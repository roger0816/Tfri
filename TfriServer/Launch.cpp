#include "Launch.h"

Launch::Launch(QObject *parent) : QObject(parent)
{

    CSqlClass::INS().open("segnet.sqlite");

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
    // QByteArray dData = m_dCache.remove(m_dCache.length()-tmp.length(),tmp.length());
    QByteArray dData = m_dCache;
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

    else if(data.sAciton == ACT_HISTORY_DATA)
    {

        qDebug()<<"get history "<<data.sMsg;
        data.dData["Analyze"]= CSQL.getAnalyzeData(data.sMsg);

        qDebug()<<"get pic "<<data.sMsg;
        data.dData["Pic"] = CSQL.getPicData(data.sMsg);

        data.sMsg=QString("%1,%2").arg(data.dData["Analyze"].toList().length()).arg(data.dData["Pic"].toList().length());

    }

    else if(data.sAciton == ACT_LOGIN)
    {
        qDebug()<<"Action : login";

        QString sType = "0";

        CSqlClass::INS().login(data.sUser,data.sMsg,sType);


        if(data.sUser=="root" && data.sMsg =="Aa111111")
            sType = "99";


        data.sMsg = sType;





    }
    else
    {
        qDebug()<<"unkonw action ";
    }

    QByteArray re = data.enCodeJson();
    qDebug()<<"return : "<<re;
    LIB.network()->recallClient(re);
}
