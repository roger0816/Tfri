#include "Library.h"




Library *Library::m_pInstance = 0;



Library::Library()
{

    m_network=new Network(this);

    m_network->connect(m_network,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));

    m_database=new DataBase(this);

    m_database->connect(m_database,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));

    m_ipc=new Ipc(this);

    m_ipc->connect(m_ipc,SIGNAL(signalLog(QString)),this,SIGNAL(signalLog(QString)));

}

QString Library::LibTest()
{
    return "Lib Test OK";
}

Network* Library::network()
{
      return m_network;
}

DataBase *Library::database()
{
    return m_database;
}

Ipc *Library::ipc()
{
    return m_ipc;
}
