#include <util/Util.h>
#include <QtWidgets/QDataWidgetMapper>
#include "EditServerDialog.h"
#include "ui_EditServerDialog.h"

//#define QT_DEBUG 0
//#undef QT_DEBUG
EditServerDialog::EditServerDialog(QWidget *parent) : EditServerDialog(false, parent) {}
EditServerDialog::EditServerDialog(bool isNew, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::EditServerDialog){
    ui->setupUi(this);
    ui->listView->setModel(Util::model);
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(Util::model);
    mapper->addMapping(ui->remarkLineEdit, 9);
    mapper->addMapping(ui->serverAddressLineEdit, 1);
    for (int i = 0; i < 4; ++i) {
        mapper->addMapping(new QLineEdit(), i);
    }
    mapper->addMapping(ui->proxyPortSpinBox, 9);
    for (int j = 0; j < 9; ++j) {
        mapper->addMapping(new QLineEdit(), j);
    }
    mapper->addMapping(ui->serverPortSpinBox, 4);
    mapper->addMapping(ui->encryptComboBox, 10);
    mapper->addMapping(ui->passwordLineEdit, 11);
    mapper->addMapping(ui->timeoutSpinBox, 12);
    mapper->setSubmitPolicy(QDataWidgetMapper::SubmitPolicy::AutoSubmit);
    QList<QByteArray> methodBA = QSS::Cipher::getSupportedMethodList();
    QStringList methodList;
    for (const QByteArray &method : methodBA) {
        methodList.push_back(QString(method));
    }
    ui->encryptComboBox->addItems(methodList);
    connect(ui->listView, &QListView::clicked, [=](const QModelIndex &index) {
        qDebug() << index;
//        mapper->submit();
        mapper->setCurrentModelIndex(index);
    });


//    mapper->addMapping(ui.)

    /*
//    ui->groupBox->setLayout(ui->formLayout);
    connect(ui->listWidget, &QListWidget::currentRowChanged, [=](int currentRow) {
#ifdef QT_DEBUG
        qDebug() <<"currentRow"<< currentRow;
#endif
        onListWidgetChange();
        if(currentRow>=0){
            ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
            Q_ASSERT(item!= nullptr);
#ifdef QT_DEBUG
            ConfigUtil::printProfile(item->profile);
#endif
            ui->serverAddressLineEdit->setText(item->profile.server);
            ui->serverPortSpinBox->setValue(item->profile.server_port);
            ui->passwordLineEdit->setText(item->profile.password);
            ui->encryptComboBox->setCurrentText(item->profile.method);
            ui->remarkLineEdit->setText(item->text());
            ui->timeoutSpinBox->setValue(item->profile.timeout);
            ui->proxyPortSpinBox->setValue(item->profile.local_port);
            localPort=item->profile.local_port;

        }
    });
    connect(ui->serverAddressLineEdit,&QLineEdit::textChanged,[=](const QString& text){
        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
        item->profile.server=text;

    });
//    static_cast< void(QComboBox :: *)(int)>(& QComboBox :: currentIndexChanged)

    connect(ui->serverPortSpinBox,static_cast< void(QSpinBox :: *)(int)>(& QSpinBox :: valueChanged),[=](int value){
        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
        item->profile.server_port= static_cast<quint16>(value);
#ifdef QT_DEBUG
       qDebug()<<value;
#endif
    });
    connect(ui->passwordLineEdit,&QLineEdit::textChanged,[=](const QString& text){
        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
        item->profile.password=text;
    });
    connect(ui->encryptComboBox,&QComboBox::currentTextChanged,[=](const QString & text){
        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
        item->profile.method=text;
    });
    connect(ui->timeoutSpinBox,static_cast< void(QSpinBox :: *)(int)>(& QSpinBox :: valueChanged),[=](int value){
        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
        item->profile.timeout=value;
        qDebug()<<value;
    });
    connect(ui->proxyPortSpinBox,static_cast< void(QSpinBox :: *)(int)>(& QSpinBox :: valueChanged),[=](int value){
//        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
#ifdef QT_DEBUG
//        item->profile.local_port=value;
        qDebug()<<value;
#endif
        localPort=value;
    });
    connect(ui->remarkLineEdit,&QLineEdit::textChanged,[=](const QString& text){
        ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
        item->setText(text);
    });
    connect(ui->savePushButton,&QPushButton::clicked,[=](){
        QList<Config> list;
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->item(i));
#ifdef QT_DEBUG
            qDebug()<<item->text()<<item->profile.server;
#endif
            Config config;
            config.profile=item->profile;
            config.setRemarks(item->text());
            list.append(config);
        }
        ConfigUtil::saveConfig(list);
        QDialog::accept();
    });

    setLayout(ui->mainLayout);
    onListWidgetChange();
    initConfig();
    if(isNew){
        ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    }*/
}

EditServerDialog::~EditServerDialog() {
    delete ui;
}

void EditServerDialog::on_addPushButton_clicked() {
/*#ifdef QT_DEBUG
    qDebug() << "on_addPushButton_clicked()";
#endif
    Profile profile;
    ServerItem *newItem = new ServerItem(profile, "new server");
    ui->listWidget->addItem(newItem);
    ui->listWidget->setCurrentItem(newItem);
    onListWidgetChange();*/
}

void EditServerDialog::onListWidgetChange() {
/*    int count = ui->listWidget->count();
    int curRow = ui->listWidget->currentRow();
    ui->removePushButton->setEnabled(count > 0);
    ui->copyPushButton->setEnabled(count > 0);
    ui->upPushButton->setEnabled(curRow > 0);
    ui->downPushButton->setEnabled(curRow != count - 1);
    setFormEnabled(count>0);*/
}

void EditServerDialog::on_removePushButton_clicked() {
/*    ServerItem *item = dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
    serverItemList.removeOne(item);
    ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
    onListWidgetChange();*/
}

void EditServerDialog::on_copyPushButton_clicked() {
/*//    int row=ui->listWidget->currentRow();
    ServerItem* item= dynamic_cast<ServerItem *>(ui->listWidget->currentItem());
    Profile profile=item->profile;
    ServerItem* newItem=new ServerItem(profile,item->text());
    serverItemList.append(newItem);
    ui->listWidget->addItem(newItem);
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
//    serverItemList.swap()*/
}

void EditServerDialog::on_upPushButton_clicked() {
/*    int row=ui->listWidget->currentRow();
#ifdef QT_DEBUG
    qDebug()<<"swap"<<row<<row-1;
    qDebug()<<"swap"<<serverItemList[row]->text()<<serverItemList[row-1]->text();
    qDebug()<<"swap"<<ui->listWidget->item(row)->text()<<ui->listWidget->item(row-1)->text();
//    ServerItem* temp = serverItemList[row];
//    serverItemList[row]=serverItemList[row-1];
//    serverItemList[row-1]=temp;
#endif
    serverItemList.swap(row-1,row);
    updateListWidget();
    ui->listWidget->setCurrentRow(row-1);
    onListWidgetChange();*/
}

void EditServerDialog::on_downPushButton_clicked() {
/*    int row=ui->listWidget->currentRow();
    serverItemList.swap(row+1,row);
    updateListWidget();
    ui->listWidget->setCurrentRow(row+1);
    onListWidgetChange();*/
}

void EditServerDialog::initConfig() {
/*
    auto configs=ConfigUtil::readConfig();
    for(auto&it:configs){
        serverItemList.append(new ServerItem(it.profile, it.getRemarks()));
    }
    updateListWidget();
    if(ui->listWidget->count()>0){
        ui->listWidget->setCurrentRow(0);
    } else{

    }
*/

}

void EditServerDialog::updateListWidget() {
/*#ifdef QT_DEBUG
    qDebug()<<"";
#endif
    while (ui->listWidget->count()>0) {
        ui->listWidget->takeItem(0);
    }
    for(ServerItem* item:serverItemList){
        ui->listWidget->addItem(item);
#ifdef QT_DEBUG
        qDebug()<<item->text();
#endif
    }
    if(!serverItemList.isEmpty()){
        ui->listWidget->addItem(serverItemList[0]);
    } else{
        setFormEnabled(false);
    }*/
}

void EditServerDialog::setFormEnabled(bool flag) {
/*    ui->serverAddressLineEdit->setEnabled(flag);
    ui->serverPortSpinBox->setEnabled(flag);
    ui->passwordLineEdit->setEnabled(flag);
    ui->encryptComboBox->setEnabled(flag);
    ui->remarkLineEdit->setEnabled(flag);
    ui->timeoutSpinBox->setEnabled(flag);
    ui->proxyPortSpinBox->setEnabled(flag);*/
}

ServerItem::ServerItem(const Profile &profile, QString remarks, QListWidget *view, int type)
        : QListWidgetItem(remarks, view, type),
          profile(profile) {
}
