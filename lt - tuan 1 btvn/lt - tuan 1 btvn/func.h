#pragma once

struct Node
{
	int data;
	Node*next;
};
struct List
{
	Node*head;
	Node*tail;
};
void initList(List &l);
Node* createNode(int data);
void inserttail(List &l, int data);
void createlist(List&l, int n);