//
// Created by pikachu on 17-8-18.
//

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
            QString type = "socks";
            QString addr = "127.0.0.1";
            QString port = "1080";
            // TODO 需要一个东西获取配置
            w = new QDBusPendingCallWatcher(networkInter.SetProxy(type, addr, port), this);
            QObject::connect(w, &QDBusPendingCallWatcher::finished, [=] {
                qDebug() << "set proxy" << type << addr << port;
                setProxyMethod(method);
            });
            connect(w, &QDBusPendingCallWatcher::finished, w, &QDBusPendingCallWatcher::deleteLater);
            break;

        }
        case ProxyMethod::Auto: {
            method = "auto";
            //　TODO　如果是本地pac且文件不存在，去下载
//            QString proxy = QString("file:///%1/.ss/autoproxy.pac").arg(QDir::homePath());
            QString proxy = Util::ONLINE_PAC_URL;
            w = new QDBusPendingCallWatcher(networkInter.SetAutoProxy(proxy), this);
            QObject::connect(w, &QDBusPendingCallWatcher::finished, [=]() {
                qDebug() << "set auto proxy finished" << proxy;
                setProxyMethod(method);
            });
            break;

        }
        default:
            break;
    }
}

void ProxyServiceImpl_with_dde_api::setProxyEnabled(bool enabled) {
    if (controller == nullptr) {
        controller = new Controller(true, false, this);
        emit newController(controller);
    }
    if (!enabled) {
        Util::guiConfig.enabled = false;
        setProxyMethod(ProxyMethod::None);
        controller->stop();
    } else {
        Util::guiConfig.enabled = true;
        auto proxyMethod = isPacMode() ? ProxyMethod::Auto : ProxyMethod::Manual;
        setProxyMethod(proxyMethod);
        controller->setup(Util::guiConfig.getCurrentProfile());
        controller->start();
    }
    emit requestReloadMenu();
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
