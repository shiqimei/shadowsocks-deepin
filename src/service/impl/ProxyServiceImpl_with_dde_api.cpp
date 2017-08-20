//
// Created by pikachu on 17-8-18.
//

#include <util/GfwlistToPacUtil.h>
#include "ProxyServiceImpl_with_dde_api.h"
#include "util/Util.h"
void ProxyServiceImpl_with_dde_api::setProxyMethod(ProxyService::ProxyMethod proxyMethod) {
    QString method;
    QDBusPendingCallWatcher *w = nullptr;
    switch (proxyMethod) {
        case None:
            method = "none";
            setProxyMethod(method);
            break;
        case Manual: {
            method = "manual";
            auto profile = Util::guiConfig.getCurrentProfile();
            QString type = "socks";
            QString addr = profile.local_address;
            QString port = QString::number(profile.local_port);
            w = new QDBusPendingCallWatcher(networkInter.SetProxy(type, addr, port), this);
            QObject::connect(w, &QDBusPendingCallWatcher::finished, [=] {
                qDebug() << "set proxy" << type << addr << port;
                setProxyMethod(method);
            });
            connect(w, &QDBusPendingCallWatcher::finished, w, &QDBusPendingCallWatcher::deleteLater);
            Util::guiConfig.global = true;
            Util::saveConfig();
            break;

        }
        case ProxyMethod::Auto: {
            method = "auto";
            Util::guiConfig.global = false;
            Util::saveConfig();
            if (Util::guiConfig.useOnlinePac) {
                setAutoProxy(Util::ONLINE_PAC_URL);
                break;
            }
            if (Util::hasPacFile()) {
                setAutoProxy(Util::LOCAL_PAC_URL);
                break;
            }
            GfwlistToPacUtil *gfwlistToPacUtil = new GfwlistToPacUtil();
            connect(gfwlistToPacUtil, &GfwlistToPacUtil::finished, [=] {
                gfwlistToPacUtil->deleteLater();
                setAutoProxy(Util::LOCAL_PAC_URL);
            });
            break;

        }
        default:
            break;
    }
}

void ProxyServiceImpl_with_dde_api::setProxyEnabled(bool enabled) {
    auto con = Util::getCurrentConnection();
    if (!enabled) {
        Util::guiConfig.enabled = false;
        setProxyMethod(ProxyMethod::None);
//        controller->stop();
        connection->stop();
    } else {
        if (connection != nullptr) {
            connection->stop();
        }
        connection = con;
//        connect(connection, &Connection::latencyAvailable, this, &ProxyServiceImpl_with_dde_api::onConnectSuccess);
//        connect(connection, &Connection::startFailed, this, &ProxyServiceImpl_with_dde_api::onConnectFailed);
//        controller->setup(Util::guiConfig.getCurrentProfile());
//        controller->start();
        connection->start();
        Util::guiConfig.enabled = true;
        auto proxyMethod = this->isPacMode() ? Auto : Manual;
        setProxyMethod(proxyMethod);
    }
    Util::saveConfig();
    emit requestReloadMenu();
    if (!list.contains(connection)) {
        list.append(connection);
        emit newController(connection->getController());
    }
}

void ProxyServiceImpl_with_dde_api::onConnectFailed() {
    Util::guiConfig.enabled = false;
    disconnect(Util::getCurrentConnection(), &Connection::startFailed, this,
               &ProxyServiceImpl_with_dde_api::onConnectFailed);
    qDebug() << "connect fail";
}

void ProxyServiceImpl_with_dde_api::onConnectSuccess(const int latency) {
    qDebug() << "latency" << latency;
    Util::guiConfig.enabled = true;
    auto proxyMethod = this->isPacMode() ? Auto : Manual;
    setProxyMethod(proxyMethod);
    disconnect(Util::getCurrentConnection(), &Connection::latencyAvailable, this,
               &ProxyServiceImpl_with_dde_api::onConnectSuccess);
}

void ProxyServiceImpl_with_dde_api::editForwardProxy() {

}

void ProxyServiceImpl_with_dde_api::setAllowClientsFromLAN(bool b) {

}

ProxyServiceImpl_with_dde_api::ProxyServiceImpl_with_dde_api(QObject *parent)
        : ProxyService(parent),
          networkInter("com.deepin.daemon.Network", "/com/deepin/daemon/Network", QDBusConnection::sessionBus(), this) {
}

void ProxyServiceImpl_with_dde_api::setProxyMethod(QString proxyMethod) {
    QDBusPendingCallWatcher *w = new QDBusPendingCallWatcher(networkInter.SetProxyMethod(proxyMethod), this);
    QObject::connect(w, &QDBusPendingCallWatcher::finished, [=] {
        qDebug() << "success to set proxy method " << proxyMethod;
    });
    connect(w, &QDBusPendingCallWatcher::finished, w, &QDBusPendingCallWatcher::deleteLater);
}

bool ProxyServiceImpl_with_dde_api::isProxyEnaled() {
    return Util::guiConfig.enabled;
}

bool ProxyServiceImpl_with_dde_api::isPacMode() {
    return !Util::guiConfig.global;
}

bool ProxyServiceImpl_with_dde_api::isGlobelMode() {
    return Util::guiConfig.global;
}

bool ProxyServiceImpl_with_dde_api::isAllowClientsFromLAN() {
    return Util::guiConfig.shareOverLan;
}

void ProxyServiceImpl_with_dde_api::setAutoProxy(const QString &proxy) {
    auto w = new QDBusPendingCallWatcher(networkInter.SetAutoProxy(proxy), this);
    QObject::connect(w, &QDBusPendingCallWatcher::finished, [=]() {
        qDebug() << "set auto proxy finished" << proxy;
        setProxyMethod("auto");
    });

}

ProxyServiceImpl_with_dde_api::~ProxyServiceImpl_with_dde_api() {
    setProxyMethod(ProxyMethod::None);
}
