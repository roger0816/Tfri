#ifndef CCALLAPI_H
#define CCALLAPI_H

#include <QObject>
#include <QDebug>
#include <CDefine.h>
#include "Library.h"
#include <QTcpSocket>
#include "CSqlClass.h"
#include "CQueryData.h"


#define OFFLINE

#define CAPI CCallApi::INS()

class CCallApi : public QObject
{
    Q_OBJECT
public:
    static CCallApi &INS();
    int callLogin(QString sUser,QString sPassword,QString &sErrorMsg);

    bool queryHistory();

    void openConnect();

    void closeConnect();

    void callAnylyze(QList<QString> listFilePath);

    QString m_sServerIp;

    QString m_sPort;

    QString m_sUser;

    CQueryData m_ai;

private:
    CCallApi(QObject *parent = nullptr);

    QTcpSocket m_scoket;

    QByteArray m_dCache;

    CSendData m_data;

void replyHistory();

signals:
    void replayOk();

    void updateData(QString sId);
public slots:
    void reply();

};

#endif // CCALLAPI_H
