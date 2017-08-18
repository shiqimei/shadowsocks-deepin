//
// Created by pikachu on 17-8-18.
//

#include <SsValidator.h>
#include "ServerSerivceImpl_old_impl.h"
#include "EditServerDialog.h"
#include "ShareServerConfigWidget.h"
#include "common/QGui.h"
#include "common/QWidgets.h"
#include "UriHelper.h"

void ServerSerivceImpl_old_impl::editServers() {
    auto dialog = new EditServerDialog();
    dialog->exec();
    dialog->deleteLater();
}

void ServerSerivceImpl_old_impl::statiscsConfig() {

}

void ServerSerivceImpl_old_impl::shareServerConfig() {
    auto dialog = new ShareServerConfigWidget();
    dialog->exec();
    dialog->deleteLater();

}

QString ServerSerivceImpl_old_impl::scanQRCodeFromScreen() {
    QString uri;
    QList<QScreen *> screens = qApp->screens();
    for (QList<QScreen *>::iterator sc = screens.begin();
         sc != screens.end();
         ++sc) {
        QImage raw_sc = (*sc)->grabWindow(qApp->desktop()->winId()).toImage();
        QString result = URIHelper::decodeImage(raw_sc);
        if (!result.isNull()) {
            uri = result;
        }
    }
    qDebug() << "扫描到二维码" << uri;
    if (!SSValidator::validate(uri)) {
        QMessageBox::critical(
                nullptr,
                tr("未找到二维码"),
                tr("没有找到包含有效ss uri的二维码"));
        return QString();
    } else {
        Profile profile = QSS::Profile(uri.toUtf8());
        Config config;
        config.profile = profile;
        config.remarks = profile.server;
        // TODO 保存二维码信息并更新菜单栏
//        configs.append(config);
//        ConfigUtil::saveConfig(configs);
//            editServerAction->trigger();
//        onEditServerActionTriggered(true);
        return uri;
    }

}

QString ServerSerivceImpl_old_impl::importURLfromClipboard() {
    QString uri = QApplication::clipboard()->text().trimmed();
    qDebug() << "uri" << uri;
    if (!SSValidator::validate(uri)) {
        QMessageBox::critical(
                nullptr,
                tr("从剪贴板导入URL错误"),
                tr("没有找到包含有效ss uri的字符串"));
        return QString();
    } else {
        Profile profile = QSS::Profile(uri.toUtf8());
        Config config;
        config.profile = profile;
        config.remarks = profile.server;
        // TODO 保存二维码信息并更新菜单栏
        return uri;
    }
}

ServerSerivceImpl_old_impl::ServerSerivceImpl_old_impl(QObject *parent) : QObject(parent) {
}
