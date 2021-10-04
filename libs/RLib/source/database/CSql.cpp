#include "CSql.h"

CSql *CSql::m_pInstance = 0;

static QString KEY_PAIR_TABLE_NAME = "Settings";

CSql::CSql(QObject *parent):QThread(parent)
{

}


bool CSql::openDb(QString sDbName,  QString sUser, QString sPassword,QString sIp, QString sPort,QString sSqldriver)
{

    m_dbType=sSqldriver;

    bool bRe=false;
    // QMYSQL  QSQLITE
    m_db = QSqlDatabase::addDatabase(sSqldriver,sDbName);

    m_db.setDatabaseName(sDbName);

    if(m_dbType == "QSQLITE")
    {

    }

    else
    {


        m_db.setPort(sPort.toInt());

        m_db.setHostName(sIp);

        m_db.setUserName(sUser);

        m_db.setPassword(sPassword);

    }
    emit signalLog("db name: "+sDbName);

    emit signalLog("db host name: "+sIp);

    emit signalLog("db port: "+sPort);

    emit signalLog("db User name: "+sUser);

    bRe=m_db.open();
    
    if(!bRe)
    {
        emit signalLog("ERROR: "+QSqlError(m_db.lastError()).text());
    }
    else
    {
        emit signalLog("sql open Ok");
    }

    if(bRe)
    {
        QSqlQuery sql(m_db);

        QString sCmd="CREATE TABLE `"+KEY_PAIR_TABLE_NAME+"` (`key`	TEXT NOT NULL,`value`	TEXT, PRIMARY KEY(`key`));";

        sql.exec(sCmd);
    }

    return bRe;
}

bool CSql::dbCmd(QString st)
{
    QSqlQuery sql(m_db);

    return sql.exec(st);
}

QList<QVariantList> CSql::getTable(QString sTableName)
{
    QList<QVariantList> dRe;

    QSqlQuery query(m_db);

    QString dbCmd="SELECT  * FROM  "+sTableName;

    query.exec(dbCmd);
    int iRow=0;
    while(query.next())
    {
        QVariantList list;
        //  qDebug()<<" row : "<<iRow<<"  ,  column count: "<<query.record().count();
        for(int i=0;i<query.record().count();i++)
        {
            list.append(query.value(i));
        }
        dRe.append(list);
        iRow++;
    }

    return dRe;
}

int CSql::insertDb(QString sTableName, QMap<QString, QString> list)
{
    int iRe=-1;
    //  insert into 資料表名稱(欄位1,欄位2,欄位3,欄位4, ...... 欄位N)
    //  values('值1','值2','值3','值4', ...... '值N');
    // INSERT INTO table1 ( id , name , pwd ) VALUES ( '9', 'Jacky', '54545' );

    QSqlQuery query(m_db);

    QString sColName;

    QString sValues;


    for(int i=0;i<list.count();i++)
    {
        if(i!=0)
        {
            sColName+=",";
            sValues+=",";
        }

        sColName+=list.keys().at(i);
        sValues+="'";
        sValues+=list.values().at(i);
        sValues+="'";

    }

    QString sCmd="INSERT INTO "+sTableName+"(" +sColName+") VALUES ("+sValues +")";

    bool bExe=query.exec(sCmd);

    if(bExe)
        iRe=0;

    return iRe;
}

bool CSql::insertKeyPair(QString sKey, QString sValue, bool bIsHasKeyDoUpdate)
{
    QSqlQuery query(m_db);

    QString sCmd;

    QString sTmp="";
    if(m_dbType == "QSQLITE")
    {
        if(bIsHasKeyDoUpdate)
            sTmp="OR REPLACE";

        sCmd = "INSERT "+ sTmp+" INTO "+KEY_PAIR_TABLE_NAME+" (key,value) VALUES ('"+sKey+"','"+sValue +"') ";
    }
    else
    {
        sCmd = "INSERT INTO "+KEY_PAIR_TABLE_NAME+" (key,value) VALUES ('"+sKey+"','"+sValue +"') ";

        if(bIsHasKeyDoUpdate)
            sTmp=" ON DUPLICATE KEY UPDATE key = '"+sKey+"', value = '"+sValue+"'";

        sCmd += sTmp;
    }

    return query.exec(sCmd);
}

bool CSql::updateKeyPair(QString sKey, QString sValue)
{
    QSqlQuery query(m_db);

    QString sCmd;

    sCmd = "UPDATE "+KEY_PAIR_TABLE_NAME+" SET value = '"+sValue+"' WHERE key = '"+sKey+"'";

    return query.exec(sCmd);

}

QString CSql::getKeyPair(QString sKey)
{
    QSqlQuery query(m_db);

    QString sCmd="SELECT value FROM "+KEY_PAIR_TABLE_NAME+" where key = '"+sKey+"';";

    query.exec(sCmd);

    QString sRe="";

    while (query.next())
    {
        sRe=query.value("value").toString();
    }

    return sRe;
}
