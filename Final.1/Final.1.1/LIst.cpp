#include "List.h"

List::List()
{
	first = new Node;
	copyNode = new Node;
}

List::List(List&L)
{

}

Node* List::Locate(int i,Node *p)
{
	if (i < 0)return NULL;
	Node*current = p;
	int k = 0;
	while (current != NULL&&k < i){
		current = current->next;
		k++;
	}
	return current;
}

bool List::Insert(int i, char x)
{
	Node *current = Locate(i,first);
	if (current == nullptr)return false;
	Node* newNode = new Node(x);
	newNode->next = current->next;
	current->next = newNode;

	return true;
}

bool List::Link(int x, int y)
{
	Node *temp1 = Locate(x + 1, first);
	Node *temp2 = Locate(y + 1, first);
	temp1->random = temp2;

	return true;
}

Node* List::Copy()
{
	Node *temp;
	temp = Copy(first);

	return temp;
}

Node *List::Copy(Node *p)
{
	if (p == nullptr)
		return nullptr;
	copyNode = copyNext(p);
	Node*temp = p;
	Node*temp2 = copyNode;
	while (temp != nullptr){
		copyRandom(temp->random, temp2->random);
		temp = temp->next;
		temp2 = temp2->next;
	}

	delete temp2;
	copyNode = copyNode->next;
	return copyNode;
}

Node *List::copyNext(Node *p)
{
	if (p == nullptr)
		return nullptr;
	Node*temp = new Node;
	temp->data = p->data;
	temp->next = copyNext(p->next);

	return temp;
}

void List::copyRandom(Node*p,Node*&temp)
{
	if (p == nullptr){
		temp = nullptr;
		return;
	}
	int i = Search(p->data);
	Node *temp2 = Locate(i, copyNode);
	temp = temp2;
}

int List::Search(char x)
{
	Node*current = first;
	int temp = 0;
	while (current != nullptr){
		if (current->data == x)
			break;
		else{
			current = current->next;
			temp++;
		}
	}
	return temp;
}

void List::makeEmpty()
{
	Node*q;
	while (first->next != nullptr){
		q = first->next;
		first->next = q->next;
		delete q;
	}
	while (copyNode != nullptr&&copyNode->next != nullptr){
		q = copyNode->next;
		copyNode->next = q->next;
		delete q;
	}
}

List::~List()
{
	makeEmpty();
}