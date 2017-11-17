#ifndef TEAM_H
#define TEAM_H

#include "QtHead.h"
#include "Graphmtx.h"
#include <Queue>

class TeamClass
{
public:
	TeamClass(QString path);
	void tSort();
	void outCount();
	~TeamClass();
private:
	void TopologicalSort(Graphmtx g, QByteArray nodes);
private:
	QString filePath;
	QFile file;
	QFile outFile;
	Graphmtx graph;
	int N;	
	int M;
	int count;
};

#endif