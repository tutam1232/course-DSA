#include <iostream>
#include "func.h"
#include <stdlib.h>
#include <ctime>
using namespace std;


void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int* sum(int* a, int* b) {
	int* c = new int;
	*c = *a + *b;
	return c;
}

void inputArray(int* &a, int &n) {
	cout << "Nhap n: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: " << a[i] << endl;
	}
}

int* findMax(int* arr, int n) {
	int *max = new int;
	max= &arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i]>*max)
		{
			max = &arr[i];
		}
	}
	return max;
}

int* findLongestAscendingSubarray(int* a, int n, int &length) {

	int *index = new int[n];
	int *len = new int[n];
	for (int i = 0; i < n; i++) len[i] = 1;

	int count = 0;
	int countindex = 0;

	index[count] = countindex; //truong hop mang chi co 1 phan tu

	for (int i = 1; i < n; i++)
	{
		index[count] = countindex;
		if (a[i]>a[i-1])
		{
			len[count]++;
		}
		else
		{
			count++;
			countindex = i;
		}
	}

	length = len[0];
	int ansindex = index[0];
	for (int i = 1; i < n; i++)
	{
		if (len[i]>length)
		{
			length = len[i];
			ansindex = index[i];
		}
	}

	int*ans = new int[length];
	int i = 0;
	for (int j = ansindex; j < (ansindex+length); j++)
	{
		ans[i] = a[j];
		i++;
	}

	//giai phong vung nho
	delete[] index;
	delete[] len;
	return ans;
}

void swapArrays(int* &a, int* &b, int &na, int &nb) {
	int*temp = a;
	a = b;
	b = temp;

	int ntemp = na;
	na = nb;
	nb = ntemp;
}


int* concatenate2Arrays(int* a, int* b, int na, int nb, int &nc) { //?
	nc = na + nb;
	int*c = new int[nc];
	for (int i = 0; i < na; i++)
	{
		c[i] = a[i];
	}
	int j = 0;
	for (int i = na; i < na+nb; i++)
	{
		c[i] = b[j];
		j++;
	}
	return c;
}

int* merge2Arrays(int* a, int* b, int na, int nb, int &nc) { //?
	nc = na + nb;
	int*c = new int[nc];
	for (int i = 0; i < na; i++)
	{
		c[i] = a[i];
	}
	int j = 0; 
	for (int i = na; i < na + nb; i++)
	{
		c[i] = b[j];
		j++;
	}
	for (int i = 0; i < nc-1; i++)
	{
		for (int j = i+1; j < nc; j++)
		{
			if (c[i]>c[j])
			{
				swap(&c[i], &c[j]);
			}
		}
	}
	return c;
}

void generateMatrix1(int** &a, int &length, int &width) {
	cout << "Nhap so dong: ";
	cin >> width;
	cout << "Nhap so cot: ";
	cin >> length;
	a = new int*[width];
	for (int i = 0; i < width; i++)
	{
		a[i] = new int[length];
	}
	srand((unsigned)time(0));
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			a[i][j]= 1+rand() % 100;
		}
	}

}

int** generateMatrix2(int* a, int* b, int na, int nb, int &crow, int &ccol) {
	crow = na;
	ccol = nb;
	int**c = new int*[na];
	for (int i = 0; i < na; i++)
	{
		c[i] = new int[nb];
	}
	for (int i = 0; i < na; i++)
	{
		for (int j = 0; j < nb; j++)
		{
			c[i][j] = a[i] * b[j];
		}
	}
	return c;
}

void swapColumns(int** a, int length, int width, int ic1, int ic2) {
	for (int i = 0; i < width; i++)
	{
		swap(&a[i][ic1], &a[i][ic2]);
	}
}

void swapRows(int** a, int length, int width, int ir1, int ir2) {
	for (int i = 0; i < length; i++)
	{
		swap(&a[ir1][i], &a[ir2][i]);
	}
}

int** transposeMatrix(int** a, int length, int width) {
	int**b = new int *[length];
	for (int i = 0; i < length; i++)
	{
		b[i] = new int[width];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++) {
			b[i][j] = a[j][i];
		}
	}
	return b;
}

int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres) {
	wres = width;
	lres = length * 2;
	int**ans = new int*[wres];
	for (int i = 0; i < wres; i++)
	{
		ans[i] = new int[lres];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			ans[i][j] = a[i][j];
		}
	}
	int k = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = length; j < lres; j++) {
			ans[i][j] = b[i][k];
			k++;
		}
		k = 0;
	}
	return ans;
}

int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres) {
	wres = width*2;
	lres = length;
	int**ans = new int*[wres];
	for (int i = 0; i < wres; i++)
	{
		ans[i] = new int[lres];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			ans[i][j] = a[i][j];
		}
	}
	int k = 0;
	for (int i = width; i < wres; i++)
	{
		for (int j = 0; j < length; j++) {
			ans[i][j] = b[k][j];
		}
		k++;
	}
	return ans;
}

bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb){
	if (lengtha!=widthb && widtha!=lengthb)
	{
		return false;
	}
	if (lengtha==widthb)
	{
		widthr = widtha;
		lengthr = lengthb;
		res = new int*[widthr];
		for (int i = 0; i < widthr; i++)
		{
			res[i] = new int[lengthr];
		}

		for (int i = 0; i < widthr; i++)
		{
			for (int j = 0; j < lengthr; j++) {
				res[i][j] = 0;
				for (int k = 0; k < widthb; k++)
				{
					res[i][j] += a[i][k] * b[k][j];
				}
			}
		}
	}
	else if (lengthb == widtha)
	{
		widthr = widthb;
		lengthr = lengtha;
		res = new int*[widthr];
		for (int i = 0; i < widthr; i++)
		{
			res[i] = new int[lengthr];
		}

		for (int i = 0; i < widthr; i++)
		{
			for (int j = 0; j < lengthr; j++) {
				res[i][j] = 0;
				for (int k = 0; k < widtha; k++)
				{
					res[i][j] += b[i][k] * a[k][j];
				}
			}
		}
	}

	
	return true;
}

int** findSubmatrix(int** a, int length, int width, int &lres, int &wres) {
	
	int*sub;

	cout << endl;
	cout << "Nhap so DONG cua ma tran con: ";
	cin >> wres;
	cout << "Nhap so COT cua ma tran con: ";
	cin >> lres;

	if (lres > length || wres > width) {
		return NULL;
	}

	int demcot = length - (lres - 1);
	int demdong = width - (wres - 1);

	int numans = demcot * demdong;
	int**addr = new int*[numans];
	int*ans = new int[numans];

	int*demw = new int[numans];
	int*deml = new int[numans];

	for (int i = 0; i < numans; i++) ans[i] = 0;

	int demans = 0;
	for (int f = 0; f < demdong; f++)
	{
		for (int g = 0; g < demcot; g++)
		{		
				addr[demans] = &a[f][g];
				demw[demans] = f;
				deml[demans] = g;
				for (int i = 0; i < wres; i++)
				{
					for (int j = 0; j < lres; j++)
					{
						ans[demans] += a[f+i][g+j];
					}
				}
				demans++;
		}

	}

	int max = ans[0];
	sub = addr[0];
	int index = 0;
	for (int i = 1; i < numans; i++)
	{
		if (ans[i]>max)
		{
			max = ans[i];
			sub = addr[i];
			index = i;
		}
	}

	int**anssub = new int*[wres];
	for (int i = 0; i < wres; i++)
		anssub[i] = new int[lres];

	anssub[0] = sub;
	anssub = &anssub[0];

	for (int i = 1; i < wres; i++)
	{
		anssub[i] = &a[demw[index]+i][deml[index]];
	}

	return anssub;


}
int LinearSearch(int* a, int n, int key) {
	int i = 0;
	while (i < n && a[i] != key)
		i++;
	if (i == n)
		return -1;
	return i;

}

int SentinelLinearSearch(int* a, int n, int key) {

	int flag = 0;
	int i = 0;
	for (i; i < n; i++)
		if (a[i] == key)
		{
			flag = 1; 
			break;
		}
	if (flag)
		return i;
	return -1;
}

int BinarySearch(int* a, int n, int key) {
	int l = 0;
	while (l <= n) {
		int mid = (l + n) / 2;
		if (a[mid] == key)
			return mid;
		if (key < a[mid])
			n = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
int RecursiveBinarySearch(int* a, int left, int right, int key) {

	if (left > right)
		return -1;

	else {

		int mid = (left + right) / 2;

		if (key == a[mid])
			return mid;
		else if (key > a[mid])
			return RecursiveBinarySearch(a, mid + 1, right, key);
		else
			return RecursiveBinarySearch(a, left, mid - 1, key);
	}
}


