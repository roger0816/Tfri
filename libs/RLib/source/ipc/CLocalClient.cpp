#include "CLocalClient.h"



CLocalClient::CLocalClient(QObject *parent) : QObject(parent)
{
    m_socket=NULL;

}


int CLocalClient::connectHost(QString sServerName, QByteArray arrInput, QByteArray &arrOutput, int iWaitTimer)
{

    int iRe=0;

    if(m_socket!=NULL)
    {

        this->disconnect(m_socket);

        delete m_socket;

    }
    m_socket = new QLocalSocket(this);
    m_socket->connectToServer(sServerName);

    if(m_socket->waitForConnected(iWaitTimer))
    {

        emit signalLog("Connected "+sServerName+" : ");
        m_socket->write(arrInput);
        //   m_socket->bytesWritten(inBuffer);
        m_socket->waitForBytesWritten(iWaitTimer);
        emit signalLog("socket written ok");

        while (true)
        {
            if(m_socket->waitForReadyRead(iWaitTimer) == false)
            {
                break;
            }

            arrOutput.append(m_socket->readAll());
        }


        QString sTmp="Reading : "+arrOutput;


        emit signalLog(sTmp);

        m_socket->close();
    }
    else
    {
        emit signalLog("Not connected!");
        iRe= 999;
    }

    return iRe;
}









