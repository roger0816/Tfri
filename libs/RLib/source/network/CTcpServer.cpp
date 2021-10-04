#include "CTcpServer.h"



CTcpServer::CTcpServer(QObject *parent) :
    QThread(parent)
{


}

void CTcpServer::run()
{



}

void CTcpServer::startServer(QString sPort)
{

    m_clientConnection=NULL;

    m_tcpServer = new QTcpServer(this);

    m_tcpServer->listen(QHostAddress::Any, sPort.toInt());

    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotAcceptConnection()));

    emit signalLog("TCP SERVER CREAT");

}

void CTcpServer::slotAcceptConnection()
{

    emit signalLog("get client link");

    if(m_clientConnection!=NULL)
    {
        m_clientConnection->abort();

        m_clientConnection->disconnect();
    }

    m_clientConnection = m_tcpServer->nextPendingConnection();

    m_clientConnection->connect(m_clientConnection, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

}

void CTcpServer::slotReadClient()
{

   QByteArray arrRead= m_clientConnection->readAll();

    QString str =arrRead;

    emit signalLog("read client : "+str);

    emit signalReadAll(arrRead);
//    QString sReClient;

//    emit signalLog(sReClient);

//    QByteArray tmp;

//    tmp.append(sReClient);

//    QTcpSocket *pSenderSocket = qobject_cast<QTcpSocket*>(sender());

//    pSenderSocket->write(tmp);

}

void CTcpServer::slotRetrun(QByteArray arrReturn)
{

    QTcpSocket *pSenderSocket = qobject_cast<QTcpSocket*>(sender());

    pSenderSocket->write(arrReturn);

    QString sReClient=arrReturn;

    emit signalLog("return client : "+sReClient);
}




