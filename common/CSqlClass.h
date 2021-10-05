#ifndef CSQLCLASS_H
#define CSQLCLASS_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include "Library.h"
#include <QFile>
#include "CDefine.h"
#include <QDir>

#define CSQL CSqlClass::INS()

class CSqlClass : public QObject
{
    Q_OBJECT
public:

    static CSqlClass &INS();

    void open(QString sDbPath);

    void createTable();
    // ai analyze  , start decode
    int insertOriginPic(QString sUser, QString sName, QByteArray dData);
       // ai analyze  , return decode
    void insertDecodePic(QString sId,QString sName, QByteArray dData);
    //----------------
    // just set/get db
    void setAnalyzeData(QString sId, CAnalyzeData cData);

    QVariantList getAnalyzeData(QString sLastDate, int iCount=3);

    QVariantList getAnalyzeData(int iIdx, int iCount=3);

    int getAnalyzeCount();


    QString getAnalyzeLast();

    void setPicData(CPicData cData);

    QVariantList getPicData(QString sLastDate);

    QString getPicDataLast();
    //--------

    bool login(QString sUser, QString sPassword, QString &sType);


    QSqlDatabase m_db;


private:
    CSqlClass(QObject *parent = nullptr);


signals:

};

#endif // CSQLCLASS_H
