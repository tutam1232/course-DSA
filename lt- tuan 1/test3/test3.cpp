#include <iostream>
#include "Header.h"
using namespace std;

void initList(LinkedList &l) {
	l.head = NULL;
}

void delnodek(int k, LinkedList &l) {

	Node*temp = l.head;
	if (k==1)
	{
		l.head = l.head->pnext;
		delete temp;
		return;
	}
	for (int i = 0; i < k-1; i++)
	{
		temp = temp->pnext;
	}
	Node*temp2 = l.head;
	while (temp2->pnext!=temp)
	{
		temp2 = temp2->pnext;
	}
	temp2->pnext = temp->pnext;
	delete temp;
} 
Stack initStack(int size) {
	Stack s;
	s.size = size;
	s.data = new char[size];
	s.top = 0;
	return s;
}
char pop(Stack &s) {
	char item = s.data[s.top];
	s.top--;
	return item;
}
int push(Stack &s, int k) {
	if (s.top == (s.size - 1))
		return 0;
	s.top++;
	s.data[s.top] = k;
	return 1;
}
//tao dslk tu mang cho trc
//xoa phan tu o vi tri k o dslk
// xoa phtu bat kytrong dslk

//cho hàng đợi ban đầu như sau: (hàng đợi tối đa 6 phần tử), vẽ tình trạng của hàng đợi và cho biết giá trị của f và r                            
//ứng với mỗi lần thực hiện các thao tác sau
//1 thêm e vào hàng đợi
//2 loại 2 ptu khỏi hàng đợi
//3 bổ sung i, j, k vào hàng đợi    
//4 loại 2 ptu khỏi hàng đợi
//5 thêm o vào hàng đợi
//6 loại 2 ptu khỏi hàng  

/*btvn: cho 1 dslk đơn, mỗi node trong dslk lưu thông tin là một số nguyên, từ dslk tạo ra 2 dslk mới mà ko phá hủy
dslk đã cho, 1 dslk chứa số lẻ và 1 dslk chứa số chẵn*/

void main() {

	Stack s=initStack(25);
	int n = 9;
	char a;
	while (n!=0)
	{
		cin >> n;
		if (n == 1) {
			cin >> a;
			push(s, a);
		}
		if (n==2)
		{
			cout << pop(s);
			cout << endl;
		}
	}



}