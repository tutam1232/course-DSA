#pragma once

struct NODE {
	int key;
	NODE *pNext;
};

	NODE *head;
};
NODE* createNode(int data);

Stack* initStack(int data);
void Push(Stack*&s, int data);
int Pop(Stack*&s);

void print(Stack*s);

Queue* initQueue(int data);
void Enqueue(Queue*&q, int data);
int Dequeue(Queue*&q);
int CountQ(Queue*q);