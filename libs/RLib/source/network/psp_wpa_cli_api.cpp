#include "psp_wpa_cli_api.h"

psp_wpa_cli_api::psp_wpa_cli_api(QObject *parent) :
    QThread(parent)
{
    runing =false;
}

psp_wpa_cli_api::~psp_wpa_cli_api()
{

}

void psp_wpa_cli_api::list_network()
{
    result = wpa_cli_api("wpa_cli -i wlan0 list_networks");

}

void psp_wpa_cli_api::scan_wifi()
{
    QString rec = wpa_cli_api("wpa_cli -i wlan0 scan");
    //qDebug() << "scan wifi" << rec;

    system("sleep 3");

    result = wpa_cli_api("wpa_cli -i wlan0 scan_results");
}


void psp_wpa_cli_api::add_network()
{
  qDebug() << "ssid :"<< ssid;
  qDebug() << "auth :"<< auth_mode;
  qDebug() << "isHidden: " << isHidden;
  qDebug() << "psk:" << psk_key;
  qDebug() << "wep:" << wep_key;

  QString rec ;
  QString i_network= wpa_cli_api(QString("wpa_cli -i wlan0 add_network"));
  qDebug() << "add_network:" << network;
  rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 ssid \\\"%2\\\"").arg(i_network).arg(ssid));
  qDebug() << "set_ssid:" << rec;

  if(isHidden)
  {
      rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 scan_ssid 1").arg(i_network));
      qDebug() << "ssid is hidden:" << rec;
  }

  switch(auth_mode)
  {
//    case auth_open:
//        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 key_mgmt NONE").arg(i_network));
//        qDebug() << "auth_open:" << rec;
//    break;
    case auth_wep:
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 key_mgmt NONE").arg(i_network));
        qDebug() << "auth_wep key_mgmt NONE :" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 wep_key0 \\\"%2\\\"").arg(i_network).arg(wep_key));
        qDebug() << "auth_wep wep_key0" << wep_key << ":" << rec;
    break;
    case auth_wpa_personal:
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 key_mgmt WPA-PSK").arg(i_network));
        qDebug() << "auth_wpa_personal key_mgmt WPA-PSK:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 proto WPA").arg(i_network));
        qDebug() << "auth_wpa_personal proto WPA:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 pairwise TKIP CCMP").arg(i_network));
        qDebug() << "auth_wpa_personal pairwise TKIP CCMP:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 group TKIP CCMP").arg(i_network));
        qDebug() << "auth_wpa_personal group TKIP CCMP:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 psk \\\"%2\\\"").arg(i_network).arg(psk_key));
        qDebug() << "auth_wpa_personal psk " << psk_key << ":" << rec;
    break;
    case auth_wpa2_personal:
      rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 key_mgmt WPA-PSK").arg(i_network));
      qDebug() << "auth_wpa2_personal key_mgmt WPA-PSK:" << rec;
      rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 proto RSN").arg(i_network));
      qDebug() << "auth_wpa2_personal proto WPA:" << rec;
      rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 pairwise TKIP CCMP").arg(i_network));
      qDebug() << "auth_wpa2_personal pairwise TKIP CCMP:" << rec;
      rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 group TKIP CCMP").arg(i_network));
      qDebug() << "auth_wpa2_personal group TKIP CCMP:" << rec;
      rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 psk \\\"%2\\\"").arg(i_network).arg(psk_key));
      qDebug() << "auth_wpa2_personal psk " << psk_key << ":" << rec;
    break;
    case auth_wpa2_enterprise:
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 key_mgmt WPA-EAP").arg(i_network));
        qDebug() << "auth_wpa2_enterprise key_mgmt WPA-PSK:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 proto WPA2").arg(i_network));
        qDebug() << "auth_wpa2_enterprise proto WPA:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 pairwise CCMP").arg(i_network));
        qDebug() << "auth_wpa2_enterprise pairwise CCMP:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 group CCMP").arg(i_network));
        qDebug() << "auth_wpa2_enterprise group CCMP:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 eap PEAP").arg(i_network));
        qDebug() << "auth_wpa2_enterprise eap PEAP:" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 identity \\\"%2\\\"").arg(i_network).arg(identity));
        qDebug() << "auth_wpa2_enterprise identity " << identity << ":" << rec;
        rec = wpa_cli_api(QString("wpa_cli -i wlan0 set_network %1 password \\\"%2\\\"").arg(i_network).arg(password));
        qDebug() << "auth_wpa2_enterprise password " << password << ":" << rec;
    break;
  }
  rec = wpa_cli_api(QString("wpa_cli -i wlan0 save_config"));
    qDebug() << "save_config " << ":" << rec;
}

void psp_wpa_cli_api::connect_network()
{
    QString rec = wpa_cli_api(QString("wpa_cli -i wlan0 enable_network %1").arg(network));
    qDebug() << "select_network" << rec;
    system("sleep 1");
    rec = wpa_cli_api(QString("wpa_cli -i wlan0 select_network %1").arg(network));
    qDebug() << "select_network" << rec;
    system("sleep 1");
    rec = wpa_cli_api(QString("wpa_cli -i wlan0 save_config"));
}

void psp_wpa_cli_api::getIp_network()
{
    if(dhcp)
    {
        system("udhcpc -n -f -q -i wlan0");
    }
    else
    {
        QString cmd;
        cmd = QString("ip addr add %1/%2 brd + dev wlan0").arg(ip).arg(mask);
        system(cmd.toStdString().c_str());
        cmd = QString("ip route add default via %1 dev wlan0 ").arg(gateway);
        system(cmd.toStdString().c_str());
        cmd = QString("ping -c 3 %1 ").arg(gateway);
        system(cmd.toStdString().c_str());
    }
}

void psp_wpa_cli_api::remove_network()
{
    QString rec = wpa_cli_api(QString("wpa_cli -i wlan0 remove_network %1").arg(network));
    qDebug() << "remove_network" << rec;
    system("sleep 1");
    rec = wpa_cli_api(QString("wpa_cli -i wlan0 save_config"));
}

void psp_wpa_cli_api::disconnect_network()
{
    QString cmd;
    QString rec = wpa_cli_api(QString("wpa_cli -i wlan0 disable_network %1").arg(network));
    qDebug() << "disable_network" << rec;
    system("sleep 1");
    cmd =QString("ip addr del %1 brd + dev wlan0").arg(ip);
    system(cmd.toStdString().c_str());
    system("udhcpc -n -f -q -i wlan0");
}

void psp_wpa_cli_api::status_network()
{
    result = wpa_cli_api("wpa_cli -i wlan0 status");
    //qDebug() << "wifi status " << result;
}

void psp_wpa_cli_api::reset_network()
{
    system("echo rmmod brcmfmac > /tmp/reset_wifi.sh");
    system("echo insmod /lib/modules/3.0.35PSP-0.0.1.051215-04858-g6b447a6-dirty/kernel/drivers/net/wireless/brcm80211/brcmfmac/brcmfmac.ko >> /tmp/reset_wifi.sh");
    system("echo sleep 1 >> /tmp/reset_wifi.sh");
    system("echo killall -9 wpa_supplicant >> /tmp/reset_wifi.sh");
    system("echo sleep 2 >> /tmp/reset_wifi.sh");
    system("echo wpa_supplicant -B -iwlan0 -c /etc/wpa_supplicant.conf -dddd -Dwext >> /tmp/reset_wifi.sh");
    system("echo sleep 5 >> /tmp/reset_wifi.sh");
    system("chmod a+x /tmp/reset_wifi.sh");
    system("/tmp/reset_wifi.sh");
}

QString psp_wpa_cli_api::wpa_cli_api(QString cmd)
{
    cmd.append(" > /tmp/ap.rc");

    //qDebug() << cmd;
    system(cmd.toStdString().c_str());

    QProcess pro;

    pro.start("cat /tmp/ap.rc");

    pro.waitForFinished(-1);

    QString rec = pro.readAll().trimmed();

    //qDebug() << rec;

    return rec;
}

void psp_wpa_cli_api::run()
{
    runing = true;
    switch(mode)
    {
    case mode_list:         list_network();         break;
    case mode_scan:         scan_wifi();            break;
    case mode_add:          add_network();          break;
    case mode_connect:      connect_network();      break;
    case mode_getIp:        getIp_network();        break;
    case mode_remove:        remove_network();       break;
    case mode_disconnect:   disconnect_network();   break;
    case mode_status:       status_network();       break;
    case mode_reset:        reset_network();        break;
    }
    runing = false;
    done();
}
