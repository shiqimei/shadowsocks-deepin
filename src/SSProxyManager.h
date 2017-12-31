//
// Created by pikachu on 17-12-30.
//

#ifndef SHADOWSOCKS_CLIENT_SSPROXYMANAGER_H
#define SHADOWSOCKS_CLIENT_SSPROXYMANAGER_H

#include "stdafx.h"
#include <controller.h>
#include "interface/ProxyManager.h"
class SSProxyManager: public ProxyManager {
Q_OBJECT
public:
    SSProxyManager(QObject* parent = nullptr);

    Proxy * startProxy(ProxyConfig *config) override;

    void stopProxy() override;

private:
    QSS::Controller* controller;
    QSS::Profile profile;
};


#endif //SHADOWSOCKS_CLIENT_SSPROXYMANAGER_H
