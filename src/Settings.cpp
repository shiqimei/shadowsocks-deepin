#include "constant.h"
#include "Settings.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>

Settings::Settings(QObject *parent) : QObject(parent) {
    settings = new QSettings(QDir(configPath()).filePath("config.conf"), QSettings::IniFormat);

    groupName = "settings";

}

Settings::~Settings() {
    delete settings;
}

QString Settings::configPath() {
    return QDir(QDir(QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first()).filePath(
            qApp->organizationName())).filePath(qApp->applicationName());
}

QVariant Settings::getOption(const QString &key) {
    settings->beginGroup(groupName);
    QVariant result;
    if (settings->contains(key)) {
        result = settings->value(key);
    } else {
        result = QVariant();
    }
    settings->endGroup();

    return result;
}

void Settings::init() {
    if (getOption("config_tab_index").isNull()) {
        setOption("config_tab_index", 0);
    }

    if (getOption("config_columns").isNull()) {
        setOption("config_columns", "name,server,status,latency,local_port,term_usage,total_usage,last_used");
    }

    if (getOption("config_sorting_column").isNull()) {
        setOption("config_sorting_column", "name");
    }

    if (getOption("config_sorting_order").isNull()) {
        setOption("config_sorting_order", true);
    }

    if (getOption("theme_style").isNull()) {
        setOption("theme_style", "light");
    }

    if (getOption("window_width").isNull()) {
        setOption("window_width", Constant::WINDOW_MIN_WIDTH);
    }

    if (getOption("window_height").isNull()) {
        setOption("window_height", Constant::WINDOW_MIN_HEIGHT);
    }
}

void Settings::setOption(const QString &key, const QVariant &value) {
    settings->beginGroup(groupName);
    settings->setValue(key, value);
    settings->endGroup();

    settings->sync();
}

