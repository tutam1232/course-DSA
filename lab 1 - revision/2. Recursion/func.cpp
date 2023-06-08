#include <iostream>
#include <cmath>
#include "func.h"
using namespace std;

int calSum(int n) {
	if (n==1)
	{
		return 1;
	}

	return n + calSum(n - 1);
}

int calFact(int n) {
	if (n == 0)
	{
		return 1;
	}

	return n * calFact(n - 1);
}

int calMu(int x,int n) {
	if (n == 0)
	{
		return 1;
	}
	n--;

	return x * calMu(x, n);
}

int calNum(int n) {
	if (n <= 9)
	{
		return 1;
	}

	return 1 + calNum(n / 10);
}

bool calEven(int n) {
	if (n % 2 != 0)
	{
		return false;
	}
	if (n <= 9 && n % 2 == 0)
	{
		return true;
	}

	return calEven(n / 10);
}

int calUC(int a, int b) {
	static int count = 1;
	if (a==count || b==count)
	{
		if (a%b == 0 || b % a == 0) return 1;
		else return 0;
	}
	if (a%count==0 && b%count==0)
	{
		count++;
		return 1+calUC(a, b);
	}
	else
	{
		count++;
		return calUC(a, b);
	}
}

int calUCLN(int a, int b) {
	if (a == b) return a;
	else if (a > b)
		return calUCLN(a - b, b);
	else
		return calUCLN(a, b - a);
}

int calBCNN(int a, int b) {
	static int i = 1;
	static int j = 1;

	if (a == b) return b;
	else if (a>b)
	{
		i++;
		calBCNN(a, (b/(i-1))*i);
	}
	else
	{
		j++;
		calBCNN((a / (j - 1))*j, b);
	}
}

int calReverse(int n) {
	int num=calNum(n);
	if (n==0)
	{
		return 0;
	}

	return ((n%10)*pow(10, num - 1) + calReverse(n / 10));
}

int calFibo(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;

	return calFibo(n - 1) + calFibo(n - 2);
}