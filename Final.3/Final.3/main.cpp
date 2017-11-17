#include "myclass.h"
#include <QtWidgets/QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyClass w;
	w.show();
	return a.exec();
}
