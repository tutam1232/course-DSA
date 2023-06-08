#include <iostream>
#include "func.h"
using namespace std;

int main() {

	NODE*pRoot = NULL;
	NODE*pRoot2 = NULL;

	cout << "0. Exit the program" << endl;
	cout << "1. Insert a node into AVL tree" << endl;
	cout << "2. Remove a node from AVL tree" << endl;
	cout << "3. Determine if the given Binary Tree is an AVL Tree" << endl;
	cout << "4. Examples to determine if a tree is AVL or not" << endl;

	int n = -1;
	int x = -1;

	do
	{
		cout << "Input request: ";
		cin >> n;

		switch (n)
		{
			case 1:
			{
				cout << "Input x value to be inserted: ";
				cin >> x;
				Insert(pRoot, x);
				printTree(pRoot, 0);
				cout << endl;
			}
				break;
			case 2:
			{
				cout << "Input x value to be removed: ";
				cin >> x;
				Remove(pRoot, x);
				printTree(pRoot, 0);
				cout << endl;
			}
				break;
			case 3:
			{
				if (isAVL(pRoot) == true) {
					printTree(pRoot, 0);
					cout << "This is a AVL Tree!" << endl;
					cout << endl;
				}
				else
				{
					printTree(pRoot, 0);
					cout << "This isn't a AVL Tree!" << endl;
					cout << endl;
				}	
			}
				break;
			case 4:
			{
				//------------example of a avl tree

				int a[] = { 3,/*14,*/25,15,92,65/*,45,89*/,2,1/*,0*/ };
				for (int i = 0; i < sizeof(a) / sizeof(int); i++)
					InsertWithoutRotate(pRoot2, a[i]);

				if (isAVL(pRoot2) == true) {
					printTree(pRoot2, 0);
					cout << "This is a AVL Tree!" << endl;
					cout << endl;
				}
				else
				{
					printTree(pRoot2, 0);
					cout << "This isn't a AVL Tree!" << endl;
					cout << endl;
				}
				removeTree(pRoot2);

				//------------ example of not a avl tree

				int a1[] = { 3,14,25,15,92,65,45,89,2,1,0 };
				for (int i = 0; i < sizeof(a1) / sizeof(int); i++)
					InsertWithoutRotate(pRoot2, a1[i]);
				if (isAVL(pRoot2) == true) {
					printTree(pRoot2, 0);
					cout << "This is a AVL Tree!" << endl;
					cout << endl;
				}
				else
				{
					printTree(pRoot2, 0);
					cout << "This isn't a AVL Tree!" << endl;
					cout << endl;
				}
				removeTree(pRoot2);
			}
				break;
		}

	} while (n!=0);

	removeTree(pRoot);
	printTree(pRoot, 0);
	
	return 0;
}