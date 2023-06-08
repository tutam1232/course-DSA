#pragma once

struct NODE {
	int key;
	NODE *pNext;
};struct Stack {

	NODE *head;
};struct Queue {	NODE *head;	NODE *tail;};
NODE* createNode(int data);

Stack* initStack(int data);
void Push(Stack*&s, int data);
int Pop(Stack*&s);int CountS(Stack*s);bool isEmptyS(Stack*s);

void print(Stack*s);

Queue* initQueue(int data);
void Enqueue(Queue*&q, int data);
int Dequeue(Queue*&q);
int CountQ(Queue*q);bool isEmptyQ(Queue*q);void printQ(Queue*q);