#include <iostream>
#include "func.h"
using namespace std;

int main() {

	List l;
	int n = 0;
	cout << "Nhap so node cua dslk: ";
	cin >> n;
	createlist(l, n);

	List l1;//le
	List l2;//chan
	initList(l1);
	initList(l2);

	Node*temp = l.head;

	while (temp!=NULL)
	{
		if (temp->data % 2 != 0) {
			inserttail(l1, temp->data);
		}
		else
		{
			inserttail(l2, temp->data);
		}
		temp = temp->next;
	}

	temp = l.head;
	Node*temp1 = l1.head;
	Node*temp2 = l2.head;
	
	
	while (temp!=NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	while (temp1 != NULL)
	{
		cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	cout << endl;
	while (temp2 != NULL)
	{
		cout << temp2->data << " ";
		temp2 = temp2->next;
	}
	cout << endl;

	temp = l.head;
	temp1 = l1.head;
	temp2 = l2.head;


	//giai phong vung nho
	while (temp!=NULL)
	{
		Node*del = temp;
		temp = temp->next;
		delete del;
	}
	while (temp1 != NULL)
	{
		Node*del = temp1;
		temp1 = temp1->next;
		delete del;
	}
	while (temp2 != NULL)
	{
		Node*del = temp2;
		temp2 = temp2->next;
		delete del;
	}

	return 0;
}