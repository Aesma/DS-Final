#include "WorkThread.h"

WorkThread::WorkThread(QObject *parent)
:QThread(parent)
{

}

void WorkThread::setWork(QString name, Everything app)
{
	fileName = name;
	application = app;
}

void WorkThread::run()
{
	application.search(fileName);
	result = application.getResult();

	emit searchFinsh();
}

QVector<fileNode>WorkThread::getResult()
{
	return result;
}

WorkThread::~WorkThread()
{

}