#include <iostream>
#include "func.h"
using namespace std;

NODE* createNode(int data) {
	NODE*a = new NODE;
	a->key = data;
	a->pNext = NULL;

	return a;
}
Stack* initStack(int data) {
	Stack*s = new Stack;
	NODE*a = createNode(data);
	s->head = a;
	return s;
}
void Push(Stack*&s,int data) {
	NODE*a = createNode(data);
	a->pNext = s->head;
	s->head = a;
}
int Pop(Stack*&s) {
	if (s->head==NULL)
	{
		return NULL;
	}
	NODE*temp = s->head;
	s->head = s->head->pNext;
	int ans = temp->key;

	delete temp;
	return ans;
}

int CountS(Stack*s) {
	NODE*count = s->head;
	int ans = 0;

	while (count!=NULL)
	{
		count = count->pNext;
		ans++;
	}
	return ans;
}
bool isEmptyS(Stack*s) {
	if (s->head == NULL)
		return true;
	return false;
}
void print(Stack*s) {
	NODE*count = s->head;
	while (count!=NULL)
	{
		cout << endl;
		cout << count->key;
		count = count->pNext;
	}
	cout << endl;
}

Queue* initQueue(int data) {
	NODE*a = createNode(data);
	Queue*q = new Queue;
	q->head = q->tail = a;
	return q;
}
void Enqueue(Queue*&q, int data) {
	NODE*a = createNode(data);
	if (q->head==NULL &&q->tail==NULL)
	{
		q->head = q->tail = a;
		return;
	}
	q->tail->pNext = a;
	q->tail = a;

}

int Dequeue(Queue*&q) {
	if (q->head == NULL && q->tail == NULL)
		return NULL;
	int temp = 0;
	if (q->head==q->tail)
	{
		temp = q->head->key;
		delete q->head;
		q->head = q->tail = NULL;
		return temp;
	}
	NODE*tempnode = q->head;
	temp = q->head->key;
	q->head = q->head->pNext;
	delete tempnode;

	return temp;
	
}
int CountQ(Queue*q) {
	NODE*count = q->head;
	int ans = 0;

	while (count != NULL)
	{
		count = count->pNext;
		ans++;
	}
	return ans;
}
bool isEmptyQ(Queue*q) {
	if (q->head == NULL && q->tail==NULL)
		return true;
	return false;
}

void printQ(Queue*q){
	NODE*count = q->head;
	while (count != NULL)
	{
		cout << count->key << " ";
		count = count->pNext;
	}
	cout << endl;
}