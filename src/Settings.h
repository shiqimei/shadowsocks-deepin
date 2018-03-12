#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings : public QObject {
Q_OBJECT

public:
    Settings(QObject *parent = 0);

    ~Settings();

    QString configPath();

    QVariant getOption(const QString &key);

    void init();

    void setOption(const QString &key, const QVariant &value);

private:
    QSettings *settings;
    QString groupName;
};

#endif // SETTINGS_H
