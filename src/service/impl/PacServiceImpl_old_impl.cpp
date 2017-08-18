//
// Created by pikachu on 17-8-18.
//

#include "PacServiceImpl_old_impl.h"
#include "EditOnlinePacUrlDialog.h"

void PacServiceImpl_old_impl::setUseLocalPac(bool isLocal) {

}

void PacServiceImpl_old_impl::editLocalPacFile() {
    QString path = tr("%1/.ss/autoproxy.pac").arg(QDir::homePath());
    qDebug() << "path" << path;
    DDesktopServices::showFileItem(path);
}

void PacServiceImpl_old_impl::editUserRuleForGFWList() {

    QString path = tr("%1/.ss/user-rule.txt").arg(QDir::homePath());
    qDebug() << "path" << path;
    DDesktopServices::showFileItem(path);
}

void PacServiceImpl_old_impl::setSecureLocalPac(bool b) {

}

void PacServiceImpl_old_impl::copyLocalPacURL() {
    QApplication::clipboard()->setText(tr("file://%1/.ss/autoproxy.pac").arg(QDir::homePath()));
}

void PacServiceImpl_old_impl::editOnlinePacUrl() {
    auto dialog = new EditOnlinePacUrlDialog();
    dialog->exec();
    dialog->deleteLater();
}
