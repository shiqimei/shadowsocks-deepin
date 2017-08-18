//
// Created by pikachu on 17-8-6.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include "PositiveAgentWidget.h"

PositiveAgentWidget::PositiveAgentWidget(QWidget *parent) : QDialog(parent) {
    setWindowTitle("代理设置");
    setFixedWidth(500);
    setFixedHeight(250);
    QGridLayout* gridLayout = new QGridLayout();
    int row = 0;
    int col = 0;
    checkBoxUseProxy = new QCheckBox("使用代理");
    gridLayout->addWidget(checkBoxUseProxy,row,col++,1,2);
    row++;
    col=0;
    gridLayout->addWidget(new QLabel("代理类型"),row,col++);
    comboBoxProxyType=new QComboBox();
    comboBoxProxyType->addItems(QStringList()<<"SOCKS5"<<"HTTP");
    gridLayout->addWidget(comboBoxProxyType,row,col++);
    gridLayout->addWidget(new QLabel("超时(秒)"),row,col++);
    spinBoxProxyTimeout=new QSpinBox();
    gridLayout->addWidget(spinBoxProxyTimeout,row,col++);
    row++;
    col=0;
    gridLayout->addWidget(new QLabel("代理地址"),row,col++);
    lineEditProxyServer=new QLineEdit();
    gridLayout->addWidget(lineEditProxyServer,row,col++);
    gridLayout->addWidget(new QLabel("代理端口"),row,col++);
    spinBoxProxyPort=new QSpinBox();
    spinBoxProxyPort->setRange(0,35535);
    gridLayout->addWidget(spinBoxProxyPort,row,col++);
    gridLayout->setColumnStretch(1,1);
    gridLayout->setColumnStretch(3,1);

    QHBoxLayout* hBoxLayout = new QHBoxLayout();
    pushButtonConfirm=new QPushButton("确认");
    pushButtonCancel=new QPushButton("取消");
    hBoxLayout->addStretch(1);
    hBoxLayout->addWidget(pushButtonConfirm);
    hBoxLayout->addWidget(pushButtonCancel);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(gridLayout);
    mainLayout->addStretch(1);
    mainLayout->addLayout(hBoxLayout);
    setLayout(mainLayout);
}
