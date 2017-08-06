//
// Created by pikachu on 17-7-27.
//

#include <QtCore/QIODevice>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include "DownloadUtil.h"
#include <QDebug>
void DownloadUtil::download(QString url, QString filename) {
    QFile *file;
    QNetworkReply *networkReply;
    QNetworkAccessManager *networkAccessManager;
    QFileInfo fileInfo(filename);
    QDir dir = fileInfo.absoluteDir();

    //判断文件夹是否存在 不存在创建
    if (!dir.exists()) {
        dir.mkpath(dir.path());
    }
    file = new QFile(filename);
    //判断文件是否可写入 不可写删除
    if (!file->open(QIODevice::WriteOnly)) {
        delete file;
        file = nullptr;
        qDebug()<<"文件不可写";
        exit(0);
    }
    QUrl  serviceUrl = QUrl(url);
    networkAccessManager = new QNetworkAccessManager();
    networkReply=networkAccessManager->get(QNetworkRequest(serviceUrl));
#ifdef QT_DEBUG
    qDebug()<<"下载初始化完毕"<<"准备下载"<<url;
#endif
    QObject::connect(networkReply,&QNetworkReply::readyRead,[=](){
        if(file!= nullptr){
            file->write(networkReply->readAll());
        }
    });
    QObject::connect(networkReply,&QNetworkReply::finished,[=](){
        //刷新文件
        file->flush();
        file->close();
        file->deleteLater();
        networkReply->deleteLater();
        networkAccessManager->deleteLater();
        qDebug()<<"下载完成";
        emit finished();
    });
}
