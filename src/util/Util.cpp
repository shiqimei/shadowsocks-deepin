//
// Created by pikachu on 17-8-5.
//
#include "stdafx.h"
#include "Util.h"

QString Util::DESKTOP_URL = QString("/usr/share/applications/shadowsocks-client.desktop");
QString Util::ONLINE_GFWLIST_URL = QString("https://raw.githubusercontent.com/gfwlist/gfwlist/master/gfwlist.txt");
QString Util::UPDATE_URL = QString("https://api.github.com/repos/PikachuHy/shadowsocks-client/releases");

QImage *Util::mix(QStringList list) {
    if(list.isEmpty()){
        return new QImage();
    }
    QImage *image = new QImage(list[0]);
//    image=image.scaled(24,24,Qt::KeepAspectRatio);
    QPainter painter(image);
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

QImage *Util::noProxyIconImage() {
    static QImage* image = nullptr;
    if(image!= nullptr){
        return image;
    } else{
        image = new QImage();
        *image = gray(QImage(":/icons/Resources/ssProxy24"));
        return image;
    }
}

QImage *const Util::proxyIconImage(int type) {
    static QMap<int, QImage *> map;
    if(map.contains(type)){
        qDebug() << "has " << type;
        return map.value(type);
    }
    QStringList list;
    if (type & Util::Type::None) {
        auto image = noProxyIconImage();
        map.insert(type, image);
        qDebug() << "noproxy";
        return image;
    }
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
    auto image = mix(list);
    map.insert(type,image);
    return image;
}

QIcon Util::getIcon(int type) {
//    qDebug() << "get icon" << type;
    return QIcon(QString(":/icons/Resources/%1.png").arg(type));
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

