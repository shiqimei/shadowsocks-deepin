#include "ShareDialog.h"
#include "ui_ShareDialog.h"
#include "GuiConfig.h"
ShareDialog::ShareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShareDialog)
{
    ui->setupUi(this);
    auto configs = GuiConfig::instance()->getConfigs();
    for(int i=0;i<configs.size();i++){
        auto it = configs.at(i).toObject();
        ui->listWidget->addItem(it.value("remarks").toString());
    }
    if(!configs.isEmpty()){
        ui->listWidget->setCurrentRow(0);
    }
}

ShareDialog::~ShareDialog()
{
    delete ui;
}

void ShareDialog::on_listWidget_currentRowChanged(int currentRow)
{
    QString uri = GuiConfig::instance()->getConfigURI(currentRow);
    ui->labelURI->setText(uri);
    ui->widget->setQRData(uri.toLocal8Bit());
    ui->widget->update();
}
