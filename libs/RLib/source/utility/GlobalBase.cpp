#include "GlobalBase.h"



GlobalBase *GlobalBase::m_pInstance = 0;

GlobalBase::GlobalBase(QObject *parent) : QObject(parent)
{


}


GlobalBase &GlobalBase::Instance()
{
    if(m_pInstance==0)
        m_pInstance = new GlobalBase();

    return *m_pInstance;

}
