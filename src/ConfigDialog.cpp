#include "ConfigDialog.h"
#include "ui_ConfigDialog.h"
#include "GuiConfig.h"
#include "utils.h"

void ConfigDialog::updateListWidget() {
    auto guiConfig = GuiConfig::instance();
    array = guiConfig->getConfigs();
    // cause current row -1
    ui->listWidget->clear();
    qDebug() << "config array" << array.size();
    for (auto it:array) {
        ui->listWidget->addItem(it.toObject().value("remarks").toString());
    }
}

void ConfigDialog::connectChanged() {
    connect(ui->lineEditPassword, &QLineEdit::textChanged, this, &ConfigDialog::modified);
    connect(ui->lineEditRemarks, &QLineEdit::textChanged, this, &ConfigDialog::modified);
    connect(ui->lineEditServerAddr, &QLineEdit::textChanged, this, &ConfigDialog::modified);
    connect(ui->spinBoxProxyPort, SIGNAL(valueChanged(int)), this, SLOT(modified()));
    connect(ui->spinBoxServerPort, SIGNAL(valueChanged(int)), this, SLOT(modified()));
    connect(ui->spinBoxTimeout, SIGNAL(valueChanged(int)), this, SLOT(modified()));
    connect(ui->comboBoxEncryption, &QComboBox::currentTextChanged, this, &ConfigDialog::modified);
}

void ConfigDialog::disconnectChanged() {
    disconnect(ui->lineEditPassword, &QLineEdit::textChanged, this, &ConfigDialog::modified);
    disconnect(ui->lineEditRemarks, &QLineEdit::textChanged, this, &ConfigDialog::modified);
    disconnect(ui->lineEditServerAddr, &QLineEdit::textChanged, this, &ConfigDialog::modified);
    disconnect(ui->spinBoxProxyPort, SIGNAL(valueChanged(int)), this, SLOT(modified()));
    disconnect(ui->spinBoxServerPort, SIGNAL(valueChanged(int)), this, SLOT(modified()));
    disconnect(ui->spinBoxTimeout, SIGNAL(valueChanged(int)), this, SLOT(modified()));
    disconnect(ui->comboBoxEncryption, &QComboBox::currentTextChanged, this, &ConfigDialog::modified);
}

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog) {
    ui->setupUi(this);
    isModified = false;
    updateListWidget();
    std::vector<std::string> methodBA = QSS::Cipher::supportedMethods();
    std::sort(methodBA.begin(), methodBA.end());
    QStringList methodList;
    for (const std::string &method : methodBA) {
        methodList.push_back(QString::fromStdString(method));
    }
    ui->comboBoxEncryption->addItems(methodList);
    connectChanged();

    // disconnectChanged();
    ui->listWidget->setCurrentRow(0);
    Dtk::Widget::moveToCenter(this);
}

ConfigDialog::~ConfigDialog() {
    delete ui;
}

void ConfigDialog::save() {
    lastConfig.insert("password", ui->lineEditPassword->text());
    lastConfig.insert("remarks", ui->lineEditRemarks->text());
    lastConfig.insert("server", ui->lineEditServerAddr->text());
    lastConfig.insert("server_port", ui->spinBoxServerPort->value());
    lastConfig.insert("local_port", ui->spinBoxProxyPort->value());
    lastConfig.insert("timeout", ui->spinBoxTimeout->value());
    lastConfig.insert("method", ui->comboBoxEncryption->currentText());
    array.replace(lastPos, lastConfig);
    GuiConfig::instance()->setConfigs(array);
}

void ConfigDialog::modified() {
    isModified = true;
    lastConfig.insert("update_time", Utils::getTimestamp());
}

void ConfigDialog::checkModify() {
    if (isModified) {
        auto ret = QMessageBox::information(nullptr, "warning", tr("Your config is modified. Do you want to save it?"),
                                            QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes) {
            save();
            isModified = false;
            // updateListWidget();
        }
    }
}

void ConfigDialog::on_listWidget_currentRowChanged(int currentRow) {
    if (currentRow < 0) {
        qDebug() << "cur row" << currentRow << " clear listwidget";
        return;
    }
    checkModify();
    auto config = array.at(currentRow).toObject();
    ui->lineEditPassword->setText(config.value("password").toString());
    ui->lineEditRemarks->setText(config.value("remarks").toString());
    ui->lineEditServerAddr->setText(config.value("server").toString());
    ui->spinBoxServerPort->setValue(config.value("server_port").toInt());
    ui->spinBoxProxyPort->setValue(config.value("local_port").toInt());
    ui->spinBoxTimeout->setValue(config.value("timeout").toInt());
    ui->comboBoxEncryption->setCurrentText(config.value("method").toString());
    lastConfig = config;
    lastPos = currentRow;
    isModified = false;
    qDebug() << "cur pos" << lastPos;
}

void ConfigDialog::on_pushButtonAdd_clicked() {
    checkModify();
    QJsonObject o = lastConfig;
    auto t = Utils::getTimestamp();
    o.insert("create_time", t);
    o.insert("update_time", t);
    o.insert("password", "");
    o.insert("server", "");
    o.insert("remarks", tr("unname"));
    GuiConfig::calId(o);
    array.append(o);
    save();
    updateListWidget();
    ui->listWidget->setCurrentRow(array.size() - 1);
}

void ConfigDialog::on_pushButtonDelete_clicked() {
    int ret = QMessageBox::warning(nullptr, "warning", tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::No) {
        return;
    }
    array.removeAt(lastPos);
    save();
    if (array.isEmpty()) {
        ui->lineEditPassword->clear();
        ui->lineEditRemarks->clear();
        ui->lineEditServerAddr->clear();
        updateListWidget();
    } else if (array.size() > lastPos) {
        updateListWidget();
        ui->listWidget->setCurrentRow(lastPos);
    } else {
        updateListWidget();
        ui->listWidget->setCurrentRow(lastPos - 1);
    }
}

void ConfigDialog::on_pushButtonDuplicate_clicked() {
    checkModify();
    QJsonObject o = lastConfig;
    auto t = Utils::getTimestamp();
    o.insert("create_time", t);
    o.insert("update_time", t);
    GuiConfig::calId(o);
    array.append(o);
    save();
    updateListWidget();
    ui->listWidget->setCurrentRow(array.size() - 1);
}

void ConfigDialog::on_pushButtonMoveUp_clicked() {
    if (lastPos == 0) {
        return;
    }
    auto o1 = array.at(lastPos).toObject();
    auto o2 = array.at(lastPos - 1).toObject();
    array.replace(lastPos, o2);
    array.replace(lastPos - 1, o1);
    GuiConfig::instance()->setConfigs(array);
    updateListWidget();
    ui->listWidget->setCurrentRow(lastPos - 1);
}

void ConfigDialog::on_pushButtonMoveDown_clicked() {
    if (lastPos == array.size() - 1) {
        return;
    }
    auto o1 = array.at(lastPos).toObject();
    auto o2 = array.at(lastPos + 1).toObject();
    array.replace(lastPos, o2);
    array.replace(lastPos + 1, o1);
    GuiConfig::instance()->setConfigs(array);
    updateListWidget();
    ui->listWidget->setCurrentRow(lastPos + 1);
}

void ConfigDialog::on_pushButtonOK_clicked() {
    checkModify();
    GuiConfig::instance()->setConfigs(array);
    close();
}
