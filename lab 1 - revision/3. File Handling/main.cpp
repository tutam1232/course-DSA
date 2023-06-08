#include <iostream>
#include <fstream>
#include <string>
#include "func.h"
using namespace std;

int main() {

	ifstream f("data.txt");
	if (!f) {
		cout << "Khong the mo file" << endl;
		return 0;
	}
	string temp;
	getline(f, temp);
	getline(f, temp);
	f.close();

	Examinee ex=readExaminee(temp);
	printExaminee(ex);
	vector<Examinee> exlist = readExamineeList("data.txt");
	writeScores(exlist, "data3.txt");
	for (int i = 0; i < exlist.size(); i++)
	{
		printExaminee(exlist[i]);
	}
	

	return 0;
}