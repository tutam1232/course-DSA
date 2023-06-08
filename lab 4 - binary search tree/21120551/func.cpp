#include "func.h"
#include <iostream>
#include <vector>
using namespace std;

void printTree(NODE* pRoot, int space) 
{
	if (pRoot == NULL)
		return;

	space += 10;
	printTree(pRoot->pRight, space);
	cout << endl;
	for (int i = 10; i < space; i++)
		cout << " ";
	cout << pRoot->key << "\n";

	printTree(pRoot->pLeft, space);

	//reference: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
	/*
	Input : Pointer to root of below tree
			 1
			/  \
		   2    3
		  / \   / \
		 4   5  6  7

		Output :
							7

				  3

							6

		1

							5

				  2

							4
	*/
}

NODE* createNode(int data) {
	NODE*p = new NODE;
	p->key = data;
	p->pLeft = p->pRight = NULL;

	return p;
}

void Insert(NODE* &pRoot, int x) {
	if (pRoot == NULL)
		pRoot = createNode(x);
	else if (x < pRoot->key)
		Insert(pRoot->pLeft, x);
	else if (x > pRoot->key)
		Insert(pRoot->pRight, x);
}

void NLR(NODE* pRoot) {
	if (pRoot == NULL)
		return;
	cout << pRoot->key << " ";
	NLR(pRoot->pLeft);
	NLR(pRoot->pRight);
}

void LNR(NODE* pRoot) {
	if (pRoot == NULL)
		return;
	LNR(pRoot->pLeft);
	cout << pRoot->key << " ";
	LNR(pRoot->pRight);
}

void LRN(NODE* pRoot) {
	if (pRoot == NULL)
		return;
	LRN(pRoot->pLeft);
	LRN(pRoot->pRight);
	cout << pRoot->key << " ";
}

void printCurrentLevel(NODE* pRoot, int level) {
	if (pRoot == NULL)
		return;
	if (level == 0)
		cout << pRoot->key << " ";
	if (level > 0) {
		printCurrentLevel(pRoot->pLeft, level - 1);
		printCurrentLevel(pRoot->pRight, level - 1);
	}

}
void LevelOrder(NODE* pRoot) {
	int height = Height(pRoot);
	for (int i = 0; i < height; i++) {
		printCurrentLevel(pRoot, i);
	}
}

int findmax(int a, int b) {
	if (a > b) return a;
	return b;
}
int Height(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	int a = Height(pRoot->pLeft);
	int b = Height(pRoot->pRight);

	return (findmax(a, b) + 1);
}
int countNode(NODE* pRoot) {
	if (pRoot == NULL)
		return 0;
	int c = 1;
	int a = countNode(pRoot->pLeft);
	int b = countNode(pRoot->pRight);

	return a + b + c;
}

int sumNode(NODE* pRoot) { //check?
	if (pRoot == NULL)
		return 0;
	return (pRoot->key + sumNode(pRoot->pLeft) + sumNode(pRoot->pRight));
}

NODE* Search(NODE* pRoot, int x) {
	if (pRoot == NULL)
		return NULL;
	if (pRoot->key == x)
		return pRoot;
	if (x < pRoot->key)
		return Search(pRoot->pLeft, x);
	if (x > pRoot->key)
		return  Search(pRoot->pRight, x);
}

NODE*maxNode(NODE*pRoot) {
	while (pRoot->pRight != NULL)
		pRoot = pRoot->pRight;
	return pRoot;
}
void Remove(NODE* &pRoot, int x) {

	if (pRoot == NULL)
		return;
	else if (x < pRoot->key)
		Remove(pRoot->pLeft, x);
	else if (x > pRoot->key)
		Remove(pRoot->pRight, x);
	else if (pRoot->key == x) {
		if (pRoot->pLeft == NULL && pRoot->pRight == NULL) {
			delete pRoot;
			pRoot = NULL;
		}
			
		else if (pRoot->pLeft == NULL && pRoot->pRight != NULL) {
			NODE*temp = pRoot;
			pRoot = pRoot->pRight;
			delete temp;
		}
		else if (pRoot->pLeft != NULL && pRoot->pRight == NULL) {
			NODE*temp = pRoot;
			pRoot = pRoot->pLeft;
			delete temp;
		}
		else if (pRoot->pLeft != NULL && pRoot->pRight != NULL) {
			NODE*temp = maxNode(pRoot->pLeft);
			pRoot->key = temp->key;
			Remove(pRoot->pLeft, temp->key);
		}

	}

}

NODE* createTree(int a[], int n) { //check?

	NODE*pRoot = NULL;
	for (int i = 0; i < n; i++)
		Insert(pRoot, a[i]);
	return pRoot;
}

void removeTree(NODE* &pRoot) { //check?
	if (pRoot == NULL)
		return;
	removeTree(pRoot->pLeft);
	removeTree(pRoot->pRight);

	delete pRoot;
	pRoot = NULL;
}

int heightNode(NODE* pRoot, int value) { //check?
	NODE*count = NULL;
	count = Search(pRoot, value);

	if (count == NULL)
		return -1;
	return Height(count);
}

int Level(NODE* pRoot, NODE* p) { //check? level bat dau tu 0

	if (pRoot == NULL || p == NULL)
		return -1;

	int heightRoot = Height(pRoot);
	int heightp = Height(p);

	return (heightRoot - heightp);
}

int countLeaf(NODE* pRoot){ //check?
	if (pRoot == NULL)
		return 0;

	int a = 0;
	if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
		a = 1;
	int b = countLeaf(pRoot->pLeft);
	int c = countLeaf(pRoot->pRight);

	return (a + b + c);
}

int countLess(NODE* pRoot, int x) { //check
	if (pRoot == NULL)
		return 0;
	int a = 0;
	if (pRoot->key < x)
		a = 1;
	int b = countLess(pRoot->pLeft, x);
	int c = countLess(pRoot->pRight, x);

	return (a + b + c);
}

int countGreater(NODE* pRoot, int x) { //check
	if (pRoot == NULL)
		return 0;
	int a = 0;
	if (pRoot->key > x)
		a = 1;
	int b = countGreater(pRoot->pLeft, x);
	int c = countGreater(pRoot->pRight, x);

	return (a + b + c);
}

//bool isBST(NODE* pRoot) { // check
//	if (pRoot == NULL)
//		return true;
//	if (pRoot->pLeft != NULL && pRoot->pLeft->key >= pRoot->key)
//		return false;
//	if (pRoot->pRight != NULL && pRoot->pRight->key <= pRoot->key)
//		return false;
//	return (isBST(pRoot->pLeft) && isBST(pRoot->pRight));
//}


void LNRtoVector(vector<int> &a, NODE*pRoot) {
	if (pRoot == NULL)
		return;
	LNRtoVector(a, pRoot->pLeft);
	a.push_back(pRoot->key);
	LNRtoVector(a, pRoot->pRight);

}
bool isBST(NODE* pRoot) {
	
	vector<int> a;
	LNRtoVector(a, pRoot);

	if (a.empty() || a.size() == 1)
		return true;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] <= a[i - 1])
			return false;
	}

	return true;

}

bool isFullBST(NODE* pRoot) { //check
	if (pRoot == NULL)
		return true;
	if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
		return true;
	if ((pRoot->pLeft != NULL) && (pRoot->pRight != NULL))
		return (isFullBST(pRoot->pLeft) && isFullBST(pRoot->pRight));
	return false;

}