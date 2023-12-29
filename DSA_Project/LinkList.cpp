#include <iostream>
#include "LinkList.h"
using namespace std;

LinkList::LinkList()
{
	this->head = nullptr;
}

void LinkList::Insert(int r, int c)
{
	Node* n = new Node;
	if (n != nullptr) {
		n->row = r;
		n->col = c;
		if (head == nullptr) {
			head = n;
		}
		else {
			Node* t = head;
			while (t->next != nullptr) {
				t = t->next;
			}
			t->next = n;
		}
	}
}

bool LinkList::listcheck(int r, int c)
{
	Node* t = head;
	while (t != nullptr) {
		if (t->row == r && t->col == c) {
			return false;
		}
		t = t->next;
	}
	return true;
}

void LinkList::Display()
{
	Node* t = this->head;
	while (t != nullptr) {
		cout << "Row: " << t->row << " ";
		cout << "Col: " << t->col << endl;
		t = t->next;
	}
	cout << endl;
}

