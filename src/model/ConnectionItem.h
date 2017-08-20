//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_CONNECTIONITEM_H
#define SHADOWSOCKS_CLIENT_CONNECTIONITEM_H

#include <widget/ListItem.h>
#include "common/common.h"
#include "Connection.h"

class ConnectionItem : public ListItem {
Q_OBJECT

public:
    explicit ConnectionItem(Connection *_con, QObject *parent = nullptr);

    static int columnCount();

    QVariant data(int column, int role = Qt::DisplayRole) const;

    Connection *getConnection();

    void testLatency();

    bool sameAs(ListItem *item) override;

    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect) override;

    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect) override;

public slots:

    void changeTheme(QString theme);

    void initTheme();

signals:

    void message(const QString &);

    void stateChanged(bool);

    void latencyChanged();

private:
    Connection *con;

    static QString convertLatencyToString(const int latency);

    static QString convertBytesToHumanReadable(quint64 bytes);

    static const QStringList bytesUnits;

    QPixmap iconPixmap;
    QString displayName;
    QString evenLineColor;
    QString name;
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
private slots:

    void onConnectionStateChanged(bool running);

    void onConnectionPingFinished(const int latency);

    void onStartFailed();

    void drawCell(const QRect &rect, QPainter *painter, bool isSelect, QString text) const;
};


#endif //SHADOWSOCKS_CLIENT_CONNECTIONITEM_H
