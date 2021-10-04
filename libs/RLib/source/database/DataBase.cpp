#include "DataBase.h"
#include "CSql.h"

CSql *sql=nullptr;

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    sql=new CSql(this);
    sql->connect(sql,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));
}

bool DataBase::openDb(QString sDbName, QString sUser, QString sPassword,QString sIp, QString sPort,_db_type type)
{
    QString sSqldrive="QSQLITE";

    if(type==_mysql)
        sSqldrive="QMYSQL";



    return sql->openDb(sDbName,sUser,sPassword,sIp,sPort,sSqldrive);
}

bool DataBase::openDb(QString sDbName)
{
    return openDb(sDbName,"","","","",_sql_lite);
}



void DataBase::closeDb()
{
    sql->closeDB();
}

bool DataBase::dbCmd(QString st)
{
    return sql->dbCmd(st);
}


QSqlDatabase &DataBase::getCurrentDb()
{
    return sql->m_db;
}

QList<QVariantList> DataBase::getTable(QString sTableName)
{
    QList<QVariantList> dRe;
    dRe=sql->getTable(sTableName);
    return dRe;
}

void DataBase::insertDb(QString sTableName, QMap<QString, QString> data)
{
    sql->insertDb(sTableName,data);
}

bool DataBase::updateKeyPair(QString sKey, QString sValue)
{
    return sql->updateKeyPair(sKey,sValue);
}

bool DataBase::insertKeyPair(QString sKey, QString sValue, bool isHaveKeyDoUpdate)
{
    return sql->insertKeyPair(sKey,sValue,isHaveKeyDoUpdate);
}

QString DataBase::getKeyPair(QString sKey)
{
    return sql->getKeyPair(sKey);
}
