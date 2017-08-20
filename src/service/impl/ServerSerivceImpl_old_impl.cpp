//
// Created by pikachu on 17-8-18.
//

#include <util/SsValidator.h>
#include <model/Connection.h>
#include <util/Util.h>
#include "ServerSerivceImpl_old_impl.h"
#include "widget/EditServerDialog.h"
#include "widget/ShareServerConfigWidget.h"
#include "util/UriHelper.h"

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
                tr("QR Code Not Found"),
                tr("Can't find any QR code image that contains valid URI on your screen(s)."));
        return QString();
    } else {
        newCon(uri);
        return uri;
    }

}

void ServerSerivceImpl_old_impl::newCon(const QString &uri) {
    auto con = new Connection(uri);
    Util::model->appendConnection(con);
    auto dialog = new EditServerDialog();
    qDebug() << "exe";
    dialog->exec();
    emit requestReloadMenu();
    dialog->deleteLater();
}

QString ServerSerivceImpl_old_impl::importURLfromClipboard() {
    QString uri = QApplication::clipboard()->text().trimmed();
    qDebug() << "uri" << uri;
    if (!SSValidator::validate(uri)) {
        QMessageBox::critical(
                nullptr,
                tr("Import URL From Clipboard Error"),
                tr("Can't find valid URI"));
        return QString();
    } else {
        newCon(uri);
        return uri;
    }
}

ServerSerivceImpl_old_impl::ServerSerivceImpl_old_impl(QObject *parent) : ServerSerivce(parent) {
}
