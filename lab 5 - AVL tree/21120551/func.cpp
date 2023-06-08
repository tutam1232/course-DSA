#include <iostream>
#include "func.h"
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

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

NODE* createNode(int data) {
	NODE*a = new NODE;
	a->key = data;
	a->pLeft = a->pRight = NULL;
	a->height = 1;

	return a;
}

int height(NODE* node){
	if (node == NULL)
		return 0;
	return node->height;
}

void RotateRight(NODE* &a) {
	NODE*b = a->pLeft;
	NODE*T2 = b->pRight;
	b->pRight = a;
	a->pLeft = T2;
	a = b;

	b = a->pRight;
	b->height = max(height(b->pLeft), height(b->pRight)) + 1;
	a->height = max(height(a->pLeft), height(a->pRight)) + 1;
	
}

void RotateLeft(NODE* &a) {
	NODE*b = a->pRight;
	NODE*T2 = b->pLeft;
	b->pLeft = a;
	a->pRight = T2;
	a = b;

	b = a->pLeft;
	b->height = max(height(b->pLeft), height(b->pRight)) + 1;
	a->height = max(height(a->pLeft), height(a->pRight)) + 1;
}

void Insert(NODE* &pRoot, int x) {
	if (pRoot==NULL)
		pRoot = createNode(x);

	else if (x < pRoot->key) {
		Insert(pRoot->pLeft, x);
		if ((height(pRoot->pLeft) - height(pRoot->pRight)) > 1) {

			if (x < pRoot->pLeft->key)
				RotateRight(pRoot);
			else {
				RotateLeft(pRoot->pLeft);
				RotateRight(pRoot);
			}

		}
			
	}

	else if (x > pRoot->key) {
		Insert(pRoot->pRight, x);
		if ((height(pRoot->pRight) - height(pRoot->pLeft)) > 1) {

			if (x > pRoot->pRight->key)
				RotateLeft(pRoot);
			else {
				RotateRight(pRoot->pRight);
				RotateLeft(pRoot);
			}

		}
	}

	else if (x == pRoot->key) {
		cout << "The given value existed, cannot be inserted to AVL!" << endl;
		return;
	}

	pRoot->height = max(height(pRoot->pLeft), height(pRoot->pRight)) + 1;

}

NODE*maxNode(NODE*pRoot) {
	while (pRoot->pRight != NULL)
		pRoot = pRoot->pRight;
	return pRoot;
}

void Remove(NODE* &pRoot, int x) {

	if (pRoot == NULL) {
		cout << "The given value not existed, cannot be removed from AVL!" << endl;
		return;
	}

	else if (x < pRoot->key)
		Remove(pRoot->pLeft, x);
	else if (x > pRoot->key)
		Remove(pRoot->pRight, x);	
	else if (x == pRoot->key) {

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

	if (pRoot == NULL)
		return;

	pRoot->height = max(height(pRoot->pLeft), height(pRoot->pRight)) + 1;

	if ((height(pRoot->pLeft) - height(pRoot->pRight)) > 1) {

		if ((height(pRoot->pLeft->pLeft) - height(pRoot->pLeft->pRight)) > 0) //left left
			RotateRight(pRoot);
		else {
			RotateLeft(pRoot->pLeft);
			RotateRight(pRoot);
		}
	}

	else if ((height(pRoot->pRight) - height(pRoot->pLeft)) > 1) {

		if ((height(pRoot->pRight->pRight) - height(pRoot->pRight->pLeft)) > 0) //right right
			RotateLeft(pRoot);
		else {
			RotateRight(pRoot->pRight);
			RotateLeft(pRoot);
		}
	}

}

void removeTree(NODE* &pRoot) { //check?
	if (pRoot == NULL)
		return;
	removeTree(pRoot->pLeft);
	removeTree(pRoot->pRight);

	delete pRoot;
	pRoot = NULL;
}

bool isAVL(NODE* pRoot) {

	if (pRoot == NULL)
		return true;
	int lh = height(pRoot->pLeft);
	int rh = height(pRoot->pRight);
	if ((abs(lh - rh) <= 1) && (isAVL(pRoot->pLeft) == true) && (isAVL(pRoot->pRight) == true))
		return true;
	return false;

}

void InsertWithoutRotate(NODE* &pRoot, int x) {

	if (pRoot == NULL)
		pRoot = createNode(x);

	else if (x < pRoot->key) {
		InsertWithoutRotate(pRoot->pLeft, x);
	}

	else if (x > pRoot->key) {
		InsertWithoutRotate(pRoot->pRight, x);
	}

	else if (x == pRoot->key) {
		cout << "The given value existed, cannot be inserted to tree!" << endl;
		return;
	}

	pRoot->height = max(height(pRoot->pLeft), height(pRoot->pRight)) + 1;

}