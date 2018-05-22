#include "ReceiverOptions.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: Receiveroptions.cpp - Class for the GUI of the receiver's options
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
-- This class allows the user to specify the IP address of the Sender and port number.
----------------------------------------------------------------------------------------------------------------------*/
ReceiverOptions::ReceiverOptions(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ip = ui.lineReceiverIP;
	ip->setText("127.0.0.1");
	port = ui.lineReceiverPort;
	port->setText("5150");

}