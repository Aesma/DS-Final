#include "IndexThread.h"

IndexThread::IndexThread()
{

}

void IndexThread::run()
{
	app.getIndex();
	emit finshGet();
}

Everything IndexThread::getApp()
{
	return app;
}

IndexThread::~IndexThread()
{

}