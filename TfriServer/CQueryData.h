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

extern  "C"
{
#include "upng.h"
}
class CQueryData : public QObject
{
    Q_OBJECT
public:
    explicit CQueryData(QObject *parent = nullptr);

    void setFileList(QStringList listFile);

    void query();

    QNetworkAccessManager m_network;

private:
      QStringList m_listWaitQuery;
signals:

public slots:

    void slotFinish(QNetworkReply *reply);



};

#endif // CQUERYDATA_H
