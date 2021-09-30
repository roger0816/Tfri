#ifndef CSQLCLASS_H
#define CSQLCLASS_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include "Library.h"
#include <QFile>
#include <QDir>

class CSqlClass : public QObject
{
    Q_OBJECT
public:

    static CSqlClass &INS();

    void open();

    void createTable();

    void decodeData(QString sId, QVariantMap mData);

    int inserOriginPic(QString sUserId, QString sName, QByteArray dData);


    QSqlDatabase m_db;


private:
    CSqlClass(QObject *parent = nullptr);


signals:

};

#endif // CSQLCLASS_H
