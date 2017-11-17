#ifndef PUSHBOX_H
#define PUSHBOX_H

#include "QtHead.h"
#include "qt_windows.h"

#include <Queue>
#include <QList>
#include <stack>

struct Node
{
	int x;
	int y;
	Node(){};
	Node(Node const &n)
	{
		x = n.x;
		y = n.y;
	}
	QList<Node>boxDirect(bool **r, int w, int h)
	{
		QList<Node>pushDirect;
		Node n;
		if (x > 0 && x < w - 1 && y>0 && y < h - 1){
			if (r[x - 1][y]){
				n.x = x + 1;
				n.y = y;
				pushDirect.append(n);
			}
			if (r[x][y - 1]){
				n.x = x;
				n.y = y + 1;
				pushDirect.append(n);
			}
			if (r[x + 1][y]){
				n.x = x - 1;
				n.y = y;
				pushDirect.append(n);
			}
			if (r[x][y + 1]){
				n.x = x;
				n.y = y - 1;
				pushDirect.append(n);
			}
		}
		else if (x == 0 || x == w - 1){
			if (y > 0 && y < h - 1){
				if (r[x][y + 1]){
					n.x = x;
					n.y = y - 1;
					pushDirect.append(n);
				}
				if (r[x][y - 1]){
					n.x = x;
					n.y = y + 1;
					pushDirect.append(n);
				}
			}
		}
		else if (y == 0 || y == h - 1){
			if (x > 0 && x < w - 1){
				if (r[x + 1][y]){
					n.x = x - 1;
					n.y = y;
					pushDirect.append(n);
				}
				if (r[x - 1][y]){
					n.x = x + 1;
					n.y = y;
					pushDirect.append(n);
				}
			}
		}
		return pushDirect;
	}
	Node operator + (Node&n)
	{
		Node node;
		node.x = x;
		node.y = y;
		if (n.x > x)
			node.x += 1;
		if (n.y > y)
			node.y += 1;
		if (n.x < x)
			node.x -= 1;
		if (n.y < y)
			node.y -= 1;
		return node;
	}
};

class PushBox
{
public:
	PushBox(int w, int h, bool **r, Node b, Node m, Node e);
	Node getBox();
	Node getMan();
	void changeDirect(int i);
	bool getResult();
	bool Auto();
	~PushBox();
protected:
	bool judge();
	void move();
	bool calBoxBfs(Node st, Node en);
	bool calManBfs(Node st, Node en);
	void calBoxQue(Node en);
	void calManQue(Node en);
private:
	int mapW;
	int mapH;
	int director;
	bool isWin;
	Node box;
	Node man;
	Node end;
	bool **isRood;
	queue<Node>manQue;
	queue<Node>boxQue;
	Node**manParent;
	Node**boxParent;
};

#endif