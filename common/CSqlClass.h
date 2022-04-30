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
    int insertOriginPic(QString sUser, QString sGroup, QString sName, QByteArray dData);
       // ai analyze  , return decode
    void insertDecodePic(QString sId,QString sName, QByteArray dData);
    //----------------
    // just set/get db
    void setAnalyzeData(QString sId, CAnalyzeData cData);
    void deleteAnalyzeData(QString sId);
    QVariantList getAnalyzeData(QString sUser,QString sLastDate, int iCount=3,QString sGroup ="");

    QVariantList getAnalyzeData(QString sUser,int iIdx, int iCount=3,QString sGroup ="");

    int getAnalyzeCount(QString sUser ,QString sGroup="");

    QVariantMap getAnalyzeFromId(QString sId);

    QString getAnalyzeLast();

    void setPicData(CPicData cData);

    QVariantList getPicData(QString sLastDate);

    QString getPicDataLast();

    QList<QVariantMap> getUserData(QString sUser="");

    void insertUser(QString sUser,QString sPw,int iType);

    void changePassword(QString sUser,QString sNewPw);

    void changeClassGroup(QString sUser,QStringList listGroup);
    //--------

    bool login(QString sUser, QString sPassword, QString &sError);

    bool addUser(QString sUser, QString sPassword, QString &sError);

    bool delUser(QString sUser, QString, QString &sError);

    QStringList userList();

    QSqlDatabase m_db;


private:
    CSqlClass(QObject *parent = nullptr);


signals:

};

#endif // CSQLCLASS_H
