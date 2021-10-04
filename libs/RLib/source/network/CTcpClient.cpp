#include "CTcpClient.h"

CTcpClient::CTcpClient(QObject *parent) : QObject(parent)
{
    m_socket=NULL;
}


int CTcpClient::connectHost(QString sIp,QString sPort,QByteArray arrInput,QByteArray &arrOutput,int iWaitTimer)
{

    int iRe=0;

    if(m_socket!=NULL)
    {

        this->disconnect(m_socket);

        delete m_socket;

    }
    m_socket = new QTcpSocket(this);
    m_socket->connectToHost(sIp,sPort.toInt());

    if(m_socket->waitForConnected(iWaitTimer))
    {

        emit signalLog("Connected "+sIp+" : "+sPort);
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



    if(arrOutput.length()-arrInput.length()<1)
        iRe=998;
    return iRe;
}
