#ifndef CQUERYDATA_H
#define CQUERYDATA_H

#include <QObject>
#include <QDebug>
#include <QBuffer>
#include <QUrlQuery>
#include <QEventLoop>
#include <QTimer>
#include <QSize>
#include <QUrl>
#include "Library.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QHttpMultiPart>
#include <QHttpPart>
#include <QJsonDocument>
#include <QFileInfo>
#include "CSqlClass.h"
#include <QTimer>

#define QUERY_MSEC 3000

//extern  "C"
//{
//#include "upng.h"
//}





class CQueryData : public QObject
{
    Q_OBJECT
public:
    explicit CQueryData(QObject *parent = nullptr);

    void setFileList(QString sUser,QString sGroup, QStringList listFile);

//    void setDataList(QString sUser,QVariantList listFileName,QVariantList listData);

    void query();


    QNetworkAccessManager m_network;

    int  getWaitCount();

    QString getCurrentTarget();

private:
  QList<CPicData> m_listData;

  QTimer m_timer;

  QString m_sTarget;

  bool m_bBusyLock = false;

  int m_iBusyTime = 0 ;
signals:
    void updateData(QString sId);
public slots:

    void slotFinish(QNetworkReply *reply);



};

#endif // CQUERYDATA_H
