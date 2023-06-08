#include <iostream>
#include "func.h"
using namespace std;

int main() {

	cout << "------------------------ STACK ------------------------" << endl;
	cout << "Khoi tao stack: ";
	Stack*s=initStack(0);
	print(s);

	cout << "Push 1: ";
	Push(s, 1);
	print(s);

	cout << "So luong phan tu cua stack: ";
	cout << CountS(s) << endl;
	cout << "Stack rong?: ";
	cout << isEmptyS(s) << endl;

	cout << "Phan tu o dinh stack la (pop): ";
	cout << Pop(s) << endl;
	cout << "Stack hien tai: ";
	print(s);

	cout << "Phan tu o dinh stack la (pop): ";
	cout << Pop(s) << endl;
	cout << "Stack hien tai: ";
	print(s);

	cout << "Stack rong?: ";
	cout << isEmptyS(s);

	cout << endl;
	cout << "------------------------ QUEUE ------------------------" << endl;
	cout << "Khoi tao Queue: ";
	Queue*q = initQueue(0);
	printQ(q);

	cout << "Enqueue 1: ";
	Enqueue(q, 1);
	printQ(q);

	cout << "So luong phan tu cua queue: ";
	cout << CountQ(q) << endl;
	cout << "Queue rong?: ";
	cout << isEmptyQ(q) << endl;

	cout << "Phan tu dau tien cua queue la (dequeue): ";
	cout << Dequeue(q) << endl;
	cout << "Queue hien tai: ";
	printQ(q);

	cout << "Phan tu dau tien cua queue la (dequeue): ";
	cout << Dequeue(q) << endl;
	cout << "Queue hien tai: ";
	printQ(q);

	cout << "Queue rong?: ";
	cout << isEmptyQ(q);

	cout << endl;
	return 0;
}