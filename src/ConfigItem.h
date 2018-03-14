#ifndef CONFIGITEM_H
#define CONFIGITEM_H

#include "stdafx.h"

DWIDGET_USE_NAMESPACE

class ConfigItem : public DSimpleListItem {
Q_OBJECT
public:
    ConfigItem(QJsonObject o);

    bool sameAs(DSimpleListItem *item);
    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect, bool isHover);
    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect, bool isHover);

    static bool search(const DSimpleListItem *item, QString searchContent);

    static bool sortByName(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort);

    static bool sortByServer(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort);

    static bool sortByTotalUsager(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort);

    QString getId();

    QString getName() const;

    QString getServer() const;

    QString getStatus();

    QString getLatency();

    QString getLocalPort();

    QString getTermUsage();

    QString getTotalUsage() const;

    QString getResetDate();

    QString getLastUsed();

public slots:

    void changeTheme(QString theme);

    void initTheme();

private:
    QJsonObject config;
    QString name;
    QString server;
    QString status;
    QString latency;
    QString local_port;
    QString term_usage;
    QString total_usage;
    QString last_used;
    QStringList texts;
    // copy from deepin-system-moniter
    QPixmap iconPixmap;
    QString displayName;
    QString evenLineColor;
    QString oddLineColor;
    QString path;
    QString selectLineColor;
    QString textColor;
    QString user;
    bool displayNameComplete;
    char state;
    double cpu;
    double evenLineOpacity;
    double oddLineOpacity;
    double selectOpacity;
    double textLeftOpacity;
    double textRightOpacity;
    int iconSize;
    int padding;
    int pid;
    int textPadding;
    long memory;

    void drawCell(bool isSelect, QRect rect, QPainter *painter, QString text);
};

#endif // CONFIGITEM_H
