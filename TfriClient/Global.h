#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QWidget>
#include "CQueryData.h"
#include "LayerLoadingLock.h"

#define GLOBAL Global::INS()

class Global : public QObject
{
    Q_OBJECT
public:
    static Global &INS(QWidget *parent = nullptr);

    QString m_sUser;

    CQueryData m_ai;

    void showBlockLoading(QWidget *parent = nullptr);

    void hideBlockLoading();
    LayerLoadingLock *m_loadingLock = nullptr;
private:
    Global(QObject *parent = nullptr);


signals:

};

#endif // GLOBAL_H
