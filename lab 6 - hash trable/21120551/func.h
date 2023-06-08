#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#define SIZE 2000
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Company
{
	string name;
	string tax_code;
	string address;
};vector<Company> ReadCompanyList(string file_name);long long HashString(string company_name);Company* CreateHashTable(vector<Company> list_company);Company* Search(Company* hash_table, string company_name);void Insert(Company* hash_table, Company company);