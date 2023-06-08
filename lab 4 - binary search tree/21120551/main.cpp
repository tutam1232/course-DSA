#include <iostream>
#include "func.h"
using namespace std;

int main() {

	//int a[] = { 33,14,15,92,64,35,79,27,38,9,105,99,120,5,8 };
	int a[] = { 9,3,12,6,15};
	int n = sizeof(a) / 4;

	int request = -1;

	cout << "0. Exit the program" << endl;
	cout << "1. Print current tree" << endl;
	cout << "2. Add a NODE with given value into the given Binary Search Tree" << endl;
	cout << "3. Pre-order Traversal (NLR)" << endl;
	cout << "4. In-order Traversal (LNR)" << endl;
	cout << "5. Post-order Traversal (LRN)" << endl;
	cout << "6. Level-order Traversal" << endl;
	cout << "7. Calculate the height of the given Binary Tree" << endl;
	cout << "8. Count the number of NODE from the given Binary Tree" << endl;
	cout << "9. Calculate the total value of all NODEs from the given Binary Tree" << endl;
	cout << "10. Find and return a NODE with given value from the given Binary Search Tree" << endl;
	cout << "11. Remove a NODE with given value from the given Binary Search Tree" << endl;
	cout << "12. Initialize a Binary Search Tree from the given array" << endl;
	cout << "13. Completely remove the given Binary Search Tree" << endl;
	cout << "14. Calculate the height of the NODE with given value: (return -1 if value not exist)" << endl;
	cout << "15. Calculate the level of a given NODE" << endl;
	cout << "16. Count the number leaves from a given Binary Tree" << endl;
	cout << "17. Count the number of NODE from a given Binary Search Tree which key value is less than a given value" << endl;
	cout << "18. Count the number of NODE from a given Binary Search Tree which key value is greater than a given value" << endl;
	cout << "19. Determine if a given Binary Tree is Binary Search Tree" << endl;
	cout << "20. Determine if a given Binary Tree is a Full Binary Search Tree" << endl;

	NODE*pRoot = NULL;
	int x = -1;

	do
	{
		cout << endl << "Input request: ";
		cin >> request;

		switch (request)
		{
		case 1:
			printTree(pRoot, 0);
			break;
		case 2:
		{
			cout << "Input x value to insert into the tree: ";
			cin >> x;
			Insert(pRoot, x);
			printTree(pRoot, 0);
		}
		break;
		case 3:
		{
			printTree(pRoot, 0);
			cout << "Pre-order Traversal: ";
			NLR(pRoot);			
		}
			break;
		case 4: 
		{
			printTree(pRoot, 0);
			cout << "In-order Traversal: ";
			LNR(pRoot);
		}
			break;
		case 5:
		{
			printTree(pRoot, 0);
			cout << "Post-order Traversal: ";
			LRN(pRoot);
		}
			break;
		case 6:
		{
			printTree(pRoot, 0);
			cout << "Level-order Traversal: ";
			LevelOrder(pRoot);
		}
			break;
		case 7:
		{
			printTree(pRoot, 0);
			cout << "Height: " << Height(pRoot) << endl;
		}
		break;
		case 8:
		{
			printTree(pRoot, 0);
			cout << "Number of NODE from the given Binary Tree: " << countNode(pRoot) << endl;
		}
		break;
		case 9:
		{
			printTree(pRoot, 0);
			cout << "Total value of all NODEs from a given Binary Tree: " << sumNode(pRoot) << endl;
		}
		break;
		case 10:
		{
			printTree(pRoot, 0);
			cout << "Input x value to be searched in the given Binary Search Tree: ";
			cin >> x;
			NODE*p = Search(pRoot, x);
			if (p != NULL)
				cout << x << " exists in the given Binary Search Tree! (returned in NODE*p)" << endl;
			else
				cout << x << " doesn't exist in the given Binary Search Tree!" << endl;
		}
		break;
		case 11:
		{
			printTree(pRoot, 0);
			cout << "Input x value to be removed in the given Binary Search Tree: ";
			cin >> x;
			Remove(pRoot, x);
			printTree(pRoot, 0);
		}
		break;
		case 12:
		{
			cout << "Binary Search Tree created from array a[]" << endl;
			pRoot = createTree(a, n);
			printTree(pRoot, 0);
		}
		break;
		case 13:
		{
			cout << "Tree removed!" << endl;
			removeTree(pRoot);
			printTree(pRoot, 0);
		}
		break;
		case 14:
		{
			printTree(pRoot, 0);
			cout << "Input value: ";
			cin >> x;
			cout << "Height of the given tree: " << heightNode(pRoot, x);
		}
		break;
		case 15:
		{
			printTree(pRoot, 0);
			cout << "Input the value of a NODE: ";
			cin >> x;
			NODE*q = Search(pRoot, x);
			if (Level(pRoot, q) != -1)
				cout << "Level of the given NODE (level starts at 0): " << Level(pRoot, q) << endl;
			else
				cout << "The given NODE doesn't exist in the given Binary Search Tree" << endl;
		}
		break;
		case 16:
		{
			printTree(pRoot, 0);
			cout << "Number of leaves: " << countLeaf(pRoot) << endl;
		}
		break;
		case 17:
		{
			printTree(pRoot, 0);
			cout << "Input x value: ";
			cin >> x;
			cout << "Number of NODE which key value is less than the given x value: " << countLess(pRoot, x) << endl;
		}
		break;
		case 18:
		{
			printTree(pRoot, 0);
			cout << "Input x value: ";
			cin >> x;
			cout << "Number of NODE which key value is greater than the given x value: " << countGreater(pRoot, x) << endl;
		}
		break;
		case 19:
		{
			//case 1: is BST
			printTree(pRoot, 0);
			if (isBST(pRoot) == 1)
				cout << "This is Binary Search Tree!" << endl;
			else
				cout << "This is not Binary Search Tree!" << endl;

			//case 2: not BST
			if (pRoot != NULL && pRoot->pLeft != NULL)
				pRoot->pLeft->key = pRoot->key + 1;
			else if (pRoot != NULL && pRoot->pRight != NULL)
				pRoot->pRight->key = pRoot->key - 1;
			printTree(pRoot, 0);
			if (isBST(pRoot) == 1)
				cout << "This is Binary Search Tree!" << endl;
			else
				cout << "This isn't Binary Search Tree!" << endl;

			removeTree(pRoot);
			pRoot = createTree(a, n);

		}
		break;
		case 20:
		{
			printTree(pRoot, 0);
			if (isFullBST(pRoot) == 1)
				cout << "This is a Full Binary Search Tree" << endl;
			else
				cout << "This isn't a Full Binary Search Tree" << endl;
		}
		break;
		default:
			break;

		}

	} while (request != 0);

	return 0;
}
