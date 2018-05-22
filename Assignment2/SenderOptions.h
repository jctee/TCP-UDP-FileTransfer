#pragma once

#include <QDialog>
#include <QLineEdit>

#include "ui_SenderOptions.h"

class SenderOptions : public QDialog
{
	Q_OBJECT

public:
	SenderOptions(QDialog *parent = 0);

	QLineEdit *ip;
	QLineEdit *packetSize;
	QLineEdit *numPackets;
	QLineEdit *port;


private:
	Ui::SenderOptions ui;

};