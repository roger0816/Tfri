#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>

class Global : public QObject
{
    Q_OBJECT
public:
   Global *INS();

    QString m_sUser;
private:
    Global(QObject *parent = nullptr);
signals:

};

#endif // GLOBAL_H
