#ifndef CDEFINE_H
#define CDEFINE_H

#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QVariantMap>
#include <QJsonDocument>
#include <QJsonObject>


#define ACT_LOGIN "3001"
#define ACT_HISTORY_DATA "4001"
#define ACT_UPDATE_DATA "4002"
#define ACT_SEND_DATA "6001"

#define END_DATA "::ENDX::"


struct CPicData
{

    CPicData()
    {
        listKey<<"Sid"<<"AnalyzeId"<<"User"<<"FileName"<<"Pic"<<"DecodePic"
                 <<"CreateTime"<<"UpdateTime";
    }

    QString sId;

    QString sAnalyzeId;

    QString sUser;

    QString sFileName;

    QByteArray dRawData;

    QByteArray dDecodeData;

    QString sCreateTime;

    QString sUpdateTime;

    QStringList listKey;

    void setData(const QVariantMap map)
    {
        sId = map["Sid"].toString();
        sAnalyzeId = map["AnalyzeId"].toString();
        sUser = map["User"].toString();
        sFileName = map["FileName"].toString();

        dRawData = map["Pic"].toByteArray();
        dDecodeData = map["DecodePic"].toByteArray();
        sCreateTime = map["CreateTime"].toString();
        sUpdateTime = map["UpdateTime"].toString();
    }

    QVariantMap toMap()
    {
        QVariantMap map;

        map["Sid"] = sId;
        map["AnalyzeId"] = sAnalyzeId  ;
        map["User"] = sUser;
        map["FileName"] =  sFileName;

        map["Pic"] = dRawData;
        map["DecodePic"] = dDecodeData;
        map["CreateTime"] = sCreateTime;
        map["UpdateTime"]= sUpdateTime;

        return map;
    }

};

struct CAnalyzeData
{
    //    Sky = [128,128,128]
    //    Building = [128,0,0]
    //    Pole = [192,192,128]
    //    Road_marking = [255,69,0]
    //    Road = [128,64,128]
    //    Pavement = [60,40,222]
    //    Tree = [128,128,0]
    //    SignSymbol = [192,128,128]
    //    Fence = [64,64,128]
    //    Car = [64,0,128]
    //    Pedestrian = [64,64,0]
    //    Bicyclist = [0,128,192]
    //    Unlabelled = [0,0,0]

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

    //    "Image_Width": "656",
    //    "Image_Height": "438",
    //    "Algorithm_Time": "19.448",
    //    "Algorithm_Result": true,
    //    "PNG":"iVBORw0KGgoAAA..."



    void setData(const QVariantMap dData)
    {

        sId = dData["Id"].toString();
        sName = dData["Name"].toString();
        sUser = dData["User"].toString();

        sBuilding = dData["Building"].toString();
        sBicyclist = dData["Bicyclist"].toString();
        sCar = dData["Car"].toString();
        sFence = dData["Fence"].toString();

        sPavement = dData["Pavement"].toString();
        sPedestrian = dData["Pedestrian"].toString();
        sPole = dData["Pole"].toString();
        sRoad = dData["Road"].toString();
        sRoadMarking = dData["Road_Marking"].toString();

        sSky = dData["Sky"].toString();
        sSignSymbol = dData["SignSymbol"].toString();

        if(!dData["Tree"].isValid())
            sTree = dData["Tree:"].toString();
        else
            sTree = dData["Tree"].toString();

        sUnlabelled = dData["Unlabelled"].toString();

        iW = dData["Image_Width"].toString().toInt();
        iH = dData["Image_Height"].toString().toInt();
        sAlgorithmTime = dData["Algorithm_Time"].toString();
        bResult = dData["Algorithm_Result"].toBool();

        if(dData["CreateTime"].isValid())
            sCreateTime = dData["CreateTime"].toString();

        if(dData["UpdateTime"].isValid())
            sUpdateTime = dData["UpdateTime"].toString();



    }

    CAnalyzeData()
    {

        listKey<<"Id"<<"Name"<<"User"<<"Building"<<"Bicyclist"<<"Car"<<"Fence"
                 <<"Pavement"<<"Pedestrian"<<"Pole"<<"Road"<<"Road_Marking"
                <<"Sky"<<"SignSymbol"<<"Tree"<<"Unlabelled"
               <<"Image_Width"<<"Image_Height"<<"Algorithm_Time"<<"Algorithm_Result"
              <<"CreateTime"<<"UpdateTime";

    }

    QVariantMap toMap()
    {
        QVariantMap dData;

        dData["Id"] = sId;
        dData["Name"] = sName;
        dData["User"] = sUser;

        dData["Building"] = sBuilding;
        dData["Bicyclist"] = sBicyclist;
        dData["Car"] = sCar;
        dData["Fence"] = sFence;

        dData["Pavement"] = sPavement;
        dData["Pedestrian"] = sPedestrian;
        dData["Pole"] = sPole;
        dData["Road"] = sRoad;
        dData["Road_Marking"] = sRoadMarking;

        dData["Sky"] = sSky;
        dData["SignSymbol"] = sSignSymbol;
        dData["Tree"] = sTree;
        dData["Unlabelled"] = sUnlabelled;

        dData["Image_Width"] = iW  ;
        dData["Image_Height"] = iH ;
        dData["Algorithm_Time"] = sAlgorithmTime;
        dData["Algorithm_Result"]= bResult;


        dData["CreateTime"] = sCreateTime ;

        dData["UpdateTime"] = sUpdateTime ;



        return dData;
    };

    QString sUser;
    QString sName;
    QString sId;

    QString sBuilding;
    QString sBicyclist;
    QString sCar;
    QString sFence;

    QString sPavement;
    QString sPedestrian;
    QString sPole;
    QString sRoad;
    QString sRoadMarking;

    QString sSky;
    QString sSignSymbol;
    QString sTree;
    QString sUnlabelled;

    int iW;
    int iH;
    QString sAlgorithmTime;
    bool bResult;

    QString sCreateTime;

    QString sUpdateTime;

    QStringList listKey;

};



struct CSendData
{
    QString sAciton;

    QString sUser;

    QString sMsg;

    QVariantList listName;

    QVariantList listData;

    QVariantMap dData;

    QByteArray enCodeJson()
    {

        QVariantMap d;

        d.insert("action",sAciton);
        d.insert("user",sUser);

        d.insert("msg",sMsg);

        d.insert("data",dData);

        d.insert("listName",listName);

        d.insert("listData",listData);

        QJsonObject obj;

        obj = QJsonObject(QJsonDocument::fromJson(QJsonDocument::fromVariant(QVariant(d)).toJson()).object());

        QByteArray re = QJsonDocument(obj).toJson();

        re.append(QString(END_DATA).toLatin1());

        return   re;


    }

    bool deCodeJson(QByteArray jsonData)
    {
        QByteArray tmp = QString(END_DATA).toLatin1();

        QByteArray d =jsonData.remove(jsonData.length()-tmp.length(),tmp.length());

        QVariantMap map= QJsonDocument::fromJson(d).toVariant().toMap();


        if(!map["action"].isValid())
            return false;

        sAciton = map["action"].toString();

        sUser = map["user"].toString();

        sMsg = map["msg"].toString();

        dData = map["data"].toMap();

        listName = map["listName"].toList();

        listData = map["listData"].toList();


        return true;

    };



};


//QByteArray encode(CData data);

//CData decode(QByteArray arrData);


#endif // CDEFINE_H
