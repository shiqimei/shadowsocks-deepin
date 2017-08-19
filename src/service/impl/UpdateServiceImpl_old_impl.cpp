//
// Created by pikachu on 17-8-18.
//

#include <util/Util.h>
#include <util/GfwlistToPacUtil.h>
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
    auto *gfwlistToPacUtil = new GfwlistToPacUtil();
    connect(gfwlistToPacUtil, &GfwlistToPacUtil::finished, [=]() {
        gfwlistToPacUtil->deleteLater();
        emit finishUpdate(tr("update pac file"), tr("update pac file from gfwlist done!"));
    });
    gfwlistToPacUtil->gfwlist2pac();
}

UpdateServiceImpl_old_impl::UpdateServiceImpl_old_impl(QObject *parent) : UpdateService(parent) {}

bool UpdateServiceImpl_old_impl::isCheckForUpdatesAtStartup() {
    return Util::guiConfig.autoCheckUpdate;
}

bool UpdateServiceImpl_old_impl::isCheckPrereleaseVersion() {
    return Util::guiConfig.checkPreRelease;
}
