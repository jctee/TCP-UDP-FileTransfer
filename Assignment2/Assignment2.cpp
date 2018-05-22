#include "Assignment2.h"

/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: Assignment2.cpp - An application that will transfer files to this same application on a different machine
-- through sockets.
--
-- PROGRAM: File Transfer
--
-- FUNCTIONS:
-- void addButtons();
-- void senderTCP();
-- void senderUDP();
-- void receiverTCP();
-- void receiverUDP();
-- void selectOptions();
-- void filePicker();
-- void fileSaver();
-- void resetMenu();
-- void start();
-- void stop();
-- std::ifstream::pos_type filesize(const char* filename);
-- SLOTS:
-- void readyRead();
-- void newConnection();
--
-- DATE: Februrary 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- NOTES:
-- The program will transfer files from sender to receiver. The sender and receiver must both agree on a protocol, either
-- TCP OR UDP. After exhcanging host information, the sender also specifies the packet size and number of times they would
-- like to send each packet and the file. The receiver will start first, listening to any incoming connections. Then the sender
-- will press their start button and file transfer should occur between the 2 machines.
----------------------------------------------------------------------------------------------------------------------*/
Assignment2::Assignment2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	qDebug("Starting Program");
	addButtons();
	soption = new SenderOptions();
	roption = new ReceiverOptions();
	totalSize = 0;

	ui.menuOptions->setEnabled(false);
	ui.menuFile->setEnabled(false);
	ui.selectFile->setEnabled(false);
	ui.createFile->setEnabled(false);
	ui.startButton->setEnabled(false);
	ui.stopButton->setEnabled(false);
	ui.progressBar->setValue(0);
	ui.sendTime->setText("unknown");
	ui.receiveTime->setText("unknown");
	ui.bytesTransferred->setText("calculating...");
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: addButtons
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void addButtons()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to add all the slots and signals to the buttons of the GUI.
----------------------------------------------------------------------------------------------------------------------*/
inline void Assignment2::addButtons()
{
	connect(ui.senderTCP, &QAction::triggered, this, &Assignment2::senderTCP);
	connect(ui.senderUDP, &QAction::triggered, this, &Assignment2::senderUDP);
	connect(ui.receiverTCP, &QAction::triggered, this, &Assignment2::receiverTCP);
	connect(ui.receiverUDP, &QAction::triggered, this, &Assignment2::receiverUDP);
	connect(ui.selectOptions, &QAction::triggered, this, &Assignment2::selectOptions);
	connect(ui.selectFile, &QAction::triggered, this, &Assignment2::filePicker);
	connect(ui.createFile, &QAction::triggered, this, &Assignment2::fileSaver);
	connect(ui.actionReset, &QAction::triggered, this, &Assignment2::resetMenu);
	connect(ui.startButton, &QPushButton::clicked, this, &Assignment2::start);
	connect(ui.stopButton, &QPushButton::clicked, this, &Assignment2::stop);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: senderTCP
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void senderTCP()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to change the settings to sender/TCP.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::senderTCP()
{
	sender = 1;
	tcp = 1;
	ui.menuSender->setEnabled(false);
	ui.menuReceiver->setEnabled(false);
	ui.menuOptions->setEnabled(true);
	ui.menuFile->setEnabled(true);
	ui.selectFile->setEnabled(true);
	ui.progressBar->setValue(0);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: senderUDP
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void senderUDP()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to change the settings to sender/UDP.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::senderUDP()
{
	sender = 1;
	udp = 1;
	ui.menuSender->setEnabled(false);
	ui.menuReceiver->setEnabled(false);
	ui.menuOptions->setEnabled(true);
	ui.menuFile->setEnabled(true);
	ui.selectFile->setEnabled(true);
	ui.progressBar->setValue(0);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: receiverTCP
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void receiverTCP()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to change the settings to receiver/TCP.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::receiverTCP()
{
	receiver = 1;
	tcp = 1;
	ui.menuSender->setEnabled(false);
	ui.menuReceiver->setEnabled(false);
	ui.menuOptions->setEnabled(true);
	ui.menuFile->setEnabled(true);
	ui.createFile->setEnabled(true);
	ui.progressBar->setValue(0);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: receiverUDP
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void receiverUDP()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to change the settings to receiver/UDP.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::receiverUDP()
{
	receiver = 1;
	udp = 1;
	ui.menuSender->setEnabled(false);
	ui.menuReceiver->setEnabled(false);
	ui.menuOptions->setEnabled(true);
	ui.menuFile->setEnabled(true);
	ui.createFile->setEnabled(true);
	ui.progressBar->setValue(0);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: selectOptions
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void selectOptions()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to open the window to change the settings.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::selectOptions()
{
	if (sender == 1)
	{
		soption->show();
	}

	if (receiver == 1)
	{
		roption->show();
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: filePicker
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void filePicker()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to open the file specified by the user.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::filePicker()
{
	fileName = QFileDialog::getOpenFileName(this,
		tr("Choose File to Send"), "./", tr("Text File (*.txt)"));

	totalSize = filesize(fileName.toStdString().c_str());
	inputFile.open(fileName.toStdString());
	ui.startButton->setEnabled(true);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: fileSaver
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void fileSaver()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to let the user create a file to write to.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::fileSaver()
{
	fileName = QFileDialog::getSaveFileName(this, tr(""), "", tr("Text file(*.txt"));
	outputFile.open(fileName.toStdString());
	ui.startButton->setEnabled(true);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: resetMenu
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void resetMenu()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to reset the Menu
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::resetMenu()
{
	sender = 0;
	receiver = 0;
	tcp = 0;
	udp = 0;
	totalSize = 0;
	ui.menuSender->setEnabled(true);
	ui.menuReceiver->setEnabled(true);
	ui.menuOptions->setEnabled(false);
	ui.menuFile->setEnabled(false);
	ui.selectFile->setEnabled(false);
	ui.createFile->setEnabled(false);

}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: start
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void start()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to either:
--		as receiver - make a socket, listen for incoming connections/messages
--		as sender - start sending a file.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::start()
{
	ui.startButton->setEnabled(false);
	ui.stopButton->setEnabled(true);

	if (receiver == 1)
	{
		if (tcp == 1)
		{
			server = new QTcpServer(this);

			// whenever a user connects, it will emit signal
			connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

			int portNum = roption->port->displayText().toInt();

			if (!server->listen(QHostAddress::Any, portNum))
			{
				qDebug() << "Server could not start";
			}
			else
			{
				qDebug() << "Server started!";
			}
		}
		else if (udp == 1)
		{

			QString ip = roption->ip->displayText();
			int portNum = roption->port->displayText().toInt();

			udpSocket = new QUdpSocket(this);
			udpSocket->bind(QHostAddress::Any, portNum);
			connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

		}
	}
	else if (sender == 1)
	{

		if (tcp == 1)
		{
			tcpSocket = new QTcpSocket(this);
			QString ip = soption->ip->displayText();
			int packetSize = soption->packetSize->displayText().toInt();
			int portNum = soption->port->displayText().toInt();
			double currSize = 0;
			double tempTotalSize = totalSize*soption->numPackets->displayText().toInt();
			int numPackets = soption->numPackets->displayText().toInt();
			tcpSocket->connectToHost(QHostAddress::QHostAddress(ip), portNum);
			QTime start = QTime::currentTime();
			ui.sendTime->setText((QString)start.toString("hh:mm:ss.zzz"));
			char buffer[8192];
			memset(buffer, '\0', packetSize + 1);
			while (!inputFile.eof())
			{
				inputFile.read(buffer, packetSize);
				for (int i = 0; i < numPackets; i++)
				{
					currSize += tcpSocket->write(buffer);
					ui.progressBar->setValue(currSize/totalSize*100);
				}
				memset(buffer, '\0', packetSize + 1);
			}
			ui.progressBar->setValue(100);
			tcpSocket->disconnectFromHost();
			stop();
		}
		else if (udp == 1)
		{

			udpSocket = new QUdpSocket(this);
			char buffer[64000];

			QString ip = soption->ip->displayText();

			int packetSize = soption->packetSize->displayText().toInt();
			int portNum = soption->port->displayText().toInt();
			double currSize = 0;
			double tempTotalSize = totalSize*soption->numPackets->displayText().toInt();
			memset(buffer, '\0', packetSize+1);
			int numPackets = soption->numPackets->displayText().toInt();
			QTime start = QTime::currentTime();
			ui.sendTime->setText((QString)start.toString("hh:mm:ss.zzz"));
			while (!inputFile.eof())
			{
				inputFile.read(buffer, packetSize);
				for (int i = 0; i < numPackets; i++)
				{
					currSize = udpSocket->writeDatagram(buffer, QHostAddress::QHostAddress(ip), portNum);

					ui.progressBar->setValue(currSize / tempTotalSize * 100);
				}
				memset(buffer, '\0', packetSize + 1);
			}
			ui.progressBar->setValue(100);
			for (int i = 0; i < 10; i++)
			{
				udpSocket->writeDatagram("", QHostAddress::QHostAddress(ip), portNum);
			}
			stop();
		}
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: readyReady
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void readyRead()
--
-- RETURNS: void.
--
-- NOTES:
-- Attach this function as a SLOT, to always get called by the receiver to read messages.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::readyRead()
{
	if (tcp == 1)
	{
		outputFile << tcpSocket->readAll().toStdString();
	}
	if (udp == 1)
	{
		QByteArray buffer;
		buffer.resize(udpSocket->pendingDatagramSize());

		QHostAddress sender;
		quint16 senderPort;
		int currSize;
		currSize = udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
		outputFile << buffer.toStdString();
		if (currSize == 0)
		{
			stop();
		}
	}
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: stop
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void stop()
--
-- RETURNS: void.
--
-- NOTES:
-- Call this function to manually stop transmission in case of emergencies.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::stop()
{
	ui.stopButton->setEnabled(false);

	if (receiver == 1)
	{
		if (tcp == 1)
		{
			QTime end = QTime::currentTime();
			ui.receiveTime->setText((QString)end.toString("hh:mm:ss.zzz"));
			ui.progressBar->setValue(100);
			outputFile.close();
			totalSize = filesize(fileName.toStdString().c_str());
			ui.bytesTransferred->setText(QString::number(totalSize));
			tcpSocket->disconnectFromHost();
			server = NULL;
		}
		else if (udp == 1)
		{
			QTime end = QTime::currentTime();
			ui.receiveTime->setText((QString)end.toString("hh:mm:ss.zzz"));
			ui.progressBar->setValue(100);
			outputFile.close();
			totalSize = filesize(fileName.toStdString().c_str());
			ui.bytesTransferred->setText(QString::number(totalSize));
		}
	}
	else if (sender == 1)
	{
		if (tcp == 1)
		{
			inputFile.close();
			tcpSocket->disconnectFromHost();
			ui.bytesTransferred->setText(QString::number(totalSize*soption->numPackets->displayText().toInt()));
		}
		else if (udp == 1)
		{
			inputFile.close();
			udpSocket->disconnectFromHost();
			ui.bytesTransferred->setText(QString::number(totalSize*soption->numPackets->displayText().toInt()));
		}
	}
	resetMenu();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: newConnection
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void newConnection()
--
-- RETURNS: void.
--
-- NOTES:
-- Attach this function as a SLOT, and get called when a connection is detected by the QTcpServer.
-- This function will bind that connection to a socket and process it.
----------------------------------------------------------------------------------------------------------------------*/
void Assignment2::newConnection()
{
	tcpSocket = server->nextPendingConnection();
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(tcpSocket, &QTcpSocket::disconnected, this, &Assignment2::stop);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: filesize
--
-- DATE: February 14 2018
--
-- REVISIONS: None
--
-- DESIGNER: John Tee
--
-- PROGRAMMER: John Tee
--
-- INTERFACE: void filesize(const char* filename)
--
-- RETURNS: std::ifstream::pos_type - position of the very end of the file (size of the file).
--
-- NOTES:
-- Call this function to determine the size of the file passed in.
----------------------------------------------------------------------------------------------------------------------*/
std::ifstream::pos_type Assignment2::filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}
