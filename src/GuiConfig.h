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
private:
    GuiConfig();

    ~GuiConfig();

    bool existConfig(const QJsonObject &j);

    void addConfig(QJsonObject j);
    QJsonObject guiConfig;

};

#endif // GUICONFIG_H
