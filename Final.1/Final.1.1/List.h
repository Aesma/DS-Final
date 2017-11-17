#ifndef LIST_H
#define LIST_H

#include "QtHead.h"

struct Node
{
	char data;
	Node *next;
	Node *random;
	Node(Node*p1 = nullptr, Node*p2 = nullptr){ next = p1; random = p2; };
	Node(const char item, Node*p1 = nullptr, Node*p2 = nullptr){ data = item; next = p1; random = p2; };
};

class List
{
public:
	List();
	List(List&L);
	void makeEmpty();
	bool Insert(int i, char x);
	bool IsEmpty(){ return first == nullptr ? true : false; };
	bool Link(int x,int y);
	Node *Locate(int i,Node *p);
	Node *Copy();
	~List();
private:
	Node* Copy(Node*p);
	Node* copyNext(Node*p);
	void copyRandom(Node *p,Node *&temp);
	int Search(char x);
private:
	Node *first;
	Node *copyNode;
};

#endif