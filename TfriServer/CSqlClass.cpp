#include "CSqlClass.h"

CSqlClass *p = nullptr;

CSqlClass::CSqlClass(QObject *parent) : QObject(parent)
{
    qDebug()<<"AAAAA";

    qDebug()<<"opendb : "<<LIB.database()->openDb(qApp->applicationDirPath()+"/../data/segnet.sqlite");

    m_db = LIB.database()->getCurrentDb();

    createTable();
}

CSqlClass &CSqlClass::INS()
{
    if(p==nullptr)
    {
        p = new CSqlClass();
    }

    return *p;
}

void CSqlClass::createTable()
{
    QSqlQuery query(m_db);

    query.exec("CREATE TABLE 'PicData' ( \
               'Sid'	INTEGER, \
               'PicId'	INTEGER NOT NULL, \
               'Name'   TEXT, \
               'Pic'	BLOB, \
               'DecodePic'	BLOB, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");



    query.clear();

    query.exec("CREATE TABLE 'Analyze' ( \
               'Sid'	INTEGER,  \
               'Name'   TEXT, \
               'UserSid'	INTEGER, \
               'Building'	TEXT, \
               'Bicyclist'	TEXT, \
               'Car'	TEXT, \
               'Sky'	TEXT, \
               'Pavement'	TEXT, \
               'AlgorithmTime'	TEXT, \
               'Fence'	TEXT, \
               'Tree'	TEXT, \
               'Pedestrian'	TEXT, \
               'Pole'	TEXT, \
               'Road'	TEXT, \
               'RoadMarking'	TEXT, \
               'SignSymbol' TEXT, \
               'Unlabelled'	TEXT, \
               'Note' TEXT, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");


    //    {"Building": "67.7",
    //    "Bicyclist": "0.6",
    //    "Car": "4.4",
    //    "Sky": "14.6",
    //    "Pavement": "1.6",
    //    "Algorithm Time": "14.550",
    //    "Fence": "0.0",
    //    "Tree:": "4.8",
    //    "Pedestrian": "1.2",
    //    "Pole": "1.8",
    //    "Road=": "0.4",
    //    "Algorithm Result": true,
    //    "SignSymbol": "2.9",
    //    "PNG":}


    query.clear();


    query.exec("CREATE TABLE 'User' ( \
               'Sid'	INTEGER NOT NULL, \
               'Name'	TEXT, \
               'Password'	TEXT, \
               'Type'	INTEGER NOT NULL, \
               'Note'	TEXT, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");


}

void CSqlClass::decodeData(QString sId, QVariantMap mData)
{
    QSqlQuery query(m_db);

    query.prepare("UPDATE Analyze SET "
                  "Building=? , Bicyclist=? , Car=? , Sky = ? "
                  "Pavement=? , Fence=? , Tree=? , Pedestrian = ? "
                  "Pole=? , Road=? , RoadMarking=? , SignSymbol = ? "
                  "Unlabelled =? , Algorithm Time =? , Algorithm Result =? "
                  "WHERE Sid=?;");




}

int CSqlClass::inserOriginPic(QString sUserId,QString sName,QByteArray dData)
{
    QSqlQuery query(m_db);

    int iRe =0;
    query.prepare("INSERT INTO Analyze (UserSid,Name) "
                  "VALUES (?,?)");
    query.bindValue(0, sUserId.toUInt());
    query.bindValue(1, sName);

    query.exec();

    query.clear();

    query.exec("SELECT Sid FROM Analyze ORDER BY Sid DESC;");


    if (query.next())
    {
        iRe = query.value(0).toInt();

    }

    query.clear();

    query.prepare("INSERT INTO PicData (PicId,Name,Pic) VALUES(?,?,?);");
    query.bindValue(0,iRe);
    query.bindValue(1,sName);
    query.bindValue(2,dData);
    query.exec();

    if(!QDir("../data/input").exists())
        QDir().mkdir("../data/input");

    QString sInDir = "../data/input/"+QString::number(iRe);
    QDir().mkdir(sInDir);

    QFile file(sInDir+"/"+sName);

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(QByteArray::fromBase64(dData));

        file.flush();

        file.close();
    }



    return iRe;

}
