#include "Launch.h"

Launch::Launch(QObject *parent) : QObject(parent)
{
   // DB.inserOriginPic("aa","BB");
    CSqlClass::INS();

    m_ai.setFileList(QStringList()<<"../test01.jpg");

    m_ai.query();

    LIB.network()->runTcpServer("6000");

}
