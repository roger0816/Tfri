#include "Ipc.h"

#include "CLocalClient.h"
#include "CLocalServer.h"

CLocalServer *g_server=0;

CLocalClient *g_client=0;

Ipc::Ipc(QObject *parent) : QObject(parent)
{
    g_client=new CLocalClient(this);
    g_client->connect(g_client,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));

    g_server=new CLocalServer(this);
    g_server->connect(g_server,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));
    g_server->connect(g_server,SIGNAL(signalReadAll(QByteArray)),this,SIGNAL(signalReadAll(QByteArray)));
}

Ipc::~Ipc()
{

}

void Ipc::runServer(QString sName)
{
    g_server->startServer(sName);
}

void Ipc::recallClient(QByteArray arrReturn)
{
    g_server->slotRetrun(arrReturn);
}

int Ipc::connectHost(QString sServerName, QByteArray arrInput, QByteArray &arrOutput, int iWaitTimer)
{
    return g_client->connectHost(sServerName,arrInput,arrOutput,iWaitTimer);
}



