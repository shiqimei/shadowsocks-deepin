/********************************************************************************
** Form generated from reading UI file 'ConfigDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditServerAddr;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditRemarks;
    QSpinBox *spinBoxTimeout;
    QSpinBox *spinBoxServerPort;
    QComboBox *comboBoxEncryption;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonDuplicate;
    QPushButton *pushButtonMoveUp;
    QPushButton *pushButtonMoveDown;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *spinBoxProxyPort;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(629, 372);
        listWidget = new QListWidget(ConfigDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(21, 31, 256, 192));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        groupBox = new QGroupBox(ConfigDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(310, 20, 311, 241));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditServerAddr = new QLineEdit(groupBox);
        lineEditServerAddr->setObjectName(QStringLiteral("lineEditServerAddr"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditServerAddr);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPassword);

        lineEditRemarks = new QLineEdit(groupBox);
        lineEditRemarks->setObjectName(QStringLiteral("lineEditRemarks"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditRemarks);

        spinBoxTimeout = new QSpinBox(groupBox);
        spinBoxTimeout->setObjectName(QStringLiteral("spinBoxTimeout"));

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxTimeout);

        spinBoxServerPort = new QSpinBox(groupBox);
        spinBoxServerPort->setObjectName(QStringLiteral("spinBoxServerPort"));
        spinBoxServerPort->setMaximum(65536);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxServerPort);

        comboBoxEncryption = new QComboBox(groupBox);
        comboBoxEncryption->setObjectName(QStringLiteral("comboBoxEncryption"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxEncryption);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, formLayout);

        layoutWidget = new QWidget(ConfigDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 260, 178, 104));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAdd = new QPushButton(layoutWidget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        gridLayout->addWidget(pushButtonAdd, 0, 0, 1, 1);

        pushButtonDelete = new QPushButton(layoutWidget);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        gridLayout->addWidget(pushButtonDelete, 0, 1, 1, 1);

        pushButtonDuplicate = new QPushButton(layoutWidget);
        pushButtonDuplicate->setObjectName(QStringLiteral("pushButtonDuplicate"));

        gridLayout->addWidget(pushButtonDuplicate, 1, 0, 1, 1);

        pushButtonMoveUp = new QPushButton(layoutWidget);
        pushButtonMoveUp->setObjectName(QStringLiteral("pushButtonMoveUp"));

        gridLayout->addWidget(pushButtonMoveUp, 2, 0, 1, 1);

        pushButtonMoveDown = new QPushButton(layoutWidget);
        pushButtonMoveDown->setObjectName(QStringLiteral("pushButtonMoveDown"));

        gridLayout->addWidget(pushButtonMoveDown, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(ConfigDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(430, 320, 178, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonOK = new QPushButton(layoutWidget1);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(layoutWidget1);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        layoutWidget2 = new QWidget(ConfigDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(319, 260, 291, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        spinBoxProxyPort = new QSpinBox(layoutWidget2);
        spinBoxProxyPort->setObjectName(QStringLiteral("spinBoxProxyPort"));
        spinBoxProxyPort->setMaximum(36555);

        horizontalLayout_2->addWidget(spinBoxProxyPort);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox->raise();
        listWidget->raise();

        retranslateUi(ConfigDialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), ConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("ConfigDialog", "Server", 0));
        label->setText(QApplication::translate("ConfigDialog", "Server Addr", 0));
        label_2->setText(QApplication::translate("ConfigDialog", "Server Port", 0));
        label_3->setText(QApplication::translate("ConfigDialog", "Password", 0));
        label_4->setText(QApplication::translate("ConfigDialog", "Encryption", 0));
        label_5->setText(QApplication::translate("ConfigDialog", "Remarks", 0));
        label_6->setText(QApplication::translate("ConfigDialog", "Timeout(Sec)", 0));
        pushButtonAdd->setText(QApplication::translate("ConfigDialog", "&Add", 0));
        pushButtonDelete->setText(QApplication::translate("ConfigDialog", "&Delete", 0));
        pushButtonDuplicate->setText(QApplication::translate("ConfigDialog", "Dupli&cate", 0));
        pushButtonMoveUp->setText(QApplication::translate("ConfigDialog", "Move &Up", 0));
        pushButtonMoveDown->setText(QApplication::translate("ConfigDialog", "Move D&own", 0));
        pushButtonOK->setText(QApplication::translate("ConfigDialog", "OK", 0));
        pushButtonCancel->setText(QApplication::translate("ConfigDialog", "Cancel", 0));
        label_7->setText(QApplication::translate("ConfigDialog", "Proxy Port", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
