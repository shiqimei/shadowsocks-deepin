//
// Created by pikachu on 17-8-18.
//

#include <util/Util.h>
#include "UpdateServiceImpl_old_impl.h"

void UpdateServiceImpl_old_impl::checkUpdate() {
    updateChecker.checkUpdate();
}

void UpdateServiceImpl_old_impl::setCheckForUpdatesAtStartup(bool b) {
    Util::guiConfig.autoCheckUpdate = b;
}

void UpdateServiceImpl_old_impl::setCheckPrereleaseVersion(bool b) {
    Util::guiConfig.checkPreRelease = b;
}

void UpdateServiceImpl_old_impl::updateLocalPacFromGFWList() {

}

UpdateServiceImpl_old_impl::UpdateServiceImpl_old_impl(QObject *parent) : UpdateService(parent) {}

bool UpdateServiceImpl_old_impl::isCheckForUpdatesAtStartup() {
    return Util::guiConfig.autoCheckUpdate;
}

bool UpdateServiceImpl_old_impl::isCheckPrereleaseVersion() {
    return Util::guiConfig.checkPreRelease;
}
