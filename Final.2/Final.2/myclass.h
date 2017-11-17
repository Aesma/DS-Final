#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include <QAxObject>
#include <QFileDialog>

#include "ui_myclass.h"
#include "MyView.h"
#include "MyItem.h"
#include "Subway.h"

class MyClass : public QMainWindow,public Ui_MyClassClass
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();
protected:
	void paintEvent(QPaintEvent *event);
	void dealCtr();
	void getMap();
private slots:
	void setMap();
	void addVertice();
	void delVertice();
	void addEdge();
	void delEdge();
	void seaEdge();
	void seaVertice();
	void minLengthSingal();
	void minChangeSignal();
	void search();
	void outData();
private:
	Subway *sub;
	MyView *mapView;
	MyItem *mapItem;
	QGraphicsScene *scene;
	QString filePath;
	int mark;
	bool needIn;
};

#endif // MYCLASS_H
