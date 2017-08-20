//
// Created by pikachu on 17-7-25.
//

#include <QtWidgets/QGridLayout>
#include <util/Util.h>
#include "ShareServerConfigWidget.h"

ShareServerConfigWidget::ShareServerConfigWidget(QWidget *parent) : QDialog(parent) {
    setWindowTitle(tr("QR Code and URL"));
    listView = new QListView(this);
    listView->setModel(Util::model);
    lineEdit=new QLineEdit();
    qRencodeWidget = new QRencodeWidget("");
    auto *mainLayout = new QGridLayout();
    mainLayout->addWidget(qRencodeWidget,0,0);
    mainLayout->addWidget(listView, 0, 1);
    mainLayout->addWidget(lineEdit,1,0,1,2);
    setLayout(mainLayout);

    connect(listView, &QListView::clicked, [=](const QModelIndex &index) {
        int row = index.row();
//        qDebug()<<"row"<<row;
        ssUri = Util::model->getItem(row)->getConnection()->getURI();
        qRencodeWidget->setString(ssUri);
        lineEdit->setText(ssUri);
    });
    listView->clicked(Util::model->index(0, 0));
}
