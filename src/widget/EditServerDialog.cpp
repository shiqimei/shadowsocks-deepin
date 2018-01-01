#include "stdafx.h"
#include <util/Util.h>
#include "EditServerDialog.h"
#include "ui_EditServerDialog.h"
#include <vector>
#include <cipher.h>
#include "dao/ConfigDAO.h"
#include "widget/SingleListView.h"
#include "SingleListItem.h"

EditServerDialog::EditServerDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::EditServerDialog){
    ui->setupUi(this);
    QGridLayout* l = dynamic_cast<QGridLayout *>(layout());
    listView = new SingleListView();
    l->addWidget(listView, 1, 0);
    setWindowTitle(tr("Servers"));
    auto configDAO =  ConfigDAO::instance();
    list = configDAO->findAll();

    for(auto& it:list){
        auto item = new SingleListItem(it);
        items.append(item);
    }
    listView->refreshItems(items);
    auto methodBA = QSS::Cipher::supportedMethods();
    QStringList methodList;
    for (const auto &method : methodBA) {
        methodList.push_back(QString::fromStdString(method));
    }
    ui->encryptComboBox->addItems(methodList);
//    list.first()->setProperty("remarks","wbd");
//    listView->refreshItems(items);
    listView->clearItems();
    listView->refreshItems(items);
}

EditServerDialog::~EditServerDialog() {
    delete ui;
}

void EditServerDialog::on_addPushButton_clicked() {
    auto config = new ProxyConfig();
    config->setProperty("remarks","new config");
    list.append(config);

    for(auto& it:list){
        auto item = new SingleListItem(it);
        items.append(item);
    }
//    listView->refreshItems(items);
    listView->clearItems();
    listView->addItems(items);
}

void EditServerDialog::onListWidgetChange() {
}

void EditServerDialog::on_removePushButton_clicked() {
}

void EditServerDialog::on_copyPushButton_clicked() {
}

void EditServerDialog::on_upPushButton_clicked() {
}

void EditServerDialog::on_downPushButton_clicked() {
}

void EditServerDialog::setFormEnabled(bool flag) {
}

void EditServerDialog::on_pushButtonTestLatency_clicked() {
}

void EditServerDialog::onConnectionItem_latencyChanged() {
}

void EditServerDialog::wheelEvent(QWheelEvent *event) {
    qDebug()<<"wheel event";
    QWidget::wheelEvent(event);
}

