#ifndef GRAPHMTX_H
#define GRAPHMTX_H

#include "QtHead.h"

const int maxWeight = INT_MAX;

#define DefaultVertices 30

class Graphmtx
{
public:
	Graphmtx(int sz = DefaultVertices);
	Graphmtx(Graphmtx &g);
	bool GraphEmpty()const{
		if (numVertices == 0)return true;
		return false;
	}
	bool GraphFull()const{
		if (numVertices == maxVertices || numEdges == maxVertices*(maxVertices - 1) / 2)
			return true;
		return false;
	}
	int NumberOfVertices(){ return numVertices; };
	int NumberOfEdges(){ return numEdges; };
	int getValue(int i){ return i >= 0 && i <= numVertices ? VerticesList[i] : NULL; };
	int getWeight(int v1, int v2){ return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0; };
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	bool insertVertex(const int&vertex);
	bool insertEdge(int v1, int v2, int cost);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
	~Graphmtx();
private:
	int *VerticesList;
	int **Edge;
	int maxVertices;
	int numEdges;
	int numVertices;
	int getVertexPos(int vertex);
};

#endif
