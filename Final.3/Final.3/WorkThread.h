#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include "Everything.h"
#include "qt_windows.h"
#include "windows.h"

class WorkThread :public QThread
{
	Q_OBJECT
public:
	explicit WorkThread(QObject *parent = 0);
	void setWork(QString name, Everything app);
	QVector<fileNode>getResult();
	~WorkThread();
protected:
	void run()Q_DECL_OVERRIDE;
signals:
	void searchFinsh();
private:
	QString fileName;
	Everything search;
	QVector<fileNode>result;
	Everything application;
};

#endif