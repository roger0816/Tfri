#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include "CQueryData.h"
class Global : public QObject
{
    Q_OBJECT
public:
   Global *INS();

    QString m_sUser;

    CQueryData m_ai;

private:
    Global(QObject *parent = nullptr);
signals:

};

#endif // GLOBAL_H
