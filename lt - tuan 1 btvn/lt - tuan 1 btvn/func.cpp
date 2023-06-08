#include <iostream>
#include "func.h"
using namespace std;

void initList(List &l) {
	l.head = l.tail = NULL;
}

Node* createNode(int data) {
	Node*a = new Node;
	a->data = data;
	a->next = NULL;
	return a;
}

void inserttail(List &l, int data) {
	Node*a = createNode(data);
	if (l.head==NULL && l.tail==NULL)
	{
		l.head = l.tail = a;
		return;
	}
	l.tail->next = a;
	l.tail = a;
}

void createlist(List&l, int n) {
	initList(l);
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri cua node thu " << i + 1 << ": ";
		cin >> x;
		inserttail(l, x);
	}
}
