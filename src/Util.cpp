//
// Created by pikachu on 17-8-5.
//

#include <QtGui/QPainter>
#include <QtCore/QMap>
#include <QtCore/QFile>
#include "Util.h"
#include <QDebug>
#include <QtCore/QDir>

QImage Util::mix(QStringList list) {
    if(list.isEmpty()){
        return QImage();
    }
    QImage image(list[0]);
//    image=image.scaled(24,24,Qt::KeepAspectRatio);
    QPainter painter(&image);
//    painter.setCompositionMode(QPainter::CompositionMode_Source);
//    painter.fillRect(image.rect(),Qt::transparent);
    for (int i = 1; i < list.size(); ++i) {
        auto t=QImage(list[i]);
//        t=t.scaled(24,24,Qt::KeepAspectRatio);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.drawImage(0,0,t);
    }
    painter.end();
    return image;
}
QImage Util::gray(QImage image) {
    QImage grayImage(image.width(),image.height(),QImage::Format_ARGB32);
    for (int i = 0; i < image.width(); ++i) {
        for (int j = 0; j < image.height(); ++j) {
            QRgb  pixel = image.pixel(i,j);
            int grayValue = qGray(pixel);
            QRgb grayPixel = qRgba(grayValue,grayValue,grayValue,grayValue);
            grayImage.setPixel(i,j,grayPixel);
        }
    }
    return grayImage;
}

QImage Util::noProxyIconImage() {
    static QImage* image = nullptr;
    if(image!= nullptr){
        return *image;
    } else{
        image = new QImage();
        *image = gray(QImage(":/icons/Resources/ssProxy24"));
        return *image;
    }
}

QImage Util::proxyIconImage(int type) {
    static QMap<int,QImage> map;
    if(map.contains(type)){
        return map.value(type);
    }
    QStringList list;
    if(type & Util::Type::Global){
        list<<":/icons/Resources/ssProxy24";
    } else{
        list<<":/icons/Resources/ss24.png";
    }
    if(Util::Type::In & type){
        list<<":/icons/Resources/ssIn24.png";
    }
    if(Util::Type::Out & type){
        list<<":/icons/Resources/ssOut24.png";
    }
    QImage image = mix(list);
    map.insert(type,image);
    return image;
}

QByteArray Util::readAllFile(QString filename) {
    QFile file(filename);
    if(!file.exists()){
        qDebug()<<"文件不存在";
        exit(0);
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"打开文件失败";
        exit(0);
    }
//    qDebug()<<"打开文件成功";
    return file.readAll();
}

int Util::compareVersion(QString l, QString r) {
    auto ls = l.split(".");
    auto rs = r.split(".");
    for (int i = 0; i < qMax(ls.length(), rs.length()); ++i) {
        int lp = (i<ls.length())?ls[i].toInt():0;
        int rp = (i<ls.length())?rs[i].toInt():0;
        if(lp!=rp){
            return lp-rp;
        }
    }
    return 0;
}

QString Util::getFullpath(QString filename) {
    return QObject::tr("%1/.ss/%2").arg(QDir::homePath()).arg(filename);
}
