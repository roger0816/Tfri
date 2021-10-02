#include "Launch.h"

Launch::Launch(QObject *parent) : QObject(parent)
{
    // DB.inserOriginPic("aa","BB");
    CSqlClass::INS();

    // m_ai.setFileList("testUser",QStringList()<<"../test01.jpg"<<"../test01.jpg"<<"../test01.jpg"<<"../test01.jpg");
//    CSendData data;

//    data.sAciton = ACT_SEND_DATA;

//    data.sUser ="rogerTest";

//    data.sMsg="test01.jpg";

//    QFile f("../test01.jpg");

//    if(f.open(QIODevice::ReadOnly))
//    {
//        data.dData = f.readAll().toBase64();

//        f.close();
//    }


//    m_ai.setDataList(data.sUser,QStringList()<<data.sMsg,QList<QByteArray>()<<data.dData);



    LIB.network()->runTcpServer("6000");

    connect(LIB.network(),SIGNAL(signalReadAll(QByteArray)),this,SLOT(slotReadFromClient(QByteArray)));

}

void Launch::slotReadFromClient(QByteArray originData)
{

    qDebug()<<"get action size : "<<originData.size();

    m_dCache.append(originData);

    bool bEndPack = false;

    QByteArray tmp = QString(END_DATA).toLatin1();

    bEndPack = originData.right(tmp.length())==tmp ;


    if(!bEndPack)
    {

        return ;
    }

    qDebug()<<"get pack size : "<<m_dCache.size();
    QByteArray dData = m_dCache.remove(m_dCache.length()-tmp.length(),tmp.length());

    m_dCache.clear();

    CSendData data;

    bool bDecodeOK = data.deCodeJson(dData);

    if(!bDecodeOK)
    {
        data.sMsg = "unknow";

        LIB.network()->recallClient(data.enCodeJson());

        return ;
    }


    if(data.sAciton == ACT_SEND_DATA)
    {
        qDebug()<<"action query";


//        QStringList listName =data.sMsg.split(",");



//        QList<QByteArray> listData = data.dData.split('')
        m_ai.setDataList(data.sUser,data.listName,data.listData);

    }

    if(data.sAciton == ACT_HISTORY_DATA)
    {

        data.dData["data"] = CSqlClass::INS().getHistoryData();

        LIB.network()->recallClient(data.enCodeJson());
    }

}
