#ifndef CSQLCLASS_H
#define CSQLCLASS_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include "Library.h"
#include <QFile>
#include "CDefine.h"
#include <QDir>

class CSqlClass : public QObject
{
    Q_OBJECT
public:

    static CSqlClass &INS();

    void open();

    void createTable();

    void decodeData(QString sId, QVariantMap mData);

    void setDecodeData(QString sId,CDecodeData cData);

    int inserOriginPic(QString sUser, QString sName, QByteArray dData);

    void inserDecodePic(QString sId,QString sName, QByteArray dData);

    QVariantList getHistoryData();


    QSqlDatabase m_db;


private:
    CSqlClass(QObject *parent = nullptr);


signals:

};

#endif // CSQLCLASS_H
