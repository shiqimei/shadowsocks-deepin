//
// Created by pikachu on 17-8-6.
//

#ifndef SHADOWSOCKS_CLIENT_UPDATECHECKER_H
#define SHADOWSOCKS_CLIENT_UPDATECHECKER_H

#include <QObject>
#include <QtCore/QString>
#include <QApplication>

class Asset;
class UpdateChecker: public QObject {
    Q_OBJECT
public:
    void checkUpdate();
private:
    void updateSS(Asset* asset);
};


#endif //SHADOWSOCKS_CLIENT_UPDATECHECKER_H
