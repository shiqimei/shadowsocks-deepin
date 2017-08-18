//
// Created by pikachu on 17-7-25.
//

#include "QRencodeWidget.h"


QRencodeWidget::QRencodeWidget(QString string,QWidget *parent) : QWidget(parent) {
    setMinimumWidth(400);
    setMinimumHeight(400);
    qRcode= nullptr;
    setString(std::move(string));
}

void QRencodeWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    /**
     * 把背景涂成白色
     */
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width(), height());
    if(qRcode != nullptr)
    {
        QColor foreground(Qt::black);
        painter.setBrush(foreground);
        const int qr_width = qRcode->width > 0 ? qRcode->width : 1;
        /**
         * 把二维码缩放后绘制到窗口上
         */
        double scale_x = width() / qr_width;
        double scale_y = height() / qr_width;
        for( int y = 0; y < qr_width; y ++)
        {
            for(int x = 0; x < qr_width; x++)
            {
                unsigned char b = qRcode->data[y * qr_width + x];
                if(b & 0x01)
                {
                    QRectF r(x * scale_x, y * scale_y, scale_x, scale_y);
                    painter.drawRects(&r, 1);
                }
            }
        }
    }
    QWidget::paintEvent(event);
}

void QRencodeWidget::setString(QString string) {
    if(qRcode!= nullptr){
        QRcode_free(qRcode);
    }
    qRcode=QRcode_encodeString(string.toStdString().c_str(),1,QR_ECLEVEL_L,QR_MODE_8,1);
    update();
}
