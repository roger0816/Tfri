#include "CCallApi.h"

CCallApi *p = nullptr;

CCallApi::CCallApi(QObject *parent) : QObject(parent)
{
    //157.245.142.72
    m_sServerIp="157.245.142.72";
    m_sPort ="6000";

#ifdef OFFLINE
    m_ai.query();
#endif

    connect(&m_ai,&CQueryData::updateData,this,&CCallApi::updateData);
}

void CCallApi::replyHistory()
{

}

void CCallApi::reply()
{

    qDebug()<<"get reply";
    QByteArray originData = m_scoket.readAll();

    m_dCache.append(originData);

    bool bEndPack = false;

    QByteArray tmp = QString(END_DATA).toLatin1();

    bEndPack = originData.right(tmp.length())==tmp ;

    if(!bEndPack)
    {
        return ;
    }

    QByteArray dData = m_dCache;


    qDebug()<<"reply : "<<dData.length();

    qDebug()<<"reply data :"<<dData.toStdString().c_str();
    m_dCache.clear();

    m_data.deCodeJson(dData);

    emit replayOk();
}

CCallApi &CCallApi::INS()
{
    if(p==nullptr)
    {
        p = new CCallApi();
    }

    return *p;
}

int CCallApi::callLogin(QString sUser, QString sPassword, QString &sErrorMsg)
{
    int iType  =  0;

    CSendData data;

    data.sUser = sUser;

    data.sMsg = sPassword;
    data.sAciton = ACT_LOGIN;

    QByteArray input= data.enCodeJson() ;

    m_scoket.write(input);
    //  LIB.network()->connectHost(m_sServerIp,m_sPort,)

    m_scoket.waitForReadyRead(5000);

    iType = m_data.sMsg.toInt();

    if(iType>0)
        m_sUser = sUser;
    else
        m_sUser ="";


    return iType;
}

bool CCallApi::addUser(QString sUser, QString sPassword)
{
    bool bRe = false;





    return bRe;
}

bool CCallApi::queryHistory()
{
   bool bRe =false;
#ifdef OFFLINE

#else

    CSendData data;

    data.sUser = m_sUser;

    data.sMsg = CSQL.getAnalyzeLast();

    data.sAciton = ACT_HISTORY_DATA;

    QByteArray input= data.enCodeJson() ;

    m_scoket.write(input);


    QEventLoop loop;

    loop.connect(this,&CCallApi::replayOk, &loop,&QEventLoop::quit);

    loop.exec();


    QVariantList listAnalyze = m_data.dData["Analyze"].toList();

    qDebug()<<"data len : "<<listAnalyze.length();



    QVariantList listPic = m_data.dData["Pic"].toList();

    for(int i=0;i<listAnalyze.length();i++)
    {
        CAnalyzeData itemData;

        itemData.setData(listAnalyze.at(i).toMap());

        CSQL.setAnalyzeData(itemData.sId, itemData);


    }


    for(int i=0;i<listPic.length();i++)
    {
        CPicData itemData;

        itemData.setData(listPic.at(i).toMap());

        CSQL.setPicData(itemData);


    }

    qDebug()<<"analyze data len : "<<listAnalyze.length();




    bRe = m_data.sAciton == data.sAciton;

    if(listAnalyze.length()>0)
        return queryHistory();

#endif

        return bRe;
}

void CCallApi::openConnect()
{
    m_scoket.connectToHost(m_sServerIp,m_sPort.toInt());

    m_scoket.waitForConnected(3000);

    connect(&m_scoket,&QTcpSocket::readyRead,this,&CCallApi::reply);

}

void CCallApi::closeConnect()
{
    m_scoket.close();
}

void CCallApi::callAnylyze(QString sUser,QString sGroup,QList<QString> listFilePath)
{
#ifdef OFFLINE


    m_ai.setFileList(sUser,sGroup,listFilePath);


#else
    CSendData data;

    data.sAciton = ACT_SEND_DATA;

    data.sUser =m_sUser;

    for(int i=0;i<listFilePath.length();i++)
    {
        QFile f(listFilePath.at(i));

        QByteArray imgData;
        if(f.open(QIODevice::ReadOnly))
        {
            imgData = f.readAll().toBase64();

            f.close();
        }



            data.listName.append(listFilePath.at(i).split("/").last());

            data.listData.append(imgData);

    }

    QByteArray input = data.enCodeJson();



    QByteArray output;

    qDebug()<<"send size : "<<input.size();

    m_scoket.write(input);

  //  LIB.network()->connectHost("127.0.0.1","6000",input,output);

#endif
}
