//
// Created by pikachu on 17-8-5.
//

#include <QtGui/QPainter>
#include <QtCore/QMap>
#include "Util.h"

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
