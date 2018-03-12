#ifndef SHADOWSOCKS_CLIENT_DDEPROXYMODEMANAGER_H
#define SHADOWSOCKS_CLIENT_DDEPROXYMODEMANAGER_H

#include "stdafx.h"
#include "interface/SystemProxyModeManager.h"
#include <com_deepin_daemon_network.h>

using NetworkInter = com::deepin::daemon::Network;

class DDEProxyModeManager : public SystemProxyModeManager {
Q_OBJECT
public:
    explicit DDEProxyModeManager(QObject *parent = nullptr);

    void switchToNone() override;

    void switchToAuto(QString pacURI) override;

    void switchToManual(QString localAddress, int port) override;

private:
    NetworkInter networkInter;

    void setProxyMethod(QString proxyMethod);
};


#endif //SHADOWSOCKS_CLIENT_DDEPROXYMODEMANAGER_H
