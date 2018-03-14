#include "GuiConfig.h"
#include "utils.h"

using namespace Utils;

GuiConfig *GuiConfig::instance() {
    static GuiConfig config;
    return &config;
}

void GuiConfig::readFromDisk() {
    readFromDisk(QDir(configPath()).filePath("gui-config.json"), true);
}

void GuiConfig::readFromDisk(QString path, bool isFirst) {
    QFile file(path);
    QFileInfo fileinfo(file);
    QDir dir = fileinfo.absoluteDir();
    if (!dir.exists()) {
        dir.mkpath(dir.absolutePath());
    }

    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(nullptr, "", tr("%1 open fail").arg(path));
            return;
        } else {
            QJsonDocument d;
            QJsonObject o;
            o.insert("configs", QJsonArray());
            d.setObject(o);
            file.write(d.toJson());
            file.flush();
            file.close();
        }
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument d = QJsonDocument::fromJson(file.readAll());
    qDebug() << d.toJson();
    file.close();
    auto json = d.object();
    if (isFirst) {
        guiConfig = json;
        guiConfig.insert("configs", QJsonArray());
    }
    auto array = json.value("configs").toArray();
    for (const auto &it:array) {
        auto c = it.toObject();
        if (!existConfig(it.toObject())) {
            addConfig(it.toObject());
        }
    }
    qDebug()<<"that's ok";
    saveToDisk();
}

void GuiConfig::saveToDisk() {
    saveToDisk(QDir(configPath()).filePath("gui-config.json"));
}

void GuiConfig::saveToDisk(QString path) {
    QFile file(path);
    QFileInfo fileinfo(file);
    QDir dir = fileinfo.absoluteDir();
    if (!dir.exists()) {
        dir.mkpath(dir.absolutePath());
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "", tr("%1 open fail").arg(path));
        qDebug() << tr("%1 open fail").arg(path);
        return;
    } else {
        QJsonDocument d;
        d.setObject(guiConfig);
        file.write(d.toJson());
        qDebug() << d.toJson();
        file.flush();
        file.close();
    }

}

QJsonObject GuiConfig::getConfigById(QString id) {
    const auto &array = guiConfig["configs"].toArray();
    guiConfig.insert("configs", QJsonArray());
    for (auto it:array) {
        if (it.toObject()["id"] == id) {
            return it.toObject();
        }
    }
    return QJsonObject();
}

QJsonArray GuiConfig::getConfigs() {
    return guiConfig["configs"].toArray();
}

void GuiConfig::setConfigs(QJsonArray array) {
    guiConfig.insert("configs", array);
}

QJsonValue GuiConfig::get(QString key) {
    return guiConfig.value(key);
}

void GuiConfig::set(QString key, QJsonValue value) {
    guiConfig.insert(key, value);
}

QString GuiConfig::getCurrentId() {
    auto index = guiConfig.value("index").toInt();
    auto array = guiConfig.value("configs").toArray();
    if (index < array.size()) {
        return array.at(index).toObject().value("id").toString();
    }
    return QString();
}

void GuiConfig::setCurrentTermUsage(int n) {
    auto index = guiConfig.value("index").toInt();
    auto array = guiConfig.value("configs").toArray();
    auto o = array.at(index).toObject();
    o.insert("term_usage", n);
    array.replace(index, o);
    setConfigs(array);
}

void GuiConfig::addTotalUsage(int n) {
    auto index = guiConfig.value("index").toInt();
    auto array = guiConfig.value("configs").toArray();
    auto o = array.at(index).toObject();
    auto m = o.value("total_usage").toInt();
    o.insert("total_usage", m + n);
    array.replace(index, o);
    setConfigs(array);
}

void GuiConfig::updateLastUsed() {
    auto index = guiConfig.value("index").toInt();
    auto array = guiConfig.value("configs").toArray();
    auto o = array.at(index).toObject();
    o.insert("last_used", QDateTime::currentDateTime().toString());
    array.replace(index, o);
    setConfigs(array);
}

GuiConfig::GuiConfig() {
    guiConfig.insert("strategy", "");
    guiConfig.insert("index", 3);
    guiConfig.insert("global", false);
    guiConfig.insert("localPort", 1080);
    guiConfig.insert("enabled", true);
    guiConfig.insert("shareOverLan", false);
    guiConfig.insert("pacUrl", "");
    guiConfig.insert("useOnlinePac", false);
    guiConfig.insert("secureLocalPac", true);
    guiConfig.insert("availabilityStatistics", true);
    guiConfig.insert("autoCheckUpdate", false);
    guiConfig.insert("checkPreRelease", false);
    guiConfig.insert("isVerboseLogging", true);
}

GuiConfig::~GuiConfig() {
    qDebug() << "~GuiConfig()";
    saveToDisk();
}

bool GuiConfig::existConfig(const QJsonObject &j) {
    bool flag = false;
    const auto &array = guiConfig["configs"].toArray();
    if (array.empty()) {
        flag = false;
    } else {
        const auto &id = j["id"];
        for (auto it:array) {
            if (it.toObject()["id"] == id) {
                flag = true;
            }
        }
    }
    return flag;
}

void GuiConfig::addConfig(QJsonObject j) {
    auto array = guiConfig["configs"].toArray();
    QString id = j["id"].toString();
    if (id.isEmpty()) {
        calId(j);
    }
    int local_port = j.value("local_port").toInt();
    if (local_port == 0) {
        local_port = guiConfig.value("localPort").toInt();
        if (local_port == 0) {
            local_port = 1080;
            guiConfig.insert("localPort", 1080);
        }
        j.insert("local_port", local_port);
    }
    QString local_addr = j.value("local_address").toString();
    if (local_addr.isEmpty()) {
        local_addr = "127.0.0.1";
        j.insert("local_address", local_addr);
    }
    j.insert("term_usage", 0);
    QString reset_date = j.value("rest_date").toString();
    if (reset_date.isEmpty()) {
        auto date = QDate::currentDate();
        date = date.addDays(1);
        auto s = QDate(date.year(), date.month(), 1).toString("yy/M/d");
        j.insert("reset_date", s);
    }
    QString last_used = j.value("last_used").toString();
    if (last_used.isEmpty()) {
        j.insert("last_used", "");
    }
    array.append(j);
    guiConfig.insert("configs", array);
}

void GuiConfig::calId(QJsonObject &j) {
    QString server = j["server"].toString();
    QString remarks = j["remarks"].toString();
    if (remarks.isEmpty()) {
            remarks = server;
            j.insert("remarks", remarks);
        }
    QString password = j["password"].toString();
    auto timestamp = getTimestamp();
    QString updateTime = j["update_time"].toString();
    if (updateTime.isEmpty()) {
            updateTime = QString::number(timestamp);
            j.insert("update_time", updateTime);
        }
    QString createTime = j["create_time"].toString();
    if (createTime.isEmpty()) {
            createTime = QString::number(timestamp);
            j.insert("create_time", createTime);
        }
    QString s = QString("%1%2%3%4").arg(server).arg(password).arg(updateTime).arg(createTime);
    QByteArray id = QCryptographicHash::hash(s.toLatin1(), QCryptographicHash::Sha256).toHex();
    j.insert("id", QString(id));
}

QJsonObject GuiConfig::getConfigFromURI(QString )
{
    return createConfig();
}

int GuiConfig::getIndexById(QString id) {

    auto array = guiConfig["configs"].toArray();
    for (int i = 0; i < array.size(); i++) {
        QString t_id = array.at(i).toObject().value("id").toString();
        if (t_id == id) {
            return i;
        }
    }
    return -1;
}

QJsonObject GuiConfig::createConfig() {
    QJsonObject o;
    calId(o);
    return o;
}
