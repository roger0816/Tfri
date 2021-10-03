#include "Global.h"

Global *pGlobal = nullptr;

Global *Global::INS()
{
    if(pGlobal==nullptr)
    {
        pGlobal = new Global(this);
    }

    return pGlobal;
}

Global::Global(QObject *parent) : QObject(parent)
{

}

