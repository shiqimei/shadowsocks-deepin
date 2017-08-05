//
// Created by pikachu on 17-8-6.
//

#include "EditShortcutsWidget.h"

EditShortcutsWidget::EditShortcutsWidget(QWidget *parent) : QDialog(parent) {
    setFixedWidth(600);
    setWindowTitle("编辑快捷键...");
    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("切换系统代理状态",new QLineEdit());
    formLayout->addRow("切换系统代理模式",new QLineEdit());
    formLayout->addRow("切换局域网共享",new QLineEdit());
    formLayout->addRow("显示日志",new QLineEdit());
    formLayout->addRow("切换上个服务器",new QLineEdit());
    formLayout->addRow("切换下个服务器",new QLineEdit());
    QHBoxLayout* hBoxLayout=new QHBoxLayout();
    hBoxLayout->addStretch(1);
    pushButtonRegisterAllShortcuts=new QPushButton("注册全部热键");
    pushButtonCancel=new QPushButton("取消");
    pushButtonConfirm=new QPushButton("确认");
    hBoxLayout->addWidget(pushButtonRegisterAllShortcuts);
    hBoxLayout->addWidget(pushButtonCancel);
    hBoxLayout->addWidget(pushButtonConfirm);
    formLayout->addRow(hBoxLayout);
    setLayout(formLayout);

}
