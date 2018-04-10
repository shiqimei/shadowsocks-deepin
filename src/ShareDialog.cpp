#include "ShareDialog.h"
#include "GuiConfig.h"
#include "widget/SingleListItem.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include "utils.h"
#include <DDesktopServices>
ShareDialog::ShareDialog(QWidget *parent) :
    QDialog(parent)
{
    // 无法获取Item的点击事件，自己造了一个
    listView = new SingleListView(this);
    qrWidget = new QRWidget(this);
    uriLabel = new QLabel("uri:");
    saveButton = new QPushButton(tr("save QRCode Image"));
    listView->setMinimumSize(200,350);
    qrWidget->setMinimumSize(350,350);
    // 始终无法处理好换行的问题，放弃，不显示
    uriLabel->setMaximumWidth(200);
    uriLabel->setMinimumHeight(50);
    uriLabel->setWordWrap(false);
    QList<DSimpleListItem*> items;
    auto configs = GuiConfig::instance()->getConfigs();
    for(int i=0;i<configs.size();i++){
        auto it = configs.at(i).toObject();
        auto remarks = it.value("remarks").toString();
        auto item = new SingleListItem(remarks);
        connect(item,&SingleListItem::selected,this,&ShareDialog::onItemSelected);
        items<<item;
        item->setProperty("data",GuiConfig::instance()->getConfigURI(i));
    }
    if(!configs.isEmpty()){
        QString uri = GuiConfig::instance()->getConfigURI(0);
        setCurrentURI(uri);
    }
    listView->refreshItems(items);
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(new QLabel("Profile list"),0,0);
    layout->addWidget(new QLabel("QRCode"),0,1);
    layout->addWidget(listView,1,0);
    layout->addWidget(qrWidget,1,1);
    layout->addWidget(saveButton,2,1,Qt::AlignTop | Qt::AlignRight);
    this->setLayout(layout);
    connect(saveButton,&QPushButton::clicked,this,&ShareDialog::onSaveQRCodeImage);
}

ShareDialog::~ShareDialog()
{
    qDebug()<<"ShareDialog::~ShareDialog()";
}

void ShareDialog::closeEvent(QCloseEvent *)
{
    qDebug()<<"set list view to nullptr";
    listView->setParent(nullptr);
}

void ShareDialog::onItemSelected()
{
    SingleListItem* item =static_cast<SingleListItem*>(sender());
    QString uri = item->property("data").toString();
    setCurrentURI(uri);
}

void ShareDialog::onSaveQRCodeImage()
{
    QString filename = QFileDialog::getSaveFileName(nullptr,tr("Save QRCode Image"),
                                                    QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).first(),
                                                    tr("Images (*.png *.xpm *.jpg)"));
    if(filename.isEmpty()){
        return;
    }
    bool flag = qrWidget->getQRImage().save(filename,"png");
    if(flag){
        Utils::info(tr("Save QRCode Image Success"));
        DDesktopServices::showFileItem(filename);
    }else{
        Utils::critical(tr("Save QRCode Image Error"));
    }
}

void ShareDialog::setCurrentURI(QString uri)
{
    currentURI = uri;
    qrWidget->setQRData(uri.toLocal8Bit());
    qrWidget->update();
    // 自己做一下换行
    QStringList l;
    int width = 20;
    while(uri.length()>width){
        l<<uri.left(width);
        uri = uri.remove(0,width);
    }
    l<<uri;
    uriLabel->setText(l.join("\r\n"));
}
