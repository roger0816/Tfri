#ifndef LAUNCH_H
#define LAUNCH_H

#include <QObject>
#include "CQueryData.h"
#include "Library.h"
#include "CSqlClass.h"

class Launch : public QObject
{
    Q_OBJECT
public:
    explicit Launch(QObject *parent = nullptr);

    CQueryData m_ai;


signals:
public slots:


};

#endif // LAUNCH_H
