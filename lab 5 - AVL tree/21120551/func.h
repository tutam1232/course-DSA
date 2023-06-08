#pragma once

struct NODE {
	int key;
	NODE* pLeft;
	NODE* pRight;
	int height;
};
void printTree(NODE* pRoot, int space);
int max(int a, int b);
NODE* createNode(int data);
int height(NODE* node);
void RotateRight(NODE* &a);
void RotateLeft(NODE* &a);
void Insert(NODE* &pRoot, int x);
NODE*maxNode(NODE*pRoot);
void Remove(NODE* &pRoot, int x);
void removeTree(NODE* &pRoot);
bool isAVL(NODE* pRoot);
void InsertWithoutRotate(NODE* &pRoot, int x);
