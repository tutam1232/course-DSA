#include <iostream>
#include "func.h"
using namespace std;

DNODE* createNode(int data) {
	DNODE*a = new DNODE;
	a->key = data;
	a->pNext = NULL;
	a->pPrev = NULL;

	return a;
}

DList* createList(DNODE* pNode) {

	DList*l = new DList; 
	l->pHead = l->pTail = pNode;
	return l;
}

bool addHead(DList* &L, int data) {

	if (L->pHead == NULL && L->pTail == NULL)
		return false;

	DNODE*p = createNode(data);
	
	p->pNext = L->pHead;
	L->pHead->pPrev = p;
	L->pHead = p;

	return true;
}

bool addTail(DList* &L, int data) {

	if (L->pHead == NULL && L->pTail == NULL)
		return false;

	DNODE*p = createNode(data);

	p->pPrev = L->pTail;
	L->pTail->pNext = p;
	L->pTail = p;
	return true;
}
void removeHead(DList* &L) {
	if (L->pHead == NULL && L->pTail == NULL)
		return;
	if (L->pHead == L->pTail)
	{
		delete L->pHead;
		L->pHead = L->pTail = NULL;
		return;
	}

	DNODE*temp2 = L->pHead;
	L->pHead = L->pHead->pNext;
	delete temp2;
	L->pHead->pPrev = NULL;
}

void removeTail(DList* &L) {
	if (L->pHead == NULL && L->pTail == NULL)
		return;
	if (L->pHead == L->pTail)
	{
		delete L->pHead;
		L->pHead = L->pTail = NULL;
		return;
	}
	DNODE*del = L->pTail;
	DNODE*temp = L->pTail->pPrev;
	delete del;
	temp->pNext = NULL;
	L->pTail = temp;
}

void removeAll(DList* &L) {
	DNODE*count = L->pHead;
	DNODE*temp = count;
	L->pHead = L->pTail = NULL;

	while (count != NULL)
	{
		count = count->pNext;
		delete temp;
		temp = count;
	}
}

void removeBefore(DList* L, int val) {

	//neu val o node head
	DNODE*count = L->pHead;
	if (count->key == val)
		return;

	//neu val o node ke tiep head
	if (count->pNext->key == val)
	{
		removeHead(L);
		return;
	}

	//truong hop con lai
	while (count != NULL)
	{
		if (count->key != val)
			count = count->pNext;
		else
			break;
	}

	if (count == NULL)
		return;

	DNODE*temp = count->pPrev->pPrev;
	count = temp->pNext;
	temp->pNext = temp->pNext->pNext;
	temp->pNext->pPrev = temp;

	delete count;
}

void removeAfter(DList* L, int val) {

	//neu val o node tail
	DNODE*check = L->pTail;
	if (check->key == val)
		return;

	while (check != NULL)
	{
		if (check->key != val)
			check = check->pPrev;
		else
			break;
	}
	if (check == NULL)
		return;

	//neu val o ke node tail
	if (check->pNext == L->pTail)
	{
		removeTail(L);
		return;
	}

	DNODE*temp = check->pNext;
	check->pNext = check->pNext->pNext;
	check->pNext->pPrev = check;
	delete temp;
}

bool addPos(DList* &L, int data, int pos) { //pos bat dau tinh tu 0
	if (pos < 0)
		return false;

	if (pos == 0)
	{
		addHead(L, data);
		return true;
	}

	DNODE*count = L->pHead;
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

	DNODE*p = createNode(data);
	p->pNext = count->pNext;
	count->pNext = p;
	p->pPrev = count;
	p->pNext->pPrev = p;
	return true;

}
void removePos(DList* &L, int pos) { //pos bat dau tinh tu 0

	if (pos < 0)
		return;

	DNODE*count = L->pHead;
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
	for (int i = 0; i != pos; i++)
		count = count->pNext;

	DNODE*temp = count;
	count->pPrev->pNext = count->pNext;
	count->pNext->pPrev = count->pPrev;
	delete temp;

}
bool addBefore(DList* L, int data, int val) {

	DNODE*count = L->pHead;

	if (count->key == val)
	{
		addHead(L, data);
		return true;
	}

	while (count != NULL)
	{
		if (count->key == val) {

			DNODE*p = createNode(data);
			p->pNext = count;
			p->pPrev = count->pPrev;
			p->pPrev->pNext = p->pNext->pPrev = p;

			return true;
		}
		count = count->pNext;
	}
	return false;
}

bool addAfter(DList* L, int data, int val) {

	DNODE*count = L->pHead;
	while (count != NULL)
	{
		if (count->key == val) {
			if (count == L->pTail)
			{
				addTail(L, data);
				return true;
			}

			DNODE*p = createNode(data);
			p->pNext = count->pNext;
			p->pPrev = count;
			p->pNext->pPrev = p->pPrev->pNext = p;
			return true;
		}
		count = count->pNext;
	}
	return false;

}

void printList(DList* L) {
	DNODE*count = L->pHead;
	while (count != NULL)
	{
		cout << count->key << " ";
		count = count->pNext;
	}
	cout << endl;
}

int countElements(DList* L) {
	int ans = 1;
	DNODE*count = L->pHead;
	while (count->pNext != NULL)
	{
		count = count->pNext;
		ans++;
	}
	return ans;
};

DList* reverseList(DList* L) {

	int num = countElements(L);
	int*a = new int[num];
	DNODE*count = L->pHead;
	for (int i = num - 1; i >= 0; i--)
	{
		a[i] = count->key;
		count = count->pNext;
	}


	DNODE*first = createNode(a[0]);
	DList*ans = createList(first);

	for (int i = 1; i < num; i++)
		addTail(ans, a[i]);

	delete[] a;
	return ans;
}

void removenode(DList*&L, DNODE*&remove) {
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

	DNODE*temp = remove;
	temp->pPrev->pNext = temp->pNext;
	temp->pNext->pPrev = temp->pPrev;
	delete temp;
}

void removeDuplicate(DList* &L) {

	DNODE*p = L->pHead;
	DNODE*count = p;

	while (p != NULL) {
		while (count != NULL && count->pNext != NULL)
		{
			if (count->pNext->key == p->key)
			{
				DNODE*temp = count->pNext;
				removenode(L, temp);
			}
			else
				count = count->pNext;
		}
		p = p->pNext;
		count = p;

	}
}

bool removeElement(DList* &L, int key) {

	DNODE*count = L->pHead;
	DNODE*temp;
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