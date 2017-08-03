//
// Created by pikachu on 17-7-25.
//

#include <QtWidgets/QGridLayout>
#include "ShareServerConfigWidget.h"
#include <QDebug>
ShareServerConfigWidget::ShareServerConfigWidget(QWidget *parent) : QDialog(parent) {
    setWindowTitle("二维码与URL");
    listWidget=new QListWidget(this);
    configs = ConfigUtil::readConfig();
    lineEdit=new QLineEdit();
    qDebug()<<"发生了什么"<<configs.size();
    if(!configs.isEmpty()){
        ssUri=configs.first().getSsUri();
        qRencodeWidget=new QRencodeWidget(ssUri);
        lineEdit->setText(ssUri);
#ifdef QT_DEBUG
        qDebug()<<"使用 ss: "<<ssUri;
#endif
    } else{
        qRencodeWidget=new QRencodeWidget("");
    }
    for(auto&config:configs){
        listWidget->addItem(config.remarks);
    }
    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->addWidget(qRencodeWidget,0,0);
    mainLayout->addWidget(listWidget,0,1);
    mainLayout->addWidget(lineEdit,1,0,1,2);
    setLayout(mainLayout);

    connect(listWidget,&QListWidget::currentRowChanged,[=](int row){
        ssUri=configs[row].getSsUri();
        qRencodeWidget->setString(ssUri);
        lineEdit->setText(ssUri);
    });
    if(!configs.isEmpty()){
        listWidget->setCurrentRow(0);
    }
}
