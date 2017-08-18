//
// Created by pikachu on 17-8-18.
//

#include "UpdateServiceImpl_old_impl.h"

void UpdateServiceImpl_old_impl::checkUpdate() {
    updateChecker.checkUpdate();
}

void UpdateServiceImpl_old_impl::setCheckForUpdatesAtStartup(bool b) {
}

void UpdateServiceImpl_old_impl::setCheckPrereleaseVersion(bool b) {

}

void UpdateServiceImpl_old_impl::updateLocalPacFromGFWList() {

}

UpdateServiceImpl_old_impl::UpdateServiceImpl_old_impl(QObject *parent) : UpdateService(parent) {}
