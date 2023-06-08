#include <iostream>
#include <fstream>
using namespace std;

int somesum(int n, int &count_assign, int &count_compare) {
	count_assign = 0;
	count_compare = 0;
	int sum = 0, i = 1, j; count_assign += 2;

	while (++count_compare && i <= n) {

		j = n - i; ++count_assign;

		while (++count_compare && j <= i * i) {

			sum = sum + i * j; ++count_assign;
			j += 1; ++count_assign;
		}
		i += 1; ++count_assign;
	}

	return sum;
}

int squaresum_recursion(int n, int &count_assign, int &count_compare) {
	
	if (++count_compare && n < 1) return 0;
	else
	 return n * n + squaresum_recursion(n - 1,count_assign,count_compare);

}

int main() {
	int count_assign = 0;
	int count_compare = 0;

	ofstream f("cau1-2.xml", ios::binary);
	if (!f)
	{
		cout << "Khong mo duoc file";
		return 0;
	}
	
	f << "------------------- PROBLEM A -------------------" << endl;
	f << "n , assignments , comparisons" << endl;

	for (int i = 0; i <= 500 ; i+=25)
	{
		somesum(i, count_assign, count_compare);
		f << i << "," << count_assign << "," << count_compare << endl;
	}
	f << endl;


	f << "------------------- PROBLEM B -------------------" << endl;
	f << "n , assignments , comparisons" << endl;
	for (int i = 0; i <=500 ; i+=25)
	{
		count_assign = 0;
		count_compare = 0;

		squaresum_recursion(i, count_assign, count_compare);
		f << i << "," << count_assign << "," << count_compare << "," << endl;
	}

	f.close();
	return 0;
}