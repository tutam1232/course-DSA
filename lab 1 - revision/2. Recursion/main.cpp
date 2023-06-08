#include <iostream>
#include "func.h"
using namespace std;

int main(){
	int a = 5;
	int b = 0;
	//cau 1
	cout << "Ket qua 1+2+3+...+" << a<< " la: ";
	cout << calSum(a) << endl;
	//cau 2
	cout << "Ket qua 1*2*3...*" << a << " la: ";
	cout << calFact(a) << endl;
	//cau 3
	a = 2;
	b = 9;
	cout << "Ket qua cua "<<a<<"^" << b << " la: ";
	cout << calMu(a,b) << endl;
	//cau 4
	a = 14364567;
	cout << "So chu so trong " << a << " la: ";
	cout << calNum(a) << endl;
	//cau 5
	a = 2668;
	if (calEven(a))
		cout << a << " chua toan so chan" << endl;
	else
		cout << a << " co chua so le" << endl;
	a = 2678;
	if (calEven(a))
		cout << a << " chua toan so chan" << endl;
	else
		cout << a << " co chua so le" << endl;
	//cau 6
	a = 12;
	b = 24;
	cout << "So uoc chung cua " << a << " va " << b << " la: ";
	cout << calUC(12, 24) << endl;
	//cau 7
	a = 12;
	b = 16;
	cout << "BCNN cua "<<a<<" va "<<b<<": " << calBCNN(a, b) << endl;
	a = 9;
	b = 6;
	cout << "UCNN cua " << a << " va " << b << ": " << calUCLN(9, 6) << endl;
	//cau 8
	a = 12345;
	cout << "So dao nguoc cua " << a << " la: ";
	cout << calReverse(a) << endl;
	//cau 9
	a = 8;
	cout << "Phan tu thu " << a << " cua day Fibonacci la: ";
	cout << calFibo(a) << endl;
	return 0;
}