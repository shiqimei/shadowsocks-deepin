//
// Created by pikachu on 17-8-3.
//

#include <QtCore/QDir>
#include <QtWidgets/QVBoxLayout>
#include "ShowLogWidget.h"
#include <util/Util.h>
ShowLogWidget::ShowLogWidget(QWidget *parent) : QWidget(parent) {
    setMinimumWidth(1200);
//    plainTextEdit = new QPlainTextEdit();
//    QFile logFile(Util::LOG_PATH);
//    if (!logFile.exists()){
//        logFile.open(QIODevice::WriteOnly);
//        logFile.close();
//    }
//    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug() << "打开日志文件失败";
//        QMessageBox::critical(nullptr,"ERROR","Open log file fail");
//        exit(0);
//    }
//    plainTextEdit->setPlainText(logFile.readAll());
//    plainTextEdit->moveCursor(QTextCursor::End);
//    plainTextEdit->setReadOnly(true);
//    auto *mainLayout = new QVBoxLayout();
//    mainLayout->addWidget(plainTextEdit);
//    setLayout(mainLayout);
//    DUtility::moveToCenter(this);
}
