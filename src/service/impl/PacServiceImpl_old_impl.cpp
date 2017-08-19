//
// Created by pikachu on 17-8-18.
//

#include <util/Util.h>
#include "PacServiceImpl_old_impl.h"
#include "widget/EditOnlinePacUrlDialog.h"

void PacServiceImpl_old_impl::setUseLocalPac(bool isLocal) {
    Util::guiConfig.useOnlinePac = !isLocal;
}

void PacServiceImpl_old_impl::editLocalPacFile() {
    QString path = QString("%1/.ss/autoproxy.pac").arg(QDir::homePath());
    qDebug() << "path" << path;
    DDesktopServices::showFileItem(path);
}

void PacServiceImpl_old_impl::editUserRuleForGFWList() {

    QString path = QString("%1/.ss/user-rule.txt").arg(QDir::homePath());
    qDebug() << "path" << path;
    DDesktopServices::showFileItem(path);
}

void PacServiceImpl_old_impl::setSecureLocalPac(bool b) {
    Util::guiConfig.secureLocalPac = b;
}

void PacServiceImpl_old_impl::copyLocalPacURL() {
    QApplication::clipboard()->setText(QString("file://%1/.ss/autoproxy.pac").arg(QDir::homePath()));
}

void PacServiceImpl_old_impl::editOnlinePacUrl() {
    auto dialog = new EditOnlinePacUrlDialog();
    dialog->exec();
    dialog->deleteLater();
}

PacServiceImpl_old_impl::PacServiceImpl_old_impl(QObject *parent) : PacService(parent) {}

bool PacServiceImpl_old_impl::isUseLocalPac() {
    return !Util::guiConfig.useOnlinePac;
}

bool PacServiceImpl_old_impl::isUseOnlinePac() {
    return Util::guiConfig.useOnlinePac;
}

bool PacServiceImpl_old_impl::isSecureLocalPac() {
    return Util::guiConfig.secureLocalPac;
}
