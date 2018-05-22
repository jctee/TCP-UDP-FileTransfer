#pragma once
#include <QtWidgets/QMainWindow>
#include <QFiledialog>
#include <iostream>
#include <fstream> 
#include <QDebug>
#include <QtNetwork>
#include <iostream>
#include <fstream>
#include <QProgressBar>
#include <QTime>


#include "ui_Assignment2.h"
#include "SenderOptions.h"
#include "ReceiverOptions.h"


class Assignment2 : public QMainWindow
{
	Q_OBJECT

public:
	Assignment2(QWidget *parent = Q_NULLPTR);

	bool tcp;
	bool udp;
	bool sender;
	bool receiver;
	QString fileName;
	std::ifstream inputFile;
	std::ofstream outputFile;
	int totalSize;

	QUdpSocket *udpSocket;
	QTcpServer *server;
	QTcpSocket *tcpSocket;


	void addButtons();
	void senderTCP();
	void senderUDP();
	void receiverTCP();
	void receiverUDP();
	void selectOptions();
	void filePicker();
	void fileSaver();
	void resetMenu();
	void start();
	void stop();
	std::ifstream::pos_type filesize(const char* filename);


public slots:
	void readyRead();
	void newConnection();
	


private:
	Ui::Assignment2Class ui;
	SenderOptions *soption;
	ReceiverOptions *roption;

};

