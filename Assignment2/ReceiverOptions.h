#pragma once

#include <QDialog>
#include <QLineEdit>

#include "ui_ReceiverOptions.h"

class ReceiverOptions : public QDialog
{
	Q_OBJECT

public:
	ReceiverOptions(QDialog *parent = 0);
	QLineEdit *ip;
	QLineEdit *port;


private:
	Ui::ReceiverOptions ui;

};