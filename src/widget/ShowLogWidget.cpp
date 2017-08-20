//
// Created by pikachu on 17-8-3.
//

#include <QtCore/QDir>
#include <QtWidgets/QVBoxLayout>
#include "ShowLogWidget.h"
#include <dutility.h>

ShowLogWidget::ShowLogWidget(QWidget *parent) : QWidget(parent) {
    setMinimumWidth(1200);
    plainTextEdit = new QPlainTextEdit();
    QFile logFile(QString("%1/.cache/pikachu/shadowsocks-client/shadowsocks-client.log").arg(QDir::homePath()));
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "打开日志文件失败";
        exit(0);
    }
    plainTextEdit->setPlainText(logFile.readAll());
    plainTextEdit->moveCursor(QTextCursor::End);
    plainTextEdit->setReadOnly(true);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(plainTextEdit);
//    QScrollBar* scrollBar = plainTextEdit->verticalScrollBar();
//    if(scrollBar!= nullptr){
//        scrollBar->setSliderPosition(scrollBar->maximum());
//        qDebug()<<"滑动到底部";
//    }
    setLayout(mainLayout);
    DUtility::moveToCenter(this);
}
