#ifndef CLOCALSERVER_H
#define CLOCALSERVER_H

#include <QLocalServer>
#include <QLocalSocket>
#include <QThread>
#include <QFile>

class CLocalServer : public QThread
{
    Q_OBJECT
public:
    explicit CLocalServer(QObject *parent = 0);
    void run();
    void startServer(QString sName);



private:
        QLocalServer *m_server;

        QLocalSocket *m_clientConnection;



signals:
        void signalLog(QString st);

        void signalReadAll(QByteArray arrRead);

private slots:
        void slotAcceptConnection();
        void slotReadClient();

public slots:
        void slotRetrun(QByteArray arrReturn);



};

#endif // WIDGET_H
