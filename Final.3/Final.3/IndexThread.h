#ifndef INDEXTHREAD_H
#define INDEXTHREAD_H

#include "QtHead.h"
#include "Everything.h"

#include <QThread>

class IndexThread:public QThread
{
	Q_OBJECT
public:
	IndexThread();
	Everything getApp();
	~IndexThread();
protected:
	void run();
signals:
	void finshGet();
private:
	Everything app;
};

#endif