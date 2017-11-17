#include "myclass.h"

MyClass::MyClass(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	dealButton();
}

void MyClass::dealButton()
{
	connect(listButton, SIGNAL(clicked()), this, SLOT(doList()));
	connect(diskButton, SIGNAL(clicked()), this, SLOT(doDisk()));
	connect(teamButton, SIGNAL(clicked()), this, SLOT(doSort()));
	connect(woodButton, SIGNAL(clicked()), this, SLOT(doWood()));
}

void MyClass::doList()
{
	lDialog.show();
}

void MyClass::doDisk()
{
	dDialog.show();
}

void MyClass::doSort()
{
	tDialog.show();
}

void MyClass::doWood()
{
	wDialog.show();
}

MyClass::~MyClass()
{

}
