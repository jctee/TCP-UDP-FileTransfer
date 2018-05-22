#include "SenderOptions.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: SenderOptions.cpp - Class for the GUI of the sender's options
--
-- PROGRAM: File Transfer
--
-- FUNCTIONS:
-- none
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
-- This class allows the user to specify the IP address of the Receiver and port number.
-- Also determines the packet size and the number of times to send each packet.
----------------------------------------------------------------------------------------------------------------------*/
SenderOptions::SenderOptions(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ip = ui.lineSenderIP;
	ip->setText("127.0.0.1");
	packetSize = ui.lineSenderPacketSize;
	packetSize->setText("10");
	numPackets = ui.lineSenderNumPackets;
	numPackets->setText("10");
	port = ui.lineSenderPort;
	port->setText("5150");
	
}
