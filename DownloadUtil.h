//
// Created by pikachu on 17-7-27.
//

#ifndef SHADOWSOCKS_CLIENT_DOWNLOADUTIL_H
#define SHADOWSOCKS_CLIENT_DOWNLOADUTIL_H

#include <QObject>
#include <QtCore/QString>
#include "DownloadUtil.h"
class DownloadUtil : public QObject {
    Q_OBJECT
public:
    void download(QString url, QString filename);

signals:

    void finished();

};


#endif //SHADOWSOCKS_CLIENT_DOWNLOADUTIL_H
