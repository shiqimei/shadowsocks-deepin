//
// Created by pikachu on 17-8-6.
//

#include <QtCore/QFile>
#include <QtCore/QJsonDocument>
#include <QtWidgets/QMessageBox>
#include <dwidget_global.h>
#include <dutil_global.h>
#include <DDesktopServices>
#include <model/JsonObjectSerializable.h>
#include "UpdateChecker.h"
#include "util/DownloadUtil.h"
#include "util/Util.h"
#include "dao/GuiConfigDao.h"
DWIDGET_USE_NAMESPACE
DUTIL_USE_NAMESPACE

/**
 * GitHub的附件信息
 */
class Asset : public JsonObjectSerializable {
public:
    QJsonObject toJsonObject() override {
        return QJsonObject();
    }

    void fromJsonObject(QJsonObject jsonObject) override {
        preRelease = jsonObject.value("").toBool();
        name = jsonObject.value("name").toString();
        downloadUrl = jsonObject.value("browser_download_url").toString();

        QRegExp rx(R"((\d+\.\d+\.\d+))");
        rx.setMinimal(true);
        QStringList list;
        int pos = 0;

        while ((pos = rx.indexIn(name, pos)) != -1) {
            list << rx.cap(1);
            pos += rx.matchedLength();
        }
        version = list.isEmpty() ? "0.0.0" : list[0];
//        qDebug()<<name<<version;
    }

    bool isNewVersion(const QString &currentVersion, bool checkPreRelease) {
        if (preRelease && !checkPreRelease) {
            return false;
        }
        if (version.isEmpty()) {
            return false;
        }
        return Util::compareVersion(version, currentVersion) > 0;
    }

    int compareTo(const Asset &other) const {
        return Util::compareVersion(version, other.version);
    }

    bool operator<(const Asset &rhs) const {
//        qDebug()<<version<<rhs.version<<compareTo(rhs);
        return compareTo(rhs) > 0;
    }

    bool operator>(const Asset &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Asset &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Asset &rhs) const {
        return !(*this < rhs);
    }

    bool preRelease;
    QString name;
    QString version;
    QString downloadUrl;
};

void UpdateChecker::checkUpdate() {
    DownloadUtil *downloadUtil = new DownloadUtil();
    QString filename = Util::getFullpath("releases.json");
    downloadUtil->download(updateUrl, filename);
    QObject::connect(downloadUtil, &DownloadUtil::finished, [=]() {
        auto json = Util::readAllFile(filename);
        auto jsonDocument = QJsonDocument::fromJson(json);
        QList<Asset> assets;
        auto jsonArray = jsonDocument.array();
        for (const auto &it:jsonArray) {
            bool isPreRelease = it.toObject().value("prerelease").toBool();
            auto assetArray = it.toObject().value("assets").toArray();
            for (const auto &assetJson:assetArray) {
                Asset asset;
                asset.preRelease = isPreRelease;
                asset.fromJsonObject(assetJson.toObject());
                assets.append(asset);
            }
        }
        qSort(assets);
//        for(const auto&it:assets){
//            qDebug()<<it.version;
//        }
        GuiConfigDao *dao = GuiConfigDao::instance();

        Asset &latestRelease = assets.first();
        if (latestRelease.isNewVersion(version, dao->get().checkPreRelease)) {
            qDebug() << "有新版本" << latestRelease.version;
            updateSS(&latestRelease);
        } else {
            qDebug() << "没有新版本";
            QMessageBox::information(nullptr, "检查更新结果", "没有新版本\n当前版本式最新的");
        }
        downloadUtil->deleteLater();
    });
}

void UpdateChecker::updateSS(Asset* asset) {
    DownloadUtil *downloadUtil = new DownloadUtil();
    QString filename = Util::getFullpath(QObject::tr("ss_deepin_temp/%1").arg(asset->name));
    downloadUtil->download(asset->downloadUrl, filename);
    QObject::connect(downloadUtil, &DownloadUtil::finished, [=]() {
        auto ret = QMessageBox::information(nullptr, "检查更新结果", "有新版本");
        if (ret == QMessageBox::Ok) {
            DDesktopServices::showFileItem(filename);
        }
    });
}
