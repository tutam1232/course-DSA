#include <iostream>
#include "func.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using std::cout; 
using std::endl;
using std::vector; 
using std::string; 
using std::stringstream;
using std::ifstream;
using std::ofstream;

Examinee readExaminee(string line_info) {

	Examinee ex;
	stringstream temp(line_info);
	getline(temp, ex.id, ',');
	
	string tempgrade;
	getline(temp, tempgrade, ',');

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("")==0) ex.maths = 0;
	else ex.maths = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.literature = 0;
	else ex.literature = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.physics = 0;
	else ex.physics = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.chemistry = 0;
	else ex.chemistry = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.biology = 0;
	else ex.biology = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.history = 0;
	else ex.history = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.geography = 0;
	else ex.geography = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.civic_education = 0;
	else ex.civic_education = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.natural_science = 0;
	else ex.natural_science = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.social_science = 0;
	else ex.social_science = stof(tempgrade);

	getline(temp, tempgrade, ',');
	if (tempgrade.compare("") == 0) ex.foreign_language = 0;
	else ex.foreign_language = stof(tempgrade);

	getline(temp, tempgrade, ',');
	getline(temp, tempgrade, ',');

	return ex;
}

void printExaminee(Examinee ex) {
	cout << "So bao danh: " << ex.id.c_str() << endl;
	cout << "Toan: " << ex.maths << endl;
	cout << "Van: " << ex.literature << endl;
	cout << "Ly: " << ex.physics << endl;
	cout << "Hoa: " << ex.chemistry << endl;
	cout << "Sinh: " << ex.biology << endl;
	cout << "Su: " << ex.history << endl;
	cout << "Dia: " << ex.geography << endl;
	cout << "GDCD: " << ex.civic_education << endl;
	cout << "KHTN: " << ex.natural_science << endl;
	cout << "KHXH: " << ex.social_science << endl;
	cout << "Ngoai ngu: " << ex.foreign_language << endl;
	
	cout << endl;
}
vector<Examinee> readExamineeList(string file_name) {
	vector<Examinee> exlist;
	Examinee ex;
	ifstream f(file_name);
	if (!f) {
		cout << "Khong the mo file" << endl;
		return exlist;
	}
	string temp;

	getline(f, temp);

	while (!f.eof())
	{
		getline(f, temp);
		ex=readExaminee(temp);
		exlist.push_back(ex);
	}



	f.close();
	return exlist;
}

void writeScores(vector<Examinee> examinee_list, string out_file_name) {
	ofstream f(out_file_name);
	if (!f)
	{
		cout << "Khong the mo file";
		return;
	}

	f << "SBD BB KHTN KHXH";
	for (int i = 0; i < examinee_list.size(); i++)
	{
		f << endl;
		f << examinee_list[i].id.c_str() << " ";
		f << examinee_list[i].maths + examinee_list[i].literature + examinee_list[i].foreign_language << " ";
		examinee_list[i].natural_science = examinee_list[i].physics + examinee_list[i].chemistry + examinee_list[i].biology;
		f << examinee_list[i].natural_science << " ";
		examinee_list[i].social_science = examinee_list[i].history + examinee_list[i].geography + examinee_list[i].civic_education;
		f << examinee_list[i].social_science << " ";

	}

	f.close();
}