//
// Created by pikachu on 17-8-18.
//

#include "BootServiceImpl_with_dde_api.h"

bool BootServiceImpl_with_dde_api::isAutoBoot() {
    QString desktopUrl = "/usr/share/applications/shadowsocks-client.desktop";
    return startManagerInter.IsAutostart(desktopUrl);
}

void BootServiceImpl_with_dde_api::setAutoBoot(bool isAutoBoot) {
    QString desktopUrl = "/usr/share/applications/shadowsocks-client.desktop";
    if (isAutoBoot) {
        QDBusPendingReply<bool> reply = startManagerInter.RemoveAutostart(desktopUrl);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "remove from startup:" << ret;
            if (ret) {
//                emit signalManager->hideAutoStartLabel(appKey);
            }
        } else {
            qCritical() << reply.error().name() << reply.error().message();
        }
    } else {
        QDBusPendingReply<bool> reply = startManagerInter.AddAutostart(desktopUrl);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "add to startup:" << ret;
            if (ret) {
//                emit signalManager->showAutoStartLabel(appKey);
            }
        } else {
            qCritical() << reply.error().name() << reply.error().message();
        }
    }

}

BootServiceImpl_with_dde_api::BootServiceImpl_with_dde_api(QObject *parent) : BootService(parent) {}
