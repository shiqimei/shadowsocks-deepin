//
// Created by pikachu on 17-8-18.
//

#include "ProxyServiceImpl_with_dde_api.h"

void ProxyServiceImpl_with_dde_api::setProxyMethod(ProxyService::ProxyMethod proxyMethod) {
    QString method;
    QDBusPendingCallWatcher *w = nullptr;
    switch (proxyMethod) {
        case None:
            method = "none";
            setProxyMethod(method);
            break;
        case Manual:
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
        case Auto:
            method = "auto";
            //　TODO　如果是本地pac且文件不存在，去下载
            QString proxy = QString("file:///%1/.ss/autoproxy.pac").arg(QDir::homePath());
            w = new QDBusPendingCallWatcher(networkInter.SetAutoProxy(proxy), this);
            QObject::connect(w, &QDBusPendingCallWatcher::finished, [=]() {
                qDebug() << "set auto proxy finished" << proxy;
                setProxyMethod(method);
            });
            break;
    }
}

void ProxyServiceImpl_with_dde_api::setProxyEnabled(bool enabled) {
    if (!enabled) {
        setProxyMethod(ProxyMethod::None);
    } else {
        // TODO 判断当前的代理模式
        auto proxyMethod = ProxyMethod::Auto;
        setProxyMethod(proxyMethod);
    }

}

void ProxyServiceImpl_with_dde_api::editForwardProxy() {

}

void ProxyServiceImpl_with_dde_api::setAllowClientsFromLAN(bool b) {

}

ProxyServiceImpl_with_dde_api::ProxyServiceImpl_with_dde_api(QObject *parent)
        : QObject(parent),
          networkInter("com.deepin.daemon.Network", "/com/deepin/daemon/Network", QDBusConnection::sessionBus(), this) {
}

void ProxyServiceImpl_with_dde_api::setProxyMethod(QString proxyMethod) {
    QDBusPendingCallWatcher *w = new QDBusPendingCallWatcher(networkInter.SetProxyMethod(proxyMethod), this);
    QObject::connect(w, &QDBusPendingCallWatcher::finished, [=] {
        qDebug() << "success to set proxy method " << proxyMethod;
    });
    connect(w, &QDBusPendingCallWatcher::finished, w, &QDBusPendingCallWatcher::deleteLater);
}
