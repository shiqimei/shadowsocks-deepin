//
// Created by pikachu on 17-12-31.
//

#include <DThemeManager>
#include "MultiListItem.h"

bool MultiListItem::sameAs(DSimpleListItem *item) {
    return false;
}

void MultiListItem::drawBackground(QRect rect, QPainter *painter, int index, bool isSelect) {
    QPainterPath path;
    path.addRect(QRectF(rect));
    // Draw selected effect.
    if (isSelect) {
        painter->setOpacity(selectOpacity);
        painter->fillPath(path, QColor(selectLineColor));
    }
        // Draw background effect.
    else {
        // Use different opacity with item index.
        if (index % 2 == 0) {
            painter->setOpacity(evenLineOpacity);
            painter->fillPath(path, QColor(evenLineColor));
        } else {
            painter->setOpacity(oddLineOpacity);
            painter->fillPath(path, QColor(oddLineColor));
        }
    }
}

void MultiListItem::drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect) {
    int padding = 10;
    painter->setOpacity(1);

    if (isSelect) {
        painter->setPen(QPen(QColor("#FFFFFF")));
    } else {
        painter->setPen(QPen(QColor("#000000")));
    }
    if (column == 0) {
        painter->drawText(QRect(rect.x() + padding, rect.y(), rect.width() - padding * 2, rect.height()), Qt::AlignLeft | Qt::AlignVCenter, artist);
    } else if (column == 1) {
        painter->drawText(QRect(rect.x() + padding, rect.y(), rect.width() - padding * 2, rect.height()), Qt::AlignLeft | Qt::AlignVCenter, song);
    } else if (column == 2) {
        painter->drawText(QRect(rect.x() + padding, rect.y(), rect.width() - padding * 2, rect.height()), Qt::AlignRight | Qt::AlignVCenter, length);
    }

    QList<QString> titles;
    titles<<"remarks"<<"server"<<"status"<<"latency"<<"local_port"<<"term_usage"<<"total_usage"<<"last_used";
    QString value = config->property(titles[column].toStdString().c_str()).toString();
    painter->drawText(QRect(rect.x() + padding, rect.y(), rect.width() - padding * 2, rect.height()), Qt::AlignLeft | Qt::AlignVCenter, value);
}

MultiListItem::MultiListItem(QString artistName, QString songName, QString songLength) {
    initTheme();
    artist = artistName;
    song = songName;
    length = songLength;
}

MultiListItem::MultiListItem() {

}

void MultiListItem::changeTheme(QString theme) {
    initTheme();
}

void MultiListItem::initTheme() {
    if (DThemeManager::instance()->theme() == "light") {
        evenLineColor = "#000000";
        evenLineOpacity = 0.02;

        oddLineColor = "#D8D8D8";
        oddLineOpacity = 0.02;

        selectLineColor = "#2CA7F8";
        selectOpacity = 1.0;

    } else {
        evenLineColor = "#D8D8D8";
        evenLineOpacity = 0.02;

        oddLineColor = "#000000";
        oddLineOpacity = 0.1;

        selectLineColor = "#006BBA";
        selectOpacity = 0.8;

    }
}

MultiListItem::MultiListItem(ProxyConfig *config) {
    initTheme();
    this->config = config;
}
