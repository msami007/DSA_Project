#pragma once
#include"Node.h"
class LinkList
{
public:
	Node* head;
	LinkList();
	void Insert(int, int);
	bool listcheck(int, int);
	void Display();
};

