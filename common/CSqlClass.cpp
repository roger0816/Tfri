#include "CSqlClass.h"

CSqlClass *pSQL = nullptr;

CSqlClass::CSqlClass(QObject *parent) : QObject(parent)
{



}

CSqlClass &CSqlClass::INS()
{
    if(pSQL==nullptr)
    {
        pSQL = new CSqlClass();
    }

    return *pSQL;
}

void CSqlClass::open(QString sDbPath)
{

    QString sDataDir = qApp->applicationDirPath()+"/../data";

    if(!QDir(sDataDir).exists())
        QDir().mkdir(sDataDir);

    qDebug()<<"opendb : "<<LIB.database()->openDb(qApp->applicationDirPath()+"/../data/"+sDbPath);

    m_db = LIB.database()->getCurrentDb();

      createTable();

}

void CSqlClass::createTable()
{
    QSqlQuery query(m_db);

    query.exec("CREATE TABLE 'PicData' ( \
               'Sid'	INTEGER, \
               'AnalyzeId'	INTEGER NOT NULL, \
               'User'	TEXT, \
               'FileName'   TEXT, \
               'Pic'	BLOB, \
               'DecodePic'	BLOB, \
               'CreateTime' TEXT, \
               'UpdateTime' TEXT, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");

    query.clear();

    query.exec("CREATE TABLE 'Analyze' ( \
               'Sid'	INTEGER,  \
               'FileName'   TEXT, \
               'User'	TEXT, \
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
               'CreateTime' TEXT, \
               'UpdateTime' TEXT, \
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


    query.exec("CREATE TABLE 'UserList' ( \
               'Sid'	INTEGER NOT NULL, \
               'Name'	TEXT, \
               'Password'	TEXT, \
               'Type'	INTEGER DEFAULT 1, \
               'Note'	TEXT, \
               'CreateTime' TEXT, \
               'UpdateTime' TEXT, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");


}



void CSqlClass::setAnalyzeData(QString sId,CAnalyzeData cData)
{
    QSqlQuery query(m_db);

//    INSERT INTO Analyze (Sid,Building) VALUES('1932','67.6') ON CONFLICT(Sid) DO

//    UPDATE  SET Building='68.7' WHERE Sid='1932';
      query.prepare("INSERT INTO Analyze (Sid,User,Building,Bicyclist,Car,Fence,Pavement,Pedestrian,Pole,RoadMarking, "
                    " Sky,SignSymbol,Tree,Unlabelled,Width,Height,AlgorithmTime,Result,CreateTime,UpdateTime) "
                    " VALUES(:Sid,:User,:Building,:Bicyclist,:Car,:Fence,:Pavement,:Pedestrian,:Pole,:RoadMarking, "
                    " :Sky,:SignSymbol,:Tree,:Unlabelled,:Width,:Height,:AlgorithmTime,:Result,:CreateTime,:UpdateTime) "
                    "ON CONFLICT(Sid) DO UPDATE SET "
                  " Building=:Building , Bicyclist=:Bicyclist , Car=:Car , Fence = :Fence "
                  " ,Pavement=:Pavement , Pedestrian=:Pedestrian , Pole=:Pole , Road = :Road ,RoadMarking = :RoadMarking "
                  " ,Sky=:Sky , SignSymbol=:SignSymbol , Tree=:Tree , Unlabelled = :Unlabelled "
                  " ,Width =:Width , Height =:Height ,AlgorithmTime=:AlgorithmTime,  Result =:Result ,UpdateTime=:UpdateTime "
                  " WHERE Sid=:Sid ;");

    qDebug()<<"Sid : "<<sId.toInt();
    qDebug()<<"Tree : "<<cData.sTree;




    query.bindValue(":Sid",sId.toInt());
    query.bindValue(":User",cData.sUser);
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
    query.bindValue(":CreateTime",cData.sCreateTime);

    query.bindValue(":UpdateTime",QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));

    bool bOk =  query.exec();

    qDebug()<<"write decode : "<<bOk;

}

int CSqlClass::insertOriginPic(QString sUser,QString sName,QByteArray dData)
{
    QSqlQuery query(m_db);

    int iRe =0;
    query.prepare("INSERT INTO Analyze (User,FileName,CreateTime) "
                  "VALUES (?,?,?)");
    query.bindValue(0, sUser);
    query.bindValue(1, sName);
    query.bindValue(2,QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
    query.exec();

    query.clear();

    query.exec("SELECT Sid FROM Analyze ORDER BY Sid DESC;");


    if (query.next())
    {
        iRe = query.value(0).toInt();

    }

    query.clear();

    query.prepare("INSERT INTO PicData (User,AnalyzeId,FileName,Pic,CreateTime) VALUES(?,?,?,?,?);");
     query.bindValue(0,sUser);
    query.bindValue(1,iRe);
    query.bindValue(2,sName);
    query.bindValue(3,dData);
    query.bindValue(4,QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
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

void CSqlClass::insertDecodePic(QString sId, QString sName, QByteArray dData)
{
    QSqlQuery query(m_db);


    query.prepare("UPDATE PicData SET "
                  " DecodePic=:DecodePic , UpdateTime=:UpdateTime"
                  " WHERE AnalyzeId=:AnalyzeId");
    query.bindValue(":DecodePic",dData);
    query.bindValue(":AnalyzeId",sId);
    query.bindValue(":UpdateTime",QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
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

QVariantList CSqlClass::getAnalyzeData(QString sLastDate)
{
    QVariantList listRe;

    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM ANALYZE WHERE UpdateTime>:DateTime ;");
    query.bindValue(":DateTime",sLastDate);
    query.exec();

    while(query.next())
    {

        CAnalyzeData cData ;

        cData.sId = query.value("Sid").toString() ;
        cData.sName = query.value("FileName").toString() ;
        cData.sUser = query.value("User").toString() ;
        cData.sCreateTime = query.value("CreateTime").toString() ;
        cData.sUpdateTime = query.value("UpdateTime").toString() ;


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

        qDebug()<<"append : "<<cData.sId;
        listRe.append(cData.toMap());
    }

    return listRe;

}

QString CSqlClass::getAnalyzeLast()
{
    QString sRe="0";

    QSqlQuery query(m_db);

    query.exec("SELECT UpdateTime FROM Analyze ORDER BY UpdateTime DESC LIMIT 1;");

    if(query.next())
    {
       sRe = query.value(0).toString();
    }

    return sRe;
}

QVariantList CSqlClass::getPicData(QString sLastDate)
{
    QVariantList listRe;

    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM PicData WHERE UpdateTime>:DateTime ;");
    query.bindValue(":DateTime",sLastDate);
    query.exec();
    while(query.next())
    {

        CPicData cData;

        cData.sId = query.value("Sid").toString() ;
        cData.sFileName = query.value("FileName").toString() ;
        cData.sUser = query.value("User").toString() ;
        cData.sCreateTime = query.value("CreateTime").toString() ;
        cData.sUpdateTime = query.value("UpdateTime").toString() ;

        cData.dRawData = query.value("Pic").toByteArray();
        cData.dDecodeData = query.value("DecodePic").toByteArray();

        qDebug()<<"pic data : "<<cData.sId;
        listRe.append(cData.toMap());
    }

    return listRe;
}

QString CSqlClass::getPicDataLast()
{
    QString sRe="0";

    QSqlQuery query(m_db);

    query.exec("SELECT UpdateTime FROM PicData ORDER BY UpdateTime DESC LIMIT 1;");

    if(query.next())
    {
       sRe = query.value(0).toString();
    }

    return sRe;
}

bool CSqlClass::login(QString sUser, QString sPassword, QString &sType)
{
    bool bRe =false;
    qDebug()<<"login : "<<sUser<<" , PW : "<<sPassword;

    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM UserList WHERE Name=? AND Password=? ;");

    query.bindValue(0,sUser);
    query.bindValue(1,sPassword);
    bool bOk = query.exec();

    qDebug()<<"last  : "<<bOk;
    if(query.next())
    {

        bRe = true;

        sType = query.value(0).toString();

        qDebug()<<"has user type :";


    }


    return bRe;

}
