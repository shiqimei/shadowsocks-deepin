//
// Created by pikachu on 17-8-5.
//

#ifndef SHADOWSOCKS_CLIENT_UTIL_H
#define SHADOWSOCKS_CLIENT_UTIL_H


#include <QtGui/QImage>
#include <model/ConnectionTableModel.h>
#include <dao/GuiConfigDao.h>
#include "model/GuiConfig.h"
#include "ConfigHelper.h"

class Util {
public:

    enum Type {
        Pac    = 0x00000000,
        Global  = 0x00000001,
        In  = 0x00000002,
        Out = 0x00000004,
        None = 0x00000008
    };

    static QImage *mix(QStringList list);
    static QImage gray(QImage image);

    static QImage *noProxyIconImage();

    static QImage *const proxyIconImage(int type);

    static QIcon getIcon(int type);
    static QByteArray readAllFile(QString filename);

    /**
     * 比较两个版本的大小
     * @param l
     * @param r
     * @return
     */
    static int compareVersion(QString l, QString r);
    static QString getFullpath(QString filename);

    static QString getQrcPath(QString imageName);
    static GuiConfig guiConfig;
    static ConnectionTableModel *model;
    static ConfigHelper *configHelper;
    static QSettings *settings;
    static QString ONLINE_PAC_URL;
    static QString LOCAL_PAC_URL;
    static QString LOCAL_PAC_PATH;
    static QString DESKTOP_URL;
    static QString ONLINE_GFWLIST_URL;
    static QString LOCAL_GFWLIST_PATH;
    static QString USER_RULE_PATH;
    static QString UPDATE_URL;
    static QString VERSION;
    static QString LOG_PATH;
    static QString ORGANIZATION_NAME;
    static QString APPLICATION_NAME;
    static QString CONFIG_PATH;

    static qreal easeInOut(qreal x);

    static qreal easeInQuad(qreal x);

    static qreal easeInQuint(qreal x);

    static qreal easeOutQuad(qreal x);

    static qreal easeOutQuint(qreal x);

    static void setFontSize(QPainter &painter, int textSize);

    static QString formatBandwidth(double v);

    static QString formatByteCount(double v);

    static QString formatMillisecond(int millisecond);

    static QString formatUnitSize(double v, const char **orders, int nb_orders);

    static void readConfig(QString string, QObject *parent);

    static void saveConfig();

    static void showNotification(const QString &msg);

    static Connection *getCurrentConnection();

    static bool hasPacFile();
};

#endif //SHADOWSOCKS_CLIENT_UTIL_H
