#include <iostream>
#include "func.h"
using namespace std;

NODE* createNode(int data) {
	NODE*a = new NODE;
	a->key = data;
	a->pNext = NULL;

	return a;
}
List* createList(NODE* pNode) {
	List*l = new List;
	l->pHead = l->pTail = pNode;
	return l;
}
bool addHead(List* &L, int data) {

	if (L->pHead == NULL && L->pTail == NULL)
		return false;
	NODE*p = createNode(data);
	p->pNext = L->pHead;
	L->pHead = p;
	return true;
}

bool addTail(List* &L, int data) {

	if (L->pHead == NULL && L->pTail == NULL)
		return false;
	NODE*p = createNode(data);
	L->pTail->pNext = p;
	L->pTail = p;
	return true;
}
void removeHead(List* &L) {
	if (L->pHead == NULL && L->pTail == NULL)
		return;
	if (L->pHead == L->pTail)
	{
		delete L->pHead;
		L->pHead = L->pTail = NULL;
		return;
	}
	NODE*temp2 = L->pHead;
	L->pHead = L->pHead->pNext;
	delete temp2;
}
void removeTail(List* &L) {
	if (L->pHead == NULL && L->pTail == NULL)
		return;
	if (L->pHead == L->pTail)
	{
		delete L->pHead;
		L->pHead = L->pTail = NULL;
		return;
	}
	NODE*count = L->pHead;
	while (count->pNext != L->pTail)
		count = count->pNext;
	count->pNext = NULL;
	delete L->pTail;
	L->pTail = count;
}
void removeAll(List* &L) {
	NODE*count = L->pHead;
	NODE*temp = count;
	L->pHead = L->pTail = NULL;

	while (count != NULL)
	{
		count = count->pNext;
		delete temp;
		temp = count;
	}
}
void removeBefore(List* L, int val) {

	//neu val o node head
	NODE*count = L->pHead;
	if (count->key == val)
		return;

	//neu val o node ke tiep head
	if (count->pNext->key == val)
	{
		removeHead(L);
		return;
	}

	//truong hop con lai
	while (count->pNext->pNext != NULL)
	{
		if (count->pNext->pNext->key != val)
			count = count->pNext;
		else
			break;
	}

	if (count->pNext->pNext == NULL)
		return;

	NODE*temp = count->pNext;
	count->pNext = count->pNext->pNext;

	delete temp;
}

void removeAfter(List* L, int val) {
	//neu val o node tail
	NODE*check = L->pTail;
	if (check->key == val)
		return;

	NODE*count = L->pHead;
	while (count != NULL)
	{
		if (count->key != val)
			count = count->pNext;
		else
			break;
	}
	if (count == NULL)
		return;

	//neu val o ke node tail
	if (count->pNext == L->pTail)
	{
		removeTail(L);
		return;
	}

	NODE*temp = count->pNext;
	count->pNext = count->pNext->pNext;
	delete temp;
}

bool addPos(List* &L, int data, int pos) { //pos bat dau tinh tu 0
	if (pos < 0)
		return false;

	if (pos == 0)
	{
		addHead(L, data);
		return true;
	}

	NODE*count = L->pHead;
	int num = 1;
	while (count->pNext != NULL)
	{
		count = count->pNext;
		num++;
	}

	if (pos == (num))
	{
		addTail(L, data);
		return true;
	}

	if (pos > num)
		return false;

	count = L->pHead;

	for (int i = 1; i != pos; i++)
		count = count->pNext;

	NODE*p = createNode(data);
	p->pNext = count->pNext;
	count->pNext = p;
	return true;

}

void removePos(List* &L, int pos) { //pos bat dau tinh tu 0

	if (pos < 0)
		return;

	NODE*count = L->pHead;
	int maxpos = 0;
	while (count->pNext != NULL)
	{
		count = count->pNext;
		maxpos++;
	}

	if (pos == 0)
	{
		removeHead(L);
		return;
	}
	if (pos == maxpos)
	{
		removeTail(L);
		return;
	}
	if (pos > maxpos)
		return;

	count = L->pHead;
	for (int i = 1; i != pos; i++)
		count = count->pNext;
	NODE*temp = count->pNext;
	count->pNext = count->pNext->pNext;
	delete temp;

}
bool addBefore(List* L, int data, int val) {

	NODE*count = L->pHead;

	if (count->key == val)
	{
		addHead(L, data);
		return true;
	}

	while (count->pNext != NULL)
	{
		if (count->pNext->key == val) {
			NODE*p = createNode(data);
			p->pNext = count->pNext;
			count->pNext = p;
			return true;
		}
		count = count->pNext;
	}
	return false;
}
bool addAfter(List* L, int data, int val) {

	NODE*count = L->pHead;
	while (count != NULL)
	{
		if (count->key == val) {
			if (count == L->pTail)
			{
				addTail(L, data);
				return true;
			}
			NODE*p = createNode(data);
			p->pNext = count->pNext;
			count->pNext = p;
			return true;
		}
		count = count->pNext;
	}
	return false;

}

void printList(List* L) {
	NODE*count = L->pHead;
	while (count != NULL)
	{
		cout << count->key << " ";
		count = count->pNext;
	}
	cout << endl;
}

int countElements(List* L) {
	int ans = 1;
	NODE*count = L->pHead;
	while (count->pNext != NULL)
	{
		count = count->pNext;
		ans++;
	}
	return ans;
}

List* reverseList(List* L) {

	int num = countElements(L);
	int*a = new int[num];
	NODE*count = L->pHead;
	for (int i = num - 1; i >= 0; i--)
	{
		a[i] = count->key;
		count = count->pNext;
	}


	NODE*first = createNode(a[0]);
	List*ans = createList(first);

	for (int i = 1; i < num; i++)
		addTail(ans, a[i]);

	delete[] a;
	return ans;
}


void removenode(List*&L, NODE*&remove) {
	if (remove == L->pHead)
	{
		removeHead(L);
		return;
	}
	if (remove == L->pTail)
	{
		removeTail(L);
		return;
	}

	NODE*p = L->pHead;
	while (p->pNext != remove)
		p = p->pNext;
	NODE*temp = remove;
	p->pNext = remove->pNext;
	delete temp;
}

void removeDuplicate(List* &L) {

	NODE*p = L->pHead;
	NODE*count = p;

	while (p != NULL) {
		while (count != NULL && count->pNext != NULL)
		{
			if (count->pNext->key == p->key)
			{
				NODE*temp = count->pNext;
				removenode(L, temp);
			}
			else
				count = count->pNext;
		}
		p = p->pNext;
		count = p;

	}
}

bool removeElement(List* &L, int key) {

	NODE*count = L->pHead;
	NODE*temp;
	int check = 0; //check kiem tra xem co remove node nao chua key hay khong (de tra ve true/false)

	while (count != NULL)
	{
		if (count->key == key) {
			temp = count;
			count = count->pNext;
			removenode(L, temp);

			check = 1;
		}
		count = count->pNext;
	}

	if (check == 0) return false;
	return true;
}