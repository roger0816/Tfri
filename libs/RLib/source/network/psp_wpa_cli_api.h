#ifndef PSP_WPA_CLI_API_H
#define PSP_WPA_CLI_API_H

#include <QThread>
#include <QDebug>
#include <QString>
#include <QProcess>

#define mode_list       1
#define mode_scan       2
#define mode_add        3
#define mode_connect    4
#define mode_getIp      5
#define mode_remove     6
#define mode_disconnect 7
#define mode_status     8
#define mode_reset      9

//#define auth_open          1
#define auth_wep             1
#define auth_wpa_personal    2
#define auth_wpa2_personal   3
#define auth_wpa2_enterprise 4


class psp_wpa_cli_api : public QThread
{
    Q_OBJECT
public:
    explicit psp_wpa_cli_api(QObject *parent = 0);
    ~psp_wpa_cli_api();
    uint     mode;
    uint     network;
    uint     auth_mode;
    bool     dhcp;
    bool     runing;
    bool     isHidden;
    QString  ip;
    QString  mask;
    QString  gateway;
    QString  psk_key;
    QString  wep_key;
    QString  identity;
    QString  password;
    QString  ssid;
    void     list_network();
    void     scan_wifi();
    void     add_network();
    void     connect_network();
    void     getIp_network();
    void     remove_network();
    void     disconnect_network();
    void     status_network();
    void     reset_network();
    QString  wpa_cli_api(QString cmd);
    QString  result;
    void     run();
signals:
    void     done();
public slots:

};

#endif // PSP_WPA_CLI_API_H
