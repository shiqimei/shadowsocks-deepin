#include <util/Util.h>
#include "EditServerDialog.h"
#include "ui_EditServerDialog.h"
#include <vector>
#include <cipher.h>
//#define QT_DEBUG 0
//#undef QT_DEBUG
EditServerDialog::EditServerDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::EditServerDialog){
    ui->setupUi(this);
    setWindowTitle(tr("Servers"));
    ui->listView->setModel(Util::model);
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(Util::model);
    mapper->addMapping(ui->remarkLineEdit, 0);
    mapper->addMapping(ui->serverAddressLineEdit, 1);
    mapper->addMapping(ui->proxyPortSpinBox, 4);
    mapper->addMapping(ui->serverPortSpinBox, 9);
    mapper->addMapping(ui->encryptComboBox, 10);
    mapper->addMapping(ui->passwordLineEdit, 11);
    mapper->addMapping(ui->timeoutSpinBox, 12);
    mapper->setSubmitPolicy(QDataWidgetMapper::SubmitPolicy::AutoSubmit);
    auto methodBA = QSS::Cipher::supportedMethods();
    QStringList methodList;
    for (const auto &method : methodBA) {
        methodList.push_back(QString::fromStdString(method));
    }
    ui->encryptComboBox->addItems(methodList);
    connect(ui->listView, &QListView::clicked, [=](const QModelIndex &index) {
        mapper->setCurrentModelIndex(index);
        onListWidgetChange();
    });
    if (Util::model->rowCount() > 0)
        ui->listView->setCurrentIndex(Util::model->index(0, 0));
    mapper->toFirst();
    onListWidgetChange();
}

EditServerDialog::~EditServerDialog() {
    Util::configHelper->save(*Util::model);
    delete ui;
}

void EditServerDialog::on_addPushButton_clicked() {
    auto *connection = new Connection();
    Util::model->appendConnection(connection);
    ui->listView->setCurrentIndex(Util::model->index(Util::model->rowCount() - 1, 0));
    mapper->toLast();
}

void EditServerDialog::onListWidgetChange() {
    auto row = ui->listView->currentIndex().row();
    const auto valid = ui->listView->currentIndex().isValid();
    ui->upPushButton->setEnabled(valid ? row > 0 : false);
    ui->downPushButton->setEnabled(valid ? row < Util::model->rowCount() - 1 : false);
    ui->removePushButton->setEnabled(valid);
    ui->copyPushButton->setEnabled(valid);
    setFormEnabled(valid);
}

void EditServerDialog::on_removePushButton_clicked() {
    auto row = ui->listView->currentIndex().row();
    if (Util::model->removeRow(ui->listView->currentIndex().row())) {
        Util::configHelper->save(*Util::model);
    }
    mapper->setCurrentIndex(row > 0 ? row - 1 : row);
    onListWidgetChange();
}

void EditServerDialog::on_copyPushButton_clicked() {
    auto connection = new Connection(
            Util::model->getItem(ui->listView->currentIndex().row())->getConnection()->getProfile());
    Util::model->appendConnection(connection);
    ui->listView->setCurrentIndex(Util::model->index(Util::model->rowCount() - 1, 0));
    mapper->toLast();
}

void EditServerDialog::on_upPushButton_clicked() {
    auto curRow = ui->listView->currentIndex().row();
    auto targetRow = curRow - 1;
    Util::model->move(curRow, targetRow);
    onListWidgetChange();
}

void EditServerDialog::on_downPushButton_clicked() {
    auto curRow = ui->listView->currentIndex().row();
    auto targetRow = curRow + 1;
    Util::model->move(curRow, targetRow);
    onListWidgetChange();
}

void EditServerDialog::setFormEnabled(bool flag) {
    ui->serverAddressLineEdit->setEnabled(flag);
    ui->serverPortSpinBox->setEnabled(flag);
    ui->passwordLineEdit->setEnabled(flag);
    ui->encryptComboBox->setEnabled(flag);
    ui->remarkLineEdit->setEnabled(flag);
    ui->timeoutSpinBox->setEnabled(flag);
    ui->proxyPortSpinBox->setEnabled(flag);
}

void EditServerDialog::on_pushButtonTestLatency_clicked() {
    auto item = Util::model->getItem(ui->listView->currentIndex().row());
    item->testLatency();
    connect(item, &ConnectionItem::latencyChanged, this, &EditServerDialog::onConnectionItem_latencyChanged);
}

void EditServerDialog::onConnectionItem_latencyChanged() {
    auto *item = dynamic_cast<ConnectionItem *>(sender());
    disconnect(item, &ConnectionItem::latencyChanged, this, &EditServerDialog::onConnectionItem_latencyChanged);
    auto latency = item->getConnection()->getProfile().latency;
    auto s = item->convertLatencyToString(latency);
    QMessageBox::information(nullptr, tr("test latency"), tr("test latency result: %1").arg(s));
}

