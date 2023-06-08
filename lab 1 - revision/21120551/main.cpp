#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "func.h"
using namespace std;

int main() {
	srand((unsigned)time(0));
	
	cout << "------------------ARRAY-------------------- " << endl;
	//cau 1
	int x = 1;
	int y = 2;
	int*a = &x;
	int*b = &y;
	cout << "Gia tri cua x va y truoc khi swap: ";
	cout << "x=" << x << " y=" << y << endl;
	swap(a, b);
	cout << "Gia tri cua x va y sau khi swap: ";
	cout << "x=" << x << " y=" << y << endl;
	cout << endl;
	//cau 2
	cout << "Tong cua x va y: " << *sum(a, b) << endl;
	cout << endl;
	//cau 3
	cout << "Nhap mang arr: " << endl;
	int n = 0;
	int*arr = NULL;

	inputArray(arr, n);
	//cau4
	cout << "In mang arr: " << endl;
	printArray(arr, n);
	//cau 5
	cout << "Gia tri lon nhat trong mang arr la: " << *findMax(arr, n) << endl;
	cout << endl;
	//cau 6
	int aa[] = { 1,2,3,2,6,4,5,7,10,4,2,4,5,6,7,80,1 };
	int numa = 17;
	int lengthans6 = 0;
	int*ans6 = findLongestAscendingSubarray(aa, numa, lengthans6);

	cout << "Mang aa: ";
	for (int i = 0; i < sizeof(aa) / sizeof(aa[0]); i++)
		cout << aa[i] << " ";
	cout << endl;

	cout << "Mang con tang lon nhat trong mang aa la: ";
	for (int i = 0; i < lengthans6; i++)
	{
		cout << ans6[i] << " ";
	}
	cout << endl << endl;


	//cau 7
	int nex = 4;
	int*ex = new int[nex];
	for (int i = 0; i < nex; i++)
	{
		ex[i] = 1 + rand() % 50;
	}
	cout << "Mang arr: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Mang ex: ";
	for (int i = 0; i < nex; i++)
	{
		cout << ex[i] << " ";
	}
	cout << endl << endl;

	cout << "Sau khi swap 2 mang: " << endl;
	swapArrays(arr, ex, n, nex);
	cout << "Mang arr: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Mang ex: ";
	for (int i = 0; i < nex; i++)
	{
		cout << ex[i] << " ";
	}
	cout << endl << endl;

	//cau 8
	int nc = 0;
	int *c = concatenate2Arrays(arr, ex, n, nex, nc);
	cout << "Noi mang ex vao mang arr: ";
	for (int i = 0; i < nc; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl << endl;
	//giai phong c:
	delete[] c;

	//cau 9
	int a1[] = { 1,3,5,7,9 };
	int a2[] = { 2,4,6,8 };
	c = merge2Arrays(a1, a2, 5, 4, nc);
	cout << "Mang a1: ";
	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); i++)
		cout << a1[i] << " ";
	cout << endl;
	cout << "Mang a2: ";
	for (int i = 0; i < sizeof(a2) / sizeof(a2[0]); i++)
		cout << a2[i] << " ";
	cout << endl;
	cout << "Noi mang a2 vao a1 va sap xep tang dan, ta duoc mang c: ";
	for (int i = 0; i < nc; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl << endl;
	cout << "------------------MATRIX-------------------- " << endl;
	//cau 10
	int width = 0;
	int length = 0;
	int**d;
	generateMatrix1(d, length, width);
	cout << "Ma tran d duoc tao ngau nhien: " << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	//cau 11
	int crow = 0;
	int ccol = 0;
	int**e=generateMatrix2(arr, ex, n, nex, crow, ccol);

	cout << "Ma tran e duoc tao tu mang arr va ex voi e[i][j] = arr[i] * ex[j]: " << endl;
	for (int i = 0; i < crow; i++)
	{
		for (int j = 0; j < ccol; j++) {
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//cau 12
	int s1 = 0;
	int s2 = 2;
	swapRows(d, length, width, s1, s2); //swap dong
	cout << "Ma tran d sau khi swap dong " << s1 << " va " << s2 << ": " << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;

	swapColumns(d, length, width, s1, s2); //swap cot
	cout << "Ma tran d sau khi swap cot " << s1 << " va " << s2 << ": " << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;

	//cau 13
	int**f=transposeMatrix(d, length, width);
	cout << "f la ma tran chuyen vi cua d: " << endl;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++) {
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	//cau 14
	int**ans;
	int lres = 0;
	int wres = 0;
	ans=concatenate2MatricesH(d, d, length, width, lres, wres); //ghep ngang
	cout << "Ghep ma tran d va d theo chieu ngang: " << endl;
	for (int i = 0; i < wres; i++)
	{
		for (int j = 0; j < lres; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int**ans2;
	int lres2 = 0;
	int wres2 = 0;
	ans2 = concatenate2MatricesV(d, d, length, width, lres2, wres2); //ghep doc
	cout << "Ghep ma tran d va d theo chieu doc: " << endl;
	for (int i = 0; i < wres2; i++)
	{
		for (int j = 0; j < lres2; j++) {
			cout << ans2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;

	//cau 15
	int check = 0; //kiem tra ma tran nhan duoc hay ko de giai phong vung nho
	int**res;
	int lengthr = 0;
	int widthr = 0;
	if (ccol == width) cout << "Ma tran e*d: " << endl;
	else if (crow == length) cout << "Ma tran d*e: " << endl;
	if (multiple2Matrices(res, e, d, lengthr, widthr, ccol, crow,length, width)) {
		check = 1;
		for (int i = 0; i < widthr; i++)
		{
			for (int j = 0; j < lengthr; j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
		cout << "Hai ma tran nay khong nhan duoc" << endl << endl;

	//cau 16
	int**ans16;
	int l16;
	int w16;
	ans16 = findSubmatrix(d, length, width, l16, w16);
	if (ans16 == NULL)
		cout << "Khong the tim ma tran con" << endl;
	else {
		cout << "Ma tran con lon nhat (" << w16 << "x" << l16 << ") trong ma tran d la: " << endl;
		for (int i = 0; i < w16; i++)
		{
			for (int j = 0; j < l16; j++) {
				cout << ans16[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << "------------------SEARCHING ALGORITHMS-------------------- " << endl;

	//cau 17
	cout << "Linear Search: " << endl;
	int key = 10;
	cout << "Mang aa: ";
	for (int i = 0; i < sizeof(aa) / sizeof(aa[0]); i++)
		cout << aa[i] << " ";
	cout << endl;
	cout << "Vi tri tim thay so " << key << " trong mang aa la (-1 neu khong tim thay): " << LinearSearch(aa, numa, key) << endl;
	key = 10000;
	cout << "Vi tri tim thay so " << key << " trong mang aa la (-1 neu khong tim thay): " << LinearSearch(aa, numa, key) << endl;
	cout << endl;
	//cau 18
	cout << "Linear Search (use flag): " << endl;
	key = 7;
	cout << "Mang aa: ";
	for (int i = 0; i < sizeof(aa) / sizeof(aa[0]); i++)
		cout << aa[i] << " ";
	cout << endl;
	cout << "Vi tri tim thay so " << key << " trong mang aa la (-1 neu khong tim thay): " << SentinelLinearSearch(aa, numa, key) << endl;
	key = -9;
	cout << "Vi tri tim thay so " << key << " trong mang aa la (-1 neu khong tim thay): " << SentinelLinearSearch(aa, numa, key) << endl;
	cout << endl;
	//cau 19
	cout << "Binary Search: " << endl;
	cout << "Mang c: ";
	for (int i = 0; i < nc; i++)
		cout << c[i] << " ";
	cout << endl;
	key = 3;
	cout << "Vi tri tim thay so " << key << " trong mang c la (-1 neu khong tim thay): " << BinarySearch(c, nc, key) << endl;
	key = -6;
	cout << "Vi tri tim thay so " << key << " trong mang c la (-1 neu khong tim thay): " << BinarySearch(c, nc, key) << endl;
	cout << endl;

	//cau 20
	cout << "Binary Search (dung de quy): " << endl;
	cout << "Mang c: ";
	for (int i = 0; i < nc; i++)
		cout << c[i] << " ";
	cout << endl;
	key = 5;
	cout << "Vi tri tim thay so " << key << " trong mang c la (-1 neu khong tim thay): " << RecursiveBinarySearch(c, 0, nc, key) << endl;
	key = 100;
	cout << "Vi tri tim thay so " << key << " trong mang c la (-1 neu khong tim thay): " << RecursiveBinarySearch(c, 0, nc, key) << endl;
	cout << endl;

	//giai phong vung nho
	delete[] arr;
	delete[] ex;
	delete[] c;
	delete[] ans6;

	for (int i = 0; i < width; i++)
		delete[] d[i];
	delete[] d;

	//gan lai con tro bang NULL sau khi giai phong vung nho de tranh con tro treo
	for (int i = 0; i < w16; i++)
	{
		ans16[i] = NULL;
	}
	ans16 = NULL;

	for (int i = 0; i < crow; i++)
		delete[] e[i];
	delete[] e;

	for (int i = 0; i < length; i++)
		delete[] f[i];
	delete[] f;

	for (int i = 0; i < wres; i++)
		delete[] ans[i];
	delete[] ans;

	for (int i = 0; i < wres2; i++)
		delete[] ans2[i];
	delete[] ans2;

	if (check==1)
	{
		for (int i = 0; i < widthr; i++)
			delete[] res[i];
		delete[] res;
	}
	

	return 0;

}

