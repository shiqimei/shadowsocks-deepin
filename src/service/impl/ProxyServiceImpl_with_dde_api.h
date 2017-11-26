//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_PROXYSERVICEIMPL_WITH_DDE_API_H
#define SHADOWSOCKS_CLIENT_PROXYSERVICEIMPL_WITH_DDE_API_H

#include "service/ProxyService.h"
#include <com_deepin_daemon_network.h>
#include <model/Connection.h>

using NetworkInter = com::deepin::daemon::Network;

class ProxyServiceImpl_with_dde_api : public ProxyService {

public:
    explicit ProxyServiceImpl_with_dde_api(QObject *parent);

    virtual ~ProxyServiceImpl_with_dde_api();

    void setProxyMethod(ProxyMethod proxyMethod) override;

    bool isGlobelMode() override;

    bool isPacMode() override;

    void setProxyEnabled(bool enabled) override;

    bool isProxyEnaled() override;

    void editForwardProxy() override;

    void setAllowClientsFromLAN(bool b) override;

    bool isAllowClientsFromLAN() override;

    Controller *getController() const;

private:
    NetworkInter networkInter;
    Controller *controller = nullptr;
    Connection *connection = nullptr;
    QList<Connection *> list;

    void setProxyMethod(QString proxyMethod);


    void setAutoProxy(const QString &proxy);

    void onConnectSuccess(const int latency);

    void onConnectFailed();
};


#endif //SHADOWSOCKS_CLIENT_PROXYSERVICEIMPL_WITH_DDE_API_H
