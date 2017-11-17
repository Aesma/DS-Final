#ifndef EVERYTHING_H
#define EVERYTHING_H

#include "QtHead.h"
#include <QDir>
#include <QVector>

struct fileNode
{
	QString fileName;
	QString filePath;
	int fileSize;
};

class Everything
{
public:
	Everything();
	void creatIndex();
	void getIndex();
	void search(QString name);
	void clearResult();
	QVector<fileNode> getResult();
	~Everything();
private:
	bool findFile(QString path);
private:
	QFile *file;
	QVector<fileNode>fileV;
	QVector<fileNode>result;
};

#endif