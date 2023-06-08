#pragma once
struct NODE {
	int key;
	NODE* pNext;
};
struct List {
	NODE* pHead;
	NODE* pTail;
};NODE* createNode(int data);List* createList(NODE* pNode);bool addHead(List* &L, int data);bool addTail(List* &L, int data);void removeHead(List* &L);void removeTail(List* &L);void removeAll(List* &L);void removeBefore(List* L, int val);void removeAfter(List* L, int val);bool addPos(List* &L, int data, int pos);void removePos(List* &L, int pos);bool addBefore(List* L, int data, int val);bool addAfter(List* L, int data, int val);void printList(List* L);int countElements(List* L);List* reverseList(List* L);void removenode(List*&L, NODE*&remove);void removeDuplicate(List* &L);bool removeElement(List* &L, int key);