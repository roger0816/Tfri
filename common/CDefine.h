#ifndef CDEFINE_H
#define CDEFINE_H

#include <QDebug>
#include <QColor>
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

    QMap<QString,QColor> mColor;

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

        mColor["Building"] =QColor::fromRgb(0,0,128);
        mColor["Bicyclist"] =QColor::fromRgb(192,128,0);
        mColor["Car"] =QColor::fromRgb(128,0,64);
        mColor["Fence"] =QColor::fromRgb(128,64,64);
        mColor["Pavement"] =QColor::fromRgb(222,40,60);
        mColor["Pedestrian"] =QColor::fromRgb(0,64,64);

        mColor["Pole"] =QColor::fromRgb(128,192,192);
        mColor["Road"] =QColor::fromRgb(128,64,128);
        mColor["Road_Marking"] =QColor::fromRgb(0,69,255);
        mColor["Sky"] =QColor::fromRgb(128,128,128);
        mColor["SignSymbol"] =QColor::fromRgb(128,128,192);
        mColor["Tree"] =QColor::fromRgb(0,128,128);
        mColor["Unlabelled"] =QColor::fromRgb(0,0,0);


    }

    QStringList  toList()
    {
        QVariantMap dData = toMap();

        QStringList list;

        for(int i=0;i<listKey.length();i++)
        {
            list.append(dData[listKey.at(i)].toString());

        }

        return list;
    }


    QVariantMap toMap()
    {
        QVariantMap dData;

        dData["Id"] = sId.toDouble();
        dData["Name"] = sName;
        dData["User"] = sUser;

        dData["Building"] = sBuilding.toDouble();
        dData["Bicyclist"] = sBicyclist.toDouble();
        dData["Car"] = sCar.toDouble();
        dData["Fence"] = sFence.toDouble();

        dData["Pavement"] = sPavement.toDouble();
        dData["Pedestrian"] = sPedestrian.toDouble();
        dData["Pole"] = sPole.toDouble();
        dData["Road"] = sRoad.toDouble();
        dData["Road_Marking"] = sRoadMarking.toDouble();

        dData["Sky"] = sSky.toDouble();
        dData["SignSymbol"] = sSignSymbol.toDouble();
        dData["Tree"] = sTree.toDouble();
        dData["Unlabelled"] = sUnlabelled.toDouble();

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

    QVariantMap mMapping;

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
