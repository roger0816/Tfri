#include "Global.h"

Global *pGlobal = nullptr;
QWidget *m_parent = nullptr;
Global &Global::INS(QWidget *parent)
{
    if(pGlobal==nullptr)
    {
        pGlobal = new Global();
    }

    if(parent!=nullptr)
    {
        m_parent = parent;
        pGlobal->setParent(m_parent);
    }
    return *pGlobal;
}

void Global::showBlockLoading(QWidget *parent)
{
    if(m_loadingLock == nullptr)
        m_loadingLock = new LayerLoadingLock();

    if(parent!=nullptr)
        m_loadingLock->setParent(parent);

    m_loadingLock->raise();

    m_loadingLock->resize(m_parent->size());

    m_loadingLock->show();
}

void Global::hideBlockLoading()
{
    if(m_loadingLock != nullptr)
        m_loadingLock->hide();
}

Global::Global(QObject *parent) : QObject(parent)
{

}

