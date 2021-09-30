#include "CQueryData.h"

CQueryData::CQueryData(QObject *parent) : QObject(parent)
{
    qDebug()<< LIB.LibTest();

    connect(&m_network,&QNetworkAccessManager::finished,this,&CQueryData::slotFinish);


}

void CQueryData::setFileList(QStringList listFile)
{
    m_listWaitQuery.append(listFile);
}

void CQueryData::query()
{
    qDebug()<<"do query";
    QString sImagePath;

    if(m_listWaitQuery.length()<=0)

    {

        QEventLoop loop;

        QTimer::singleShot(10*1000,&loop,SLOT(quit()));

        loop.exec();

        query();

        return ;
    }
    sImagePath = m_listWaitQuery.first();

    //test
    QByteArray imageData("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"
                         "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");


    QFileInfo info(sImagePath);

    if(!info.exists())
    {
        m_listWaitQuery.pop_front();
        query();
        return ;
    }
    QString sFileName = sImagePath.split("/").last();



    QString sUrl = QString("http://161.35.98.42/classify_image");

    QNetworkRequest request;


    request.setUrl(sUrl);


    upng_t* upng;

    unsigned int iW=0,iH=0;

      upng = upng_new_from_file("image.png");
      if (upng != NULL) {
        upng_decode(upng);
        if (upng_get_error(upng) == UPNG_EOK) {
          /* do stuff with image */
        }

        iW = upng_get_width(upng);

        iH = upng_get_height(upng);

        upng_free(upng);
      }


    QFile *file = new QFile(sImagePath);


    if(file->open(QIODevice::ReadOnly))
    {
        QByteArray dData = file->readAll();

        CSqlClass::INS().inserOriginPic("01",sFileName,dData.toBase64());

        QHttpMultiPart *multi_part = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        file->setParent(multi_part);
        QHttpPart image_part;
        image_part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpg"));
        image_part.setHeader(QNetworkRequest::ContentDispositionHeader , QVariant(QString("form-data; name=\"imagefile\";filename=\"test01.jpg\"")));
        image_part.setHeader(QNetworkRequest::ContentLengthHeader,"65178");
        //image_part.setBodyDevice(file);
        image_part.setBody(dData);
        multi_part->append(image_part);
        //  request.setHeader(QNetworkRequest::ContentLengthHeader,data.size());
        // multi_part->setBoundary("-----wvm-----");

//        QNetworkReply *reply = m_network.post(request,multi_part);

//        reply->setProperty("origin_size",QSize(iW,iH));

//        reply->setProperty("origin_imagePath",sImagePath);


//        multi_part->setParent(reply);



    }




}

void CQueryData::slotFinish(QNetworkReply *reply)
{
    //    QByteArray testData("{"Building": "67.7",
    //                         "Bicyclist": "0.6",
    //                         "Car": "4.4",
    //                         "Sky": "14.6",
    //                         "Pavement": "1.6",
    //                         "Algorithm Time": "19.742",
    //                         "Fence": "0.0",
    //                         "Tree:": "4.8",
    //                         "Pedestrian": "1.2",
    //                         "Pole": "1.8",
    //                         "Road=": "0.4",
    //                         "Algorithm Result": true,
    //                         "SignSymbol": "2.9",
    //                         "PNG": "data:image/png;base64,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
    //                         "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"}")

    QJsonParseError jerr;

    QByteArray reData = reply->readAll();

    qDebug()<<"reply : "<<reData.toStdString().c_str();

    QJsonDocument jsDoc = QJsonDocument::fromJson(reData, &jerr);

    QVariantMap data = jsDoc.toVariant().toMap();


    QString sFilePath =reply->property("origin_imagePath").toString();

    if(m_listWaitQuery.length()>0 && m_listWaitQuery.first()==sFilePath)
        m_listWaitQuery.pop_front();

    qDebug()<<"file path : "<<sFilePath;

    QSize reSize = reply->property("origin_size").toSize();

    qDebug()<<"re size : "<<reSize;

    QByteArray imgData =data["PNG"].toByteArray().split(',').last();

    //                QImage img;

    //               img.loadFromData(QByteArray::fromBase64(imgData),"PNG");

    //               img = img.scaled(reSize);

    QStringList listTmp = sFilePath.split("/").last().split(".");
    if(listTmp.length()>1)
        listTmp.pop_back();

    //               bool bSaveOk = img.save(listTmp.join(".")+"_decode.png","PNG");


    LIB.utility.writeFile(QString("../data/output/%1").arg(listTmp.join(".")+".png"),QByteArray::fromBase64(imgData));

    reply->deleteLater();


}
