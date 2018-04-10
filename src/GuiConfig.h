/**
 * Copyright (C) 2017 ~ 2018 PikachuHy
 *
 * Author:     PikachuHy <pikachuhy@163.com>
 * Maintainer: PikachuHy <pikachuhy@163.com>
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

#ifndef GUICONFIG_H
#define GUICONFIG_H

#include "stdafx.h"

class GuiConfig : public QObject {
    Q_OBJECT
public:
    static GuiConfig *instance();

    void readFromDisk();

    void readFromDisk(QString path, bool isFirst = false);

    void saveToDisk();

    void saveToDisk(QString path);

    QJsonObject getConfigById(QString id);

    int getIndexById(QString id);

    QJsonArray getConfigs();

    void setConfigs(QJsonArray array);

    QJsonValue get(QString key);

    void set(QString key, QJsonValue value);

    QString getCurrentId();

    void setCurrentTermUsage(int n);

    void addTotalUsage(int n);

    void updateLastUsed();

    static void calId(QJsonObject &j);
    static QJsonObject getConfigFromURI(QString uri);
    static QJsonObject createConfig();
    /**
     * @brief addConfig
     * 在执行这个函数前，确保uri是合法的
     * @param uri
     */
    void addConfig(QString uri);
    QString getConfigURI(int index);
private:
    GuiConfig();

    ~GuiConfig();

    bool existConfig(const QJsonObject &j);

    void addConfig(QJsonObject j);
    QJsonObject guiConfig;

};

#endif // GUICONFIG_H
