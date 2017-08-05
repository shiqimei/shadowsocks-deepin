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
    };
    static QImage mix(QStringList list);
    static QImage gray(QImage image);
    static QImage noProxyIconImage();
    static QImage proxyIconImage(int type);
};


#endif //SHADOWSOCKS_CLIENT_UTIL_H
