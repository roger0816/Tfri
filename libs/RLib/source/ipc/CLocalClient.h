#ifndef WIDGET_H
#define WIDGET_H


#include <QDebug>
#include <QObject>
#include <QLocalSocket>

class CLocalClient : public QObject
{
    Q_OBJECT
public:
    explicit CLocalClient(QObject *parent = 0);
    QLocalSocket *m_socket;
    int connectHost(QString sServerName,QByteArray arrInput,QByteArray &arrOutput,int iWaitTimer=300);

signals:
    void signalLog(QString st);
public slots:

};

#endif // WIDGET_H
