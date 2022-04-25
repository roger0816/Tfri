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

    if(getUserData("root").length()<1)
    {
        qDebug()<<"add root data";

        insertUser("root","Aa111111",99);
    }

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
               'Enable' TEXT DEFAULT 1, \
               PRIMARY KEY('Sid' AUTOINCREMENT) \
               );");

    query.clear();

    query.exec("CREATE TABLE 'AnalyzeData' ( \
               'Sid'	INTEGER,  \
               'FileName'   TEXT, \
               'User'	TEXT, \
               'ClassGroup' TEXT , \
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
               'Result' INTEGER DEFAULT 0 , \
               'CreateTime' TEXT, \
               'UpdateTime' TEXT, \
               'Enable' TEXT DEFAULT 1 , \
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
               'Type'	INTEGER DEFAULT 1, \
               'ClassGroup'	TEXT, \
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
    query.prepare("INSERT INTO AnalyzeData (Sid,User,ClassGroup,Building,Bicyclist,Car,Fence,Pavement,Pedestrian,Pole,RoadMarking, "
                  " Sky,SignSymbol,Tree,Unlabelled,Width,Height,AlgorithmTime,Result,CreateTime,UpdateTime) "
                  " VALUES(:Sid,:User,:ClassGroup,:Building,:Bicyclist,:Car,:Fence,:Pavement,:Pedestrian,:Pole,:RoadMarking, "
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
    QString sGroup = cData.sClassGroup;


    if(sGroup=="")
        sGroup = "Def";
    query.bindValue(":ClassGroup",sGroup);
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

void CSqlClass::deleteAnalyzeData(QString sId)
{
    QSqlQuery query(m_db);

    query.prepare("DELETE FROM AnalyzeData WHERE Sid=?;");
    query.bindValue(0,sId);
    query.exec();
}

int CSqlClass::insertOriginPic(QString sUser,QString sGroup,QString sName,QByteArray dData)
{
    QSqlQuery query(m_db);

    int iRe =0;
    query.prepare("INSERT INTO AnalyzeData (User,ClassGroup,FileName,CreateTime) "
                  "VALUES (?,?,?,?)");

    if(sGroup=="" || sGroup.toLower() =="all")
        sGroup = "Def";

    query.bindValue(0, sUser);
    query.bindValue(1,sGroup);
    query.bindValue(2, sName);
    query.bindValue(3,QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
    query.exec();

    query.clear();

    query.exec("SELECT Sid FROM AnalyzeData ORDER BY Sid DESC;");


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

QVariantList CSqlClass::getAnalyzeData(QString sLastDate, int iCount, QString sGroup)
{
    QVariantList listRe;

    QSqlQuery query(m_db);

    QString sCmd = "SELECT * FROM AnalyzeData WHERE  %1 UpdateTime>:DateTime ORDER BY UpdateTime ASC %2";

    QString sCmdGroup = " ClassGroup = '"+sGroup+"' AND";


    if(sGroup=="" || sGroup.toLower()=="all")
        sCmdGroup ="";

    QString sCmdLimit =" LIMIT :Count";


    if(iCount ==-1)
        sCmdLimit="";

    // QString sCmd = "SELECT * FROM AnalyzeData WHERE UpdateTime>:DateTime ORDER BY UpdateTime ASC LIMIT :Count";

    //    if(iCount==-1)
    //        sCmd = "SELECT * FROM AnalyzeData WHERE UpdateTime>:DateTime ORDER BY UpdateTime ASC";

    query.prepare(sCmd.arg(sCmdGroup).arg(sCmdLimit));
    query.bindValue(":DateTime",sLastDate);
    if(iCount!=-1)
        query.bindValue(":Count",iCount);
    query.exec();

    while(query.next())
    {

        CAnalyzeData cData ;

        cData.sId = query.value("Sid").toString() ;
        cData.sName = query.value("FileName").toString() ;
        cData.sUser = query.value("User").toString() ;
        cData.sCreateTime = query.value("CreateTime").toString() ;
        cData.sUpdateTime = query.value("UpdateTime").toString() ;
        cData.sClassGroup = query.value("ClassGroup").toString() ;


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


        listRe.append(cData.toMap());
    }

    return listRe;

}

QVariantList CSqlClass::getAnalyzeData(int iIdx, int iCount, QString sGroup)
{
    QVariantList listRe;

    QSqlQuery query(m_db);


    QString sCmd = "SELECT * FROM AnalyzeData %1 ORDER BY Sid ASC LIMIT ? OFFSET ?  ";

    QString sCmdGroup =" WHERE ClassGroup = '"+sGroup+"' ";
    if(sGroup=="" || sGroup.toLower()=="all")
        sCmdGroup = " ";


    qDebug()<<"aa0 : "<<sGroup;
    query.prepare(sCmd.arg(sCmdGroup));
    query.bindValue(0,iCount);
    query.bindValue(1,iIdx);
    query.exec();

    while (query.next())
    {
        CAnalyzeData cData ;

        cData.sId = query.value("Sid").toString() ;
        cData.sName = query.value("FileName").toString() ;
        cData.sUser = query.value("User").toString() ;
        cData.sCreateTime = query.value("CreateTime").toString() ;
        cData.sUpdateTime = query.value("UpdateTime").toString() ;
        cData.sClassGroup = query.value("ClassGroup").toString() ;
        qDebug()<<"aa1 : "<<cData.sClassGroup;

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
        cData.bResult = query.value("Result").toBool();


        listRe.append(cData.toMap());
    }


    qDebug()<<"aa2 : "<<listRe.at(0).toMap()["ClassGroup"];

    return listRe;
}

int CSqlClass::getAnalyzeCount(QString sGroup)
{
    int iRe = 0;

    QSqlQuery query(m_db);

    QString sCmd ="SELECT count(*) FROM AnalyzeData %1;";

    QString sGroupCmd = "  WHERE ClassGroup ='"+sGroup+"' ";

    if(sGroup=="" || sGroup.toLower()=="all")
        sGroupCmd=" ";


    query.exec(sCmd.arg(sGroupCmd));

    if(query.next())
        iRe = query.value(0).toInt();

    return iRe;
}

QVariantMap CSqlClass::getAnalyzeFromId(QString sId)
{
    QSqlQuery query(m_db);

    query.exec("SELECT * FROM AnalyzeData WHERE Sid ='"+sId+"';");

    CAnalyzeData cData ;
    if (query.next())
    {


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
        cData.bResult = query.value("Result").toBool();

    }

    return cData.toMap();
}

QString CSqlClass::getAnalyzeLast()
{
    QString sRe="0";

    QSqlQuery query(m_db);

    query.exec("SELECT UpdateTime FROM AnalyzeData ORDER BY UpdateTime DESC LIMIT 1;");

    if(query.next())
    {
        sRe = query.value(0).toString();
    }

    return sRe;
}

void CSqlClass::setPicData(CPicData cData)
{
    QSqlQuery query(m_db);

    query.prepare("INSERT INTO PicData (Sid,AnalyzeId,User,FileName,Pic,DecodePic,CreateTime,UpdateTime) "
                  " VALUES(:Sid,:AnalyzeId,:User,:FileName,:Pic,:DecodePic,:CreateTime,:UpdateTime ) "
                  " ON CONFLICT(Sid) DO UPDATE SET "
                  " UPDATE PicData SET AnalyzeId=:AnalyzeId ,User=:User ,FileName=:FileName "
                  " ,Pic=:Pic ,DecodePic=:DecodePic ,CreateTime=:CreateTime ,UpdateTime=:UpdateTime "
                  " WHERE Sid=:Sid" );

    query.bindValue(":Sid",cData.sId);
    query.bindValue(":AnalyzeId",cData.sAnalyzeId);
    query.bindValue(":User",cData.sUser);
    query.bindValue(":FileName",cData.sFileName);
    query.bindValue(":Pic",cData.dRawData);
    query.bindValue(":DecodePic",cData.dDecodeData);
    query.bindValue(":CreateTime",cData.sCreateTime);
    query.bindValue(":UpdateTime",cData.sUpdateTime);

    query.exec();



}

QVariantList CSqlClass::getPicData(QString sLastDate)
{
    QVariantList listRe;

    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM PicData WHERE UpdateTime>:DateTime ORDER BY UpdateTime ASC LIMIT 3;");
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

QList<QVariantMap> CSqlClass::getUserData(QString sUser)
{
    QList<QVariantMap> list;
    QVariantMap map;

    QSqlQuery query(m_db);

    if(sUser=="")
    {
        query.exec("SELECT * FROM User;");
    }

    else
    {
        query.prepare("SELECT * FROM User Where Name = ?;");

        query.bindValue(0,sUser);

        query.exec();
    }

    while(query.next())
    {

        map["Sid"] = query.value(0).toString();

        map["Name"] = query.value(1).toString();

        map["Password"] = query.value(2).toString();

        map["Type"] = query.value(3).toString();

        map["ClassGroup"] = query.value(4).toString().split(";;");

        map["Note"] = query.value(5).toString();

        map["CreateTime"] = query.value(6).toString();

        map["UpdateTime"] = query.value(7).toString();

        qDebug()<<"appand : "<<map;

        list.append(map);
    }

    return list;
}

void CSqlClass::insertUser(QString sUser, QString sPw, int iType)
{
    QSqlQuery query(m_db);

    query.prepare("INSERT INTO User (Name,Password,Type,ClassGroup,CreateTime,UpdateTime) "
                  "VALUES (?,?,?,?,?,?)");
    query.bindValue(0, sUser);
    query.bindValue(1, sPw);
    query.bindValue(2, iType);
    query.bindValue(3, "Def");
    query.bindValue(4,QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
    query.bindValue(5,QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));

    query.exec();
}

void CSqlClass::changePassword(QString sUser, QString sNewPw)
{

    QSqlQuery query(m_db);

    query.prepare("UPDATE  User SET Password =? Where Name = ?;");
    query.bindValue(0, sNewPw);
    query.bindValue(1, sUser);
    query.exec();
}

void CSqlClass::changeClassGroup(QString sUser, QStringList listGroup)
{
    QSqlQuery query(m_db);

    query.prepare("UPDATE  User SET ClassGroup =? Where Name = ?;");
    query.bindValue(0, listGroup.join(";;"));
    query.bindValue(1, sUser);
    query.exec();
}

bool CSqlClass::login(QString sUser, QString sPassword, QString &sError)
{
    bool bRe =false;
    qDebug()<<"login : "<<sUser<<" , PW : "<<sPassword;

    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM User WHERE Name=? AND Password=? ;");

    query.bindValue(0,sUser);
    query.bindValue(1,sPassword);
    bool bOk = query.exec();

    qDebug()<<"last  : "<<bOk;

    sError= "登入錯誤";

    if(query.next())
    {

        bRe = true;

        //    sType = query.value(0).toString();

        qDebug()<<"has user :";
        sError = "登入成功";

    }


    return bRe;

}

bool CSqlClass::addUser(QString sUser, QString sPassword,QString &sError)
{

    bool bHasOne = false;
    QSqlQuery query(m_db);

    query.prepare("SELECT * FROM User WHERE Name=? ;");
    query.bindValue(0,sUser);
    query.exec();

    bHasOne = query.next();

    if(bHasOne)
    {
        sError ="帳號已存在";

        return false;
    }
    else
    {

        query.clear();

        QString sCmd="INSERT INTO User (Name, Password, ClassGroup,CreateTime,UpdateTime) "
                     " VALUES ('%1', '%2', 'Def','%3','%4'); ";

        sCmd = sCmd.arg(sUser).arg(sPassword).arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));

        qDebug()<<"sCmd"<<sCmd;

        query.exec(sCmd);

    }



    return true;
}

bool CSqlClass::delUser(QString sUser, QString , QString &)
{

    QSqlQuery query(m_db);

    query.prepare("DELETE  FROM User WHERE Name=? ;");
    query.bindValue(0,sUser);
    query.exec();

    return true;
}

QStringList CSqlClass::userList()
{
    QStringList listUser;


    QSqlQuery query(m_db);

    query.exec("SELECT * FROM User ;");

    while(query.next())
    {
        listUser.append(query.value(1).toString());
    }

    return listUser;
}
