#ifndef GRAPHMTX_H
#define GRAPHMTX_H

#include "QtHead.h"

const int maxWeight = INT_MAX;
const int DefaultVertices = 30;

struct Site
{
	QString name;
	QStringList path;
	bool isChange;
	Site() :isChange(false){};
	Site(Site&s)
	{
		name = s.name;
		path = s.path;
		isChange = s.isChange;
	}
	bool operator == (Site&s)
	{
		if (name == s.name)
			return true;
		return false;
	}
};

class Graphmtx
{
public:
	Graphmtx(int sz = DefaultVertices);
	bool GraphEmpty()const{ if (numVertices == 0)return true; return false; };
	bool GraphFull()const{ if (numVertices == maxVertices || numEdges == maxVertices*(maxVertices - 1) / 2)return true; return false; }
	int NumberOfVertices(){ return numVertices; };
	int NumberOfEdges(){ return numEdges; };
	Site getValue(int i);
	int getWeight(int v1, int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	int getVertexPos(QString vertex);
	bool insertVertex(const Site&vertex);
	bool insertEdge(int v1, int v2, int cost);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
	~Graphmtx();
private:
	int maxVertices;
	int numEdges;
	int numVertices;
	int **Edge;
	Site *VerticesList;
};

#endif