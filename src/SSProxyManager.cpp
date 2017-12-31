//
// Created by pikachu on 17-12-30.
//

#include <interface/Proxy.h>
#include "SSProxyManager.h"
#include "SSProxy.h"

Proxy * SSProxyManager::startProxy(ProxyConfig *config) {
    profile.setLocalAddress(config->property("local_address").toString().toStdString());
    profile.setLocalPort(config->property("local_port").toInt());
    profile.setMethod(config->property("method").toString().toStdString());
    profile.setPassword(config->property("password").toString().toStdString());
    profile.setServerAddress(config->property("server").toString().toStdString());
    profile.setServerPort(config->property("server_port").toInt());
    profile.setTimeout(config->property("timeout").toInt());
    controller = new QSS::Controller(profile,true, true);
    controller->start();
    Proxy* proxy = new SSProxy(controller);
    return proxy;
}

void SSProxyManager::stopProxy() {
    if(controller!= nullptr){
        controller->stop();
    }
}

SSProxyManager::SSProxyManager(QObject* parent)
:ProxyManager(parent){}
