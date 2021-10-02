#include "CSqlClass.h"

CSqlClass *p = nullptr;

CSqlClass::CSqlClass(QObject *parent) : QObject(parent)
{
    QString sDataDir = qApp->applicationDirPath()+"/../data";

    if(!QDir(sDataDir).exists())
        QDir().mkdir(sDataDir);

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
               'AnalyzeId'	INTEGER NOT NULL, \
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
               'Fence'	TEXT, \
               'Pavement'	TEXT, \
               'Pedestrian'	TEXT, \
               'Pole'	TEXT, \
               'Road'	TEXT, \
               'RoadMarking'	TEXT, \
               'Sky'	TEXT, \
               'SignSymbol' TEXT, \
               'Tree'	TEXT, \
               'Unlabelled'	TEXT, \
               'Width' TEXT, \
               'Height' TEXT, \
               'AlgorithmTime'	TEXT, \
               'Result' INTEGER, \
               'Note' TEXT, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");


    //    "Building": "67.7",
    //    "Bicyclist": "0.6",
    //    "Car": "4.4",
    //    "Fence": "0.0",

    //    "Pavement": "1.6",
    //    "Pedestrian": "1.2",
    //    "Pole": "1.8",
    //    "Road": "0.4"
    //    "Road_Marking": "0.0",

    //    "Sky": "14.6",
    //    "SignSymbol": "2.9",
    //    "Tree:": "4.8",
    //    "Unlabelled": "0.0",

    //    "Image Width": "656",
    //    "Image Height": "438",
    //    "Algorithm Time": "19.448",
    //    "Algorithm Result": true,
    //    "PNG":"iVBORw0KGgoAAA..."




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
                  "Building=:Building , Bicyclist=:Bicyclist , Car=:Car , Sky = :Sky "
                  "Pavement=:Pavement , Fence=:Fence , Tree=:Tree , Pedestrian = :Pedestrian "
                  "Pole=:Pole , Road=:Road , RoadMarking=:RoadMarking , SignSymbol = :SignSymbol "
                  "Unlabelled =:Unlabelled , AlgorithmTime =:AlgorithmTime ,  Result =:Result "
                  "WHERE Sid=?;");




}

void CSqlClass::setDecodeData(QString sId,CDecodeData cData)
{
    QSqlQuery query(m_db);

    query.prepare("UPDATE Analyze SET "
                  " Building=:Building , Bicyclist=:Bicyclist , Car=:Car , Fence = :Fence "
                  " ,Pavement=:Pavement , Pedestrian=:Pedestrian , Pole=:Pole , Road = :Road ,RoadMarking = :RoadMarking "
                  " ,Sky=:Sky , SignSymbol=:SignSymbol , Tree=:Tree , Unlabelled = :Unlabelled "
                  " ,Width =:Width , Height =:Height ,AlgorithmTime=:AlgorithmTime,  Result =:Result "
                  " WHERE Sid=:Sid ;");

    qDebug()<<"Sid : "<<sId.toInt();
 qDebug()<<"Tree : "<<cData.sTree;




    query.bindValue(":Sid",sId.toInt());

    query.bindValue(":Building",cData.sBuilding);
    query.bindValue(":Bicyclist",cData.sBicyclist);
    query.bindValue(":Car",cData.sCar);
    query.bindValue(":Fence",cData.sFence);

    query.bindValue(":Pavement",cData.sPavement);
    query.bindValue(":Pedestrian",cData.sPedestrian);
    query.bindValue(":Pole",cData.sPole);
    query.bindValue(":Road",cData.sRoad);
    query.bindValue(":RoadMarking",cData.sRoadMarking);

    query.bindValue(":Sky",cData.sSky);
    query.bindValue(":SignSymbol",cData.sSignSymbol);
    query.bindValue(":Tree",cData.sTree);
    query.bindValue(":Unlabelled",cData.sUnlabelled);

    query.bindValue(":Width",QString::number(cData.iW));
    query.bindValue(":Height",QString::number(cData.iH));
    query.bindValue(":AlgorithmTime",cData.sAlgorithmTime);
    query.bindValue(":Result",cData.bResult);

    bool bOk =  query.exec();

    qDebug()<<"write decode : "<<bOk;

}

int CSqlClass::inserOriginPic(QString sUser,QString sName,QByteArray dData)
{
    QSqlQuery query(m_db);

    int iRe =0;
    query.prepare("INSERT INTO Analyze (UserSid,Name) "
                  "VALUES (?,?)");
    query.bindValue(0, sUser);
    query.bindValue(1, sName);

    query.exec();

    query.clear();

    query.exec("SELECT Sid FROM Analyze ORDER BY Sid DESC;");


    if (query.next())
    {
        iRe = query.value(0).toInt();

    }

    query.clear();

    query.prepare("INSERT INTO PicData (AnalyzeId,Name,Pic) VALUES(?,?,?);");
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

void CSqlClass::inserDecodePic(QString sId, QString sName, QByteArray dData)
{
    QSqlQuery query(m_db);


    query.prepare("UPDATE PicData SET "
                  " DecodePic=:DecodePic "
                  " WHERE AnalyzeId=:AnalyzeId");
    query.bindValue(":DecodePic",dData);
    query.bindValue(":AnalyzeId",sId);
    query.exec();

    if(!QDir("../data/output").exists())
        QDir().mkdir("../data/output");

    QString sDir = "../data/output/"+sId;
    QDir().mkdir(sDir);

    QFile file(sDir+"/"+sName.split(".").first()+".png");

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(QByteArray::fromBase64(dData));

        file.flush();

        file.close();
    }

}

QVariantList CSqlClass::getHistoryData()
{
    QVariantList listRe;

    QSqlQuery query(m_db);

    query.exec("SELECT * FROM ANALYZE;");

    while(query.next())
    {
        QVariantMap map;

        CDecodeData cData ;

        cData.sId = query.value("Sid").toString() ;

        cData.sBuilding = query.value("Building").toString() ;
        cData.sBicyclist = query.value("Bicyclist").toString() ;
        cData.sCar = query.value("Car").toString() ;
        cData.sFence = query.value("Fence").toString() ;

        cData.sPavement = query.value("Pavement").toString() ;
        cData.sPedestrian = query.value("Pedestrian").toString() ;
        cData.sPole = query.value("Pole").toString() ;
        cData.sRoad = query.value("Road").toString() ;
        cData.sRoadMarking = query.value("RoadMarking").toString() ;

        cData.sSky = query.value("Sky").toString() ;
        cData.sSignSymbol = query.value("SignSymbol").toString() ;
        cData.sTree = query.value("Tree").toString() ;
        cData.sUnlabelled = query.value("Unlabelled").toString() ;

        cData.iW = query.value("Width").toInt() ;
        cData.iH = query.value("Height").toInt() ;
        cData.sAlgorithmTime = query.value("AlgorithmTime").toString() ;
        cData.bResult = query.value("Result").toBool() ;


        listRe.append(map);
    }

    return listRe;

}
