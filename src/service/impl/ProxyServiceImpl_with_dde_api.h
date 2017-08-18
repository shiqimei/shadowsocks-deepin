//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYSERVICEIMPL_WITH_DDE_API_H
#define SHADOWSOCKS_CLIENT_PROXYSERVICEIMPL_WITH_DDE_API_H

#include "service/ProxyService.h"
#include <com_deepin_daemon_network.h>

using NetworkInter = com::deepin::daemon::Network;

class ProxyServiceImpl_with_dde_api : public ProxyService {

public:
    explicit ProxyServiceImpl_with_dde_api(QObject *parent);

    void setProxyMethod(ProxyMethod proxyMethod) override;

    void setProxyEnabled(bool enabled) override;

    void editForwardProxy() override;

    void setAllowClientsFromLAN(bool b) override;

private:
    NetworkInter networkInter;

    void setProxyMethod(QString proxyMethod);
};


#endif //SHADOWSOCKS_CLIENT_PROXYSERVICEIMPL_WITH_DDE_API_H
