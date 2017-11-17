#include "Graphmtx.h"

Graphmtx::Graphmtx(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	VerticesList = new int[maxVertices];
	Edge = new int*[maxVertices];
	for (int i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (int i = 0; i < maxVertices; i++)
	for (int j = 0; j < maxVertices; j++)
	{
		Edge[i][j] = (i == j) ? 0 : maxWeight;
	}
}

Graphmtx::Graphmtx(Graphmtx &g)
{
	maxVertices = g.maxVertices;
	numVertices = g.numVertices;
	numEdges = g.numEdges;
	VerticesList = new int[maxVertices];
	Edge = new int*[maxVertices];
	for (int i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (int i = 0; i < maxVertices; i++)
	{
		VerticesList[i] = g.VerticesList[i];
		for (int j = 0; j < maxVertices; j++)
			Edge[i][j] = g.Edge[i][j];
	}
}

int Graphmtx::getVertexPos(int vertex)
{
	for (int i = 0; i < numVertices; i++)
	if (VerticesList[i] == vertex)
		return i;
	return -1;
}

int Graphmtx::getFirstNeighbor(int v)
{
	if (v != -1){
		for (int col = 0; col < numVertices; col++)
		if (Edge[v][col]>0 && Edge[v][col] < maxWeight)
			return col;
	}
	return -1;
}

int Graphmtx::getNextNeighbor(int v, int w)
{
	if (v != -1 && w != -1){
		for (int col = w + 1; col < numVertices; col++)
		if (Edge[v][col]>0 && Edge[v][col] < maxWeight)
			return col;
	}
	return -1;
}

bool Graphmtx::insertVertex(const int& vertex)
{
	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}

bool Graphmtx::removeVertex(int v)
{
	if (v < 0 || v >= numVertices)
		return false;
	for (int i = v + 1; i < numVertices; i++)
		VerticesList[i - 1] = VerticesList[i];
	for (int i = 0; i < numVertices; i++)
	if (Edge[v][i]>0 && Edge[v][i] < maxWeight){
		numEdges--;
	}
	for (int i = v; i < numVertices; i++)
	for (int j = 0; j < numVertices; j++)
	{
		Edge[j][i] = Edge[j][i + 1];
	}
	for (int i = 0; i < numVertices; i++)
	for (int j = v; j < numVertices; j++)
	{
		Edge[j][i] = Edge[j + 1][i];
	}
	numVertices--;
	
	return true;
}

bool Graphmtx::insertEdge(int v1, int v2, int cost)
{
	if (v1>-1 && v1<numVertices&&v2>-1 && v2 < numVertices && Edge[v1][v2] == maxWeight){
		Edge[v1][v2] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
}

bool Graphmtx::removeEdge(int v1, int v2)
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2<numVertices&&Edge[v1][v2]>0 && Edge[v1][v2] < maxWeight){
		Edge[v1][v2] = maxWeight;
		numEdges--;
		return true;
	}
	return false;
}

Graphmtx::~Graphmtx()
{
	delete[]VerticesList;
	for (int i = 0; i < maxVertices; i++)
		delete[]Edge[i];
	delete[]Edge;
}
