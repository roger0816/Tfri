#include "CCallApi.h"

CCallApi *p = nullptr;

CCallApi::CCallApi(QObject *parent) : QObject(parent)
{
    m_sServerIp="127.0.0.1";
    m_sPort ="6000";



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


    qDebug()<<"reply : "<<dData;
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

bool CCallApi::queryHistory()
{

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

    for(int i=0;i<listAnalyze.length();i++)
    {
        CAnalyzeData itemData;

        itemData.setData(listAnalyze.at(i).toMap());

        CSQL.setAnalyzeData(itemData.sId, itemData);



    }




    bool bRe =false;

    bRe = m_data.sAciton == data.sAciton;

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
