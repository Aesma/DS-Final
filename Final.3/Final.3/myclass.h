#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "WorkThread.h"
#include "IndexThread.h"
#include "ui_myclass.h"

class MyClass : public QMainWindow,public Ui::MyClassClass
{
	Q_OBJECT
	
public:
	MyClass(QWidget *parent = 0);
	~MyClass();
private:
	void creatMenu();
	void getIndex();
	void creadTableWidget();
protected:
	void paintEvent(QPaintEvent *event);
public slots:
	void search();
	void creatIndex();
	void help();
	void about();
	void getApp();
	void showResult();
	void customMenuRequested(QPoint pos);
	void openFile();
	void openPath();
	void Copy();
signals:
	void showResultSignal();
	void getAppSignal();
private:
	WorkThread *workThread;//����ǲ����߳�
	IndexThread *indexThread;//��������������ļ�������µ��߳�- -
	Everything app;
	bool isIn;
	bool needIn;
};

#endif // MYCLASS_H
