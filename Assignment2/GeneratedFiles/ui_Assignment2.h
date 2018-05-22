/********************************************************************************
** Form generated from reading UI file 'Assignment2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENT2_H
#define UI_ASSIGNMENT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignment2Class
{
public:
    QAction *senderTCP;
    QAction *senderUDP;
    QAction *receiverTCP;
    QAction *receiverUDP;
    QAction *action;
    QAction *actiona;
    QAction *selectOptions;
    QAction *selectFile;
    QAction *actionReset;
    QAction *createFile;
    QWidget *centralWidget;
    QPushButton *startButton;
    QPushButton *stopButton;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *sendTime;
    QLabel *label_3;
    QLabel *receiveTime;
    QLabel *label_2;
    QLabel *bytesTransferred;
    QMenuBar *menuBar;
    QMenu *menuSender;
    QMenu *menuReceiver;
    QMenu *menuOptions;
    QMenu *menuFile;
    QMenu *menuReset;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment2Class)
    {
        if (Assignment2Class->objectName().isEmpty())
            Assignment2Class->setObjectName(QStringLiteral("Assignment2Class"));
        Assignment2Class->resize(988, 400);
        senderTCP = new QAction(Assignment2Class);
        senderTCP->setObjectName(QStringLiteral("senderTCP"));
        senderTCP->setCheckable(false);
        senderUDP = new QAction(Assignment2Class);
        senderUDP->setObjectName(QStringLiteral("senderUDP"));
        receiverTCP = new QAction(Assignment2Class);
        receiverTCP->setObjectName(QStringLiteral("receiverTCP"));
        receiverUDP = new QAction(Assignment2Class);
        receiverUDP->setObjectName(QStringLiteral("receiverUDP"));
        action = new QAction(Assignment2Class);
        action->setObjectName(QStringLiteral("action"));
        actiona = new QAction(Assignment2Class);
        actiona->setObjectName(QStringLiteral("actiona"));
        selectOptions = new QAction(Assignment2Class);
        selectOptions->setObjectName(QStringLiteral("selectOptions"));
        selectFile = new QAction(Assignment2Class);
        selectFile->setObjectName(QStringLiteral("selectFile"));
        actionReset = new QAction(Assignment2Class);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        createFile = new QAction(Assignment2Class);
        createFile->setObjectName(QStringLiteral("createFile"));
        centralWidget = new QWidget(Assignment2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(300, 20, 150, 46));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(470, 20, 150, 46));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(90, 240, 791, 41));
        progressBar->setValue(24);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 190, 231, 51));
        sendTime = new QLabel(centralWidget);
        sendTime->setObjectName(QStringLiteral("sendTime"));
        sendTime->setGeometry(QRect(260, 200, 231, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(520, 190, 271, 41));
        receiveTime = new QLabel(centralWidget);
        receiveTime->setObjectName(QStringLiteral("receiveTime"));
        receiveTime->setGeometry(QRect(770, 200, 201, 25));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 130, 211, 21));
        bytesTransferred = new QLabel(centralWidget);
        bytesTransferred->setObjectName(QStringLiteral("bytesTransferred"));
        bytesTransferred->setGeometry(QRect(480, 130, 431, 25));
        Assignment2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Assignment2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 988, 38));
        menuSender = new QMenu(menuBar);
        menuSender->setObjectName(QStringLiteral("menuSender"));
        menuReceiver = new QMenu(menuBar);
        menuReceiver->setObjectName(QStringLiteral("menuReceiver"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuReset = new QMenu(menuBar);
        menuReset->setObjectName(QStringLiteral("menuReset"));
        Assignment2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Assignment2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Assignment2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Assignment2Class->setStatusBar(statusBar);

        menuBar->addAction(menuSender->menuAction());
        menuBar->addAction(menuReceiver->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuReset->menuAction());
        menuSender->addAction(senderTCP);
        menuSender->addAction(senderUDP);
        menuReceiver->addAction(receiverTCP);
        menuReceiver->addAction(receiverUDP);
        menuOptions->addAction(selectOptions);
        menuFile->addAction(selectFile);
        menuFile->addAction(createFile);
        menuReset->addAction(actionReset);

        retranslateUi(Assignment2Class);

        QMetaObject::connectSlotsByName(Assignment2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment2Class)
    {
        Assignment2Class->setWindowTitle(QApplication::translate("Assignment2Class", "Assignment2", Q_NULLPTR));
        senderTCP->setText(QApplication::translate("Assignment2Class", "TCP", Q_NULLPTR));
        senderUDP->setText(QApplication::translate("Assignment2Class", "UDP", Q_NULLPTR));
        receiverTCP->setText(QApplication::translate("Assignment2Class", "TCP", Q_NULLPTR));
        receiverUDP->setText(QApplication::translate("Assignment2Class", "UDP", Q_NULLPTR));
        action->setText(QApplication::translate("Assignment2Class", "a", Q_NULLPTR));
        actiona->setText(QApplication::translate("Assignment2Class", "a", Q_NULLPTR));
        selectOptions->setText(QApplication::translate("Assignment2Class", "Select Options", Q_NULLPTR));
        selectFile->setText(QApplication::translate("Assignment2Class", "Choose File to Send", Q_NULLPTR));
        actionReset->setText(QApplication::translate("Assignment2Class", "Reset", Q_NULLPTR));
        createFile->setText(QApplication::translate("Assignment2Class", "Make a file", Q_NULLPTR));
        startButton->setText(QApplication::translate("Assignment2Class", "Start", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Assignment2Class", "Stop", Q_NULLPTR));
        label->setText(QApplication::translate("Assignment2Class", "Time first packet sent:", Q_NULLPTR));
        sendTime->setText(QApplication::translate("Assignment2Class", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("Assignment2Class", "Time last packet received:", Q_NULLPTR));
        receiveTime->setText(QApplication::translate("Assignment2Class", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("Assignment2Class", "Bytes Sent/Received:", Q_NULLPTR));
        bytesTransferred->setText(QApplication::translate("Assignment2Class", "TextLabel", Q_NULLPTR));
        menuSender->setTitle(QApplication::translate("Assignment2Class", "Sender", Q_NULLPTR));
        menuReceiver->setTitle(QApplication::translate("Assignment2Class", "Receiver", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("Assignment2Class", "Options", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("Assignment2Class", "File", Q_NULLPTR));
        menuReset->setTitle(QApplication::translate("Assignment2Class", "Reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Assignment2Class: public Ui_Assignment2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT2_H
