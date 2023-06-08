#include <iostream>
#include <fstream>
using namespace std;


bool MajorityElement1(int a[], int n, int k, int& count_assign, int& count_compare) {

	count_assign = 0;
	count_compare = 0;

	int num = 0; ++count_assign;

	++count_assign;
	for (int i = 0; ++count_compare && i < n; ++count_assign && i++)
	{
		if (++count_compare && a[i] == k) {
			num++;
			++count_assign;
		}
			
	}
	if (++count_compare && num>n/2)
		return true;
	return false;
}

bool MajorityElement2(int a[], int n, int k, int &num, int start, int& count_assign, int& count_compare) {

	if (start == n && num > n / 2)
		count_compare += 2;
	else if (start == n && num <= n / 2)
		count_compare += 4;
	else
		count_compare += 2;


	if (start==n && num > n / 2)
		return true;
	else if (start == n && num <= n / 2)
		return false;


	if (++count_compare && a[start] == k) {
		num++;
		count_assign++;
	}
		
	return MajorityElement2(a, n, k, num, start + 1, count_assign, count_compare);

}


int main() {

	int a[] = { 1,1,0,3,2,6,1,1,1,1 };

	int count_assign = 0;
	int count_compare = 0;

	ofstream f("cau1-2.csv", ios::binary);
	if (!f)
	{
		cout << "Khong mo duoc file";
		return 0;
	}

	f << "------------------- PROBLEM A - Majority Element 1 -------------------" << endl;
	f << "n , assignments , comparisons" << endl;
	int temp = MajorityElement1(a, 10, 1, count_assign, count_compare);
	cout << temp << endl;
	f << 5 << "," << count_assign << "," << count_compare << endl;
	f << endl;

	f << "------------------- PROBLEM A - Majority Element 2 (recursion) -------------------" << endl;
	f << "n , assignments , comparisons" << endl;
	count_assign = count_compare = 0;
	int num = 0;

	temp = MajorityElement2(a, 10, 1, num, 0, count_assign, count_compare);
	cout << temp << endl;
	f << 5 << "," << count_assign << "," << count_compare << endl;
	f << endl;


	f.close();
	return 0;
}