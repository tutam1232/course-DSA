#include <iostream>
#include "func.h"
using namespace std;

int main() {
	cout << "------------------ LINKED LIST ------------------" << endl << endl;

	NODE*a = createNode(0);

	cout << "Create list: " << endl;
	List*L = createList(a);
	printList(L);

	cout << endl;
	cout << "Add head: " << endl;
	addHead(L, 1);
	printList(L);

	cout << endl;
	cout << "Add tail: " << endl;
	addTail(L, 2);
	printList(L);
	addTail(L, 4);
	printList(L);
	addTail(L, 3);
	printList(L);
	addTail(L, 4);
	printList(L);
	addTail(L, 5);
	printList(L);

	cout << endl;
	cout << "Add head: " << endl;
	addHead(L, 2);
	printList(L);
	addHead(L, 2);
	printList(L);

	cout << endl;
	cout << "Add tail: " << endl;
	addTail(L, 2);
	printList(L);
	addTail(L, 2);
	printList(L);

	cout << endl;
	cout << "Remove head: " << endl;
	removeHead(L);
	printList(L);

	cout << endl;
	cout << "Remove tail: " << endl;
	removeTail(L);
	printList(L);

	cout << endl;
	cout << "Remove before: " << endl;
	removeBefore(L, 200);
	printList(L);
	removeBefore(L, 2);
	printList(L);
	removeBefore(L, 1);
	printList(L);
	removeBefore(L, 3);
	printList(L);

	cout << endl;
	cout << "Remove after: " << endl;
	removeAfter(L, 200);
	printList(L);
	removeAfter(L, 2);
	printList(L);
	removeAfter(L, 5);
	printList(L);
	removeAfter(L, 3);
	printList(L);

	cout << endl;
	cout << "Add pos: " << endl;
	addPos(L, 34, 100);
	printList(L);
	addPos(L, 34, 0);
	printList(L);
	addPos(L, 10, 6);
	printList(L);
	addPos(L, 10, 4);
	printList(L);

	cout << endl;
	cout << "Remove pos: " << endl;
	removePos(L, 100);
	printList(L);
	removePos(L, 0);
	printList(L);
	removePos(L, 6);
	printList(L);
	removePos(L, 2);
	printList(L);

	cout << endl;
	cout << "Add before: " << endl;
	addBefore(L, 2, 15);
	printList(L);
	addBefore(L, 20, 1);
	printList(L);
	addBefore(L, 15, 0);
	printList(L);

	cout << endl;
	cout << "Add after: " << endl;
	addAfter(L, 2, 100);
	printList(L);
	addAfter(L, 2, 3);
	printList(L);
	addAfter(L, 15, 5);
	printList(L);
	addAfter(L, 3, 15);
	printList(L);

	cout << endl;
	cout << "So node cua list L: " << countElements(L) << endl;

	cout << endl;
	List*L2 = reverseList(L);
	cout << "List dao nguoc cua L (L2): ";
	printList(L2);

	cout << endl;
	cout << "Remove duplicate: " << endl;
	removeDuplicate(L);
	printList(L);

	cout << endl;
	cout << "Remove element 15: " << endl;
	removeElement(L, 15);
	printList(L);

	cout << endl;
	cout << "Remove all: " << endl;
	removeAll(L);
	printList(L);

	cout << "---------------------------" << endl;

	//giai phong vung nho
	removeAll(L2);


	return 0;
}