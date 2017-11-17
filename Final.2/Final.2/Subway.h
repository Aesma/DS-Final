#ifndef SUBWAY_H
#define SUBWAY_H

#include "Graphmtx.h"

#include <QAxObject>

struct Node
{
	QString stop;
	QString path;
	int len = 0;
	bool isChange = false;
};

class Subway
{
public:
	Subway(QString path);
	Subway();
	void addVertice(QString s);
	void addEdge(QString v1, QString v2, int cost);
	void delVertice(QString s);
	void delEdge(QString v1, QString v2);
	QList<Node> getMinLenPlan(QString v1, QString v2);
	QStringList searchEdge(QString e);
	QStringList searchVertice(QString ver);
	~Subway();
private:
	void ShortestPath(Graphmtx& G, int v);
private:
	QString filePath;
	QAxObject *excel;
	Graphmtx *graph = NULL;
	Site *sites;
	int sheetCount;	
	int siteCount;
	int siteCounts;
	int *dist;
	int *path;
};

#endif