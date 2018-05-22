/********************************************************************************
** Form generated from reading UI file 'SenderOptions.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDEROPTIONS_H
#define UI_SENDEROPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SenderOptions
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLineEdit *lineSenderIP;
    QLabel *label;
    QLineEdit *lineSenderPacketSize;
    QLabel *label_2;
    QLineEdit *lineSenderNumPackets;
    QLabel *label_3;
    QLineEdit *lineSenderPort;
    QLabel *label_4;

    void setupUi(QDialog *SenderOptions)
    {
        if (SenderOptions->objectName().isEmpty())
            SenderOptions->setObjectName(QStringLiteral("SenderOptions"));
        SenderOptions->resize(914, 498);
        layoutWidget = new QWidget(SenderOptions);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 400, 351, 48));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        lineSenderIP = new QLineEdit(SenderOptions);
        lineSenderIP->setObjectName(QStringLiteral("lineSenderIP"));
        lineSenderIP->setGeometry(QRect(300, 50, 491, 31));
        label = new QLabel(SenderOptions);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 50, 111, 25));
        lineSenderPacketSize = new QLineEdit(SenderOptions);
        lineSenderPacketSize->setObjectName(QStringLiteral("lineSenderPacketSize"));
        lineSenderPacketSize->setGeometry(QRect(300, 140, 491, 31));
        label_2 = new QLabel(SenderOptions);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 140, 131, 25));
        lineSenderNumPackets = new QLineEdit(SenderOptions);
        lineSenderNumPackets->setObjectName(QStringLiteral("lineSenderNumPackets"));
        lineSenderNumPackets->setGeometry(QRect(300, 220, 491, 31));
        label_3 = new QLabel(SenderOptions);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 210, 271, 51));
        lineSenderPort = new QLineEdit(SenderOptions);
        lineSenderPort->setObjectName(QStringLiteral("lineSenderPort"));
        lineSenderPort->setGeometry(QRect(300, 310, 491, 31));
        label_4 = new QLabel(SenderOptions);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 310, 89, 25));

        retranslateUi(SenderOptions);
        QObject::connect(okButton, SIGNAL(clicked()), SenderOptions, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SenderOptions, SLOT(reject()));

        QMetaObject::connectSlotsByName(SenderOptions);
    } // setupUi

    void retranslateUi(QDialog *SenderOptions)
    {
        SenderOptions->setWindowTitle(QApplication::translate("SenderOptions", "Dialog", Q_NULLPTR));
        okButton->setText(QApplication::translate("SenderOptions", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SenderOptions", "Cancel", Q_NULLPTR));
        lineSenderIP->setText(QString());
        label->setText(QApplication::translate("SenderOptions", "IP Address", Q_NULLPTR));
        lineSenderPacketSize->setText(QString());
        label_2->setText(QApplication::translate("SenderOptions", "Packet Size", Q_NULLPTR));
        lineSenderNumPackets->setText(QString());
        label_3->setText(QApplication::translate("SenderOptions", "# times to send each packet", Q_NULLPTR));
        lineSenderPort->setText(QString());
        label_4->setText(QApplication::translate("SenderOptions", "Port #", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SenderOptions: public Ui_SenderOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDEROPTIONS_H
