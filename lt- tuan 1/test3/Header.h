#pragma once
struct Node
{
	int data;
	Node*pnext;
};
struct LinkedList {
	Node*head;
};
struct Stack {
	char* data;
	int size;
	int top;
};