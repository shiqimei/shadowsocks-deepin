//
// Created by pikachu on 17-8-5.
//

#ifndef SHADOWSOCKS_CLIENT_UTIL_H
#define SHADOWSOCKS_CLIENT_UTIL_H


#include <QtGui/QImage>

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

    static QString LOCAL_PAC_PATH;
    static QString DESKTOP_URL;
    static QString ONLINE_GFWLIST_URL;
    static QString LOCAL_GFWLIST_PATH;
    static QString USER_RULE_PATH;
    static QString UPDATE_URL;
    static QString LOG_PATH;
};

#endif //SHADOWSOCKS_CLIENT_UTIL_H
