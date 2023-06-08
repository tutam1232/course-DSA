#pragma once

struct DNODE {
	int key;
	DNODE* pNext;
	DNODE* pPrev;
};struct DList {
	DNODE* pHead;
	DNODE* pTail;
};DNODE* createNode(int data);DList* createList(DNODE* pNode);bool addHead(DList* &L, int data);bool addTail(DList* &L, int data);void removeHead(DList* &L);void removeTail(DList* &L);void removeAll(DList* &L);void removeBefore(DList* L, int val);void removeAfter(DList* L, int val);bool addPos(DList* &L, int data, int pos);void removePos(DList* &L, int pos);bool addBefore(DList* L, int data, int val);bool addAfter(DList* L, int data, int val);void printList(DList* L);int countElements(DList* L);DList* reverseList(DList* L);void removeDuplicate(DList* &L);
bool removeElement(DList* &L, int key);