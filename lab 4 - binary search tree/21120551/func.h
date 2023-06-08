#pragma once

struct NODE {
	int key;
	NODE* pLeft;
	NODE* pRight;
};

void printTree(NODE* root, int space);

NODE* createNode(int data);
void Insert(NODE* &pRoot, int x);
void NLR(NODE* pRoot);
void LNR(NODE* pRoot);
void LRN(NODE* pRoot);void printCurrentLevel(NODE* pRoot, int level);void LevelOrder(NODE* pRoot);int findmax(int a, int b);int Height(NODE* pRoot);
int countNode(NODE* pRoot);
int sumNode(NODE* pRoot);
NODE* Search(NODE* pRoot, int x);

NODE*maxNode(NODE*pRoot);
void Remove(NODE* &pRoot, int x);
NODE* createTree(int a[], int n);
void removeTree(NODE* &pRoot);
int heightNode(NODE* pRoot, int value);

int Level(NODE* pRoot, NODE* p);
int countLeaf(NODE* pRoot);
int countLess(NODE* pRoot, int x);
int countGreater(NODE* pRoot, int x);
bool isBST(NODE* pRoot);
bool isFullBST(NODE* pRoot);
