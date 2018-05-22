/********************************************************************************
** Form generated from reading UI file 'ReceiverOptions.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEROPTIONS_H
#define UI_RECEIVEROPTIONS_H

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

class Ui_ReceiverOptions
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_5;
    QLineEdit *lineReceiverIP;
    QLabel *label_6;
    QLineEdit *lineReceiverPort;

    void setupUi(QDialog *ReceiverOptions)
    {
        if (ReceiverOptions->objectName().isEmpty())
            ReceiverOptions->setObjectName(QStringLiteral("ReceiverOptions"));
        ReceiverOptions->resize(846, 320);
        layoutWidget = new QWidget(ReceiverOptions);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 200, 351, 48));
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

        label_5 = new QLabel(ReceiverOptions);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 50, 111, 25));
        lineReceiverIP = new QLineEdit(ReceiverOptions);
        lineReceiverIP->setObjectName(QStringLiteral("lineReceiverIP"));
        lineReceiverIP->setGeometry(QRect(290, 50, 491, 31));
        label_6 = new QLabel(ReceiverOptions);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 120, 89, 25));
        lineReceiverPort = new QLineEdit(ReceiverOptions);
        lineReceiverPort->setObjectName(QStringLiteral("lineReceiverPort"));
        lineReceiverPort->setGeometry(QRect(290, 120, 491, 31));

        retranslateUi(ReceiverOptions);
        QObject::connect(okButton, SIGNAL(clicked()), ReceiverOptions, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), ReceiverOptions, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReceiverOptions);
    } // setupUi

    void retranslateUi(QDialog *ReceiverOptions)
    {
        ReceiverOptions->setWindowTitle(QApplication::translate("ReceiverOptions", "Dialog", Q_NULLPTR));
        okButton->setText(QApplication::translate("ReceiverOptions", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ReceiverOptions", "Cancel", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReceiverOptions", "IP Address", Q_NULLPTR));
        lineReceiverIP->setText(QString());
        label_6->setText(QApplication::translate("ReceiverOptions", "Port #", Q_NULLPTR));
        lineReceiverPort->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReceiverOptions: public Ui_ReceiverOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEROPTIONS_H
