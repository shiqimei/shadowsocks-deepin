/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#include "constant.h"
#include "Settings.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>

Settings::Settings(QObject *parent) : QObject(parent)
{
    settings = new QSettings(QDir(configPath()).filePath("config.conf"), QSettings::IniFormat);
    
    groupName = "settings";
    
}

Settings::~Settings()
{
    delete settings;
}

QString Settings::configPath()
{
    return QDir(QDir(QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).first()).filePath(qApp->organizationName())).filePath(qApp->applicationName());
}

QVariant Settings::getOption(const QString &key)
{
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

void Settings::init()
{
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

