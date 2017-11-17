#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"
#include "listDialog.h"
#include "diskDialog.h"
#include "teamDialog.h"
#include "QCalculate.h"

class MyClass : public QMainWindow, public Ui::MyClassClass
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();
private slots:
	void doList();
	void doDisk();
	void doWood();
	void doSort();
protected:
	void dealButton();
private:
	ListDialog lDialog;
	DiskDialog dDialog;
	TeamDialog tDialog;
	Calculate wDialog;
};

#endif // MYCLASS_H
