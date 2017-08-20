//
// Created by pikachu on 17-8-18.
//

#include <util/Util.h>
#include "BootServiceImpl_with_dde_api.h"

bool BootServiceImpl_with_dde_api::isAutoBoot() {
    return startManagerInter.IsAutostart(Util::DESKTOP_URL);
}

void BootServiceImpl_with_dde_api::setAutoBoot(bool isAutoBoot) {
    if (!isAutoBoot) {
        QDBusPendingReply<bool> reply = startManagerInter.RemoveAutostart(Util::DESKTOP_URL);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "remove from startup:" << ret;
            if (ret) {
//                emit signalManager->hideAutoStartLabel(appKey);
                Util::showNotification(tr("remove from starup success"));
            }
        } else {
            qCritical() << reply.error().name() << reply.error().message();
        }
    } else {
        QDBusPendingReply<bool> reply = startManagerInter.AddAutostart(Util::DESKTOP_URL);
        reply.waitForFinished();
        if (!reply.isError()) {
            bool ret = reply.argumentAt(0).toBool();
            qDebug() << "add to startup:" << ret;
            if (ret) {
//                emit signalManager->showAutoStartLabel(appKey);
                Util::showNotification(tr("add to startup success"));
            }
        } else {
            qCritical() << reply.error().name() << reply.error().message();
        }
    }

}

BootServiceImpl_with_dde_api::BootServiceImpl_with_dde_api(QObject *parent) : BootService(parent) {}
