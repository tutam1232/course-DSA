#include "func.h"

vector<Company> ReadCompanyList(string file_name) {
	Company temp;
	vector<Company> list;

	ifstream f(file_name);
	if (!f) {
		cout << "Khong the mo file " << file_name << endl;
		return list;
	}
	string tempstring;
	getline(f, tempstring);

	while (!f.eof()) {
		getline(f, temp.name, '|');
		getline(f, temp.tax_code, '|');
		getline(f, temp.address);

		list.push_back(temp);
	}

	f.close();
	return list;
}

long long HashString(string company_name) {

	long long num = 0;
	long long m = 1000000009;

	unsigned long long temp1 = 0;
	unsigned long long temp2 = 0;
	unsigned long long temp3 = 0;

	if (company_name.size() <= 20)
	{
		for (int i = 0; i < company_name.size(); i++) {

			if (i <= 10) {
				temp1 = (unsigned long long)pow(31, i) % m;
				num += ((company_name[i] % m * temp1) % m) % m;
			}

			else {
				temp1 = (unsigned long long)pow(31, i - 10) % m;
				temp2 = (unsigned long long)pow(31, 10) % m;
				temp3 = (temp1*temp2) % m;
				num += ((company_name[i] % m * temp3) % m) % m;
			}

		}

		num = num % m;
	}

	else if (company_name.size() > 20)
	{
		int count = 0;

		for (int i = company_name.size() - 20; i < company_name.size(); i++) { //ok

			if (count <= 10) {
				temp1 = (unsigned long long)pow(31, count) % m;
				num += ((company_name[i] % m * temp1) % m) % m;
			}

			else {
				temp1 = (unsigned long long)pow(31, count - 10) % m;
				temp2 = (unsigned long long)pow(31, 10) % m;
				temp3 = (temp1*temp2) % m;
				num += ((company_name[i] % m * temp3) % m) % m;
			}
			count++;

		}

		num = num % m;
	}


	return num;
}
//chia du hashstring cho so pt cua list (2000) de ra vi tri
//tranh vong while vo tan => kiem tra mang da day` hay chua?
//ve nha xem lai xay dung hash table = linked list (thi?)

Company* CreateHashTable(vector<Company> list_company) {

	Company*table = new Company[SIZE];
	int index = -1;
	int tempindex = -1;
	bool flag = true;

	//long long has;//
	//ofstream ftemp("hashnum.txt");//

	for (int i = 0; i < list_company.size(); i++)
	{
		flag = true;
		//has = HashString(list_company[i].name);//
		//ftemp << has << endl;//
		index = HashString(list_company[i].name) % SIZE;
		tempindex = index;

		while (!table[index].name.empty())
		{
			index++;
			if (index >= SIZE)
				index = index - SIZE;
			if (index == tempindex) {
				flag = false;
				cout << "Bang bam khong con cho trong de them phan tu" << endl;
				break;
			}

		}
		if (flag == true)
			table[index] = list_company[i];

	}
	//ftemp.close();//

	return table;
}

void Insert(Company* hash_table, Company company) {

	int index = HashString(company.name) % SIZE;
	int tempindex = index;

	while (!hash_table[index].name.empty())
	{
		index++;
		if (index >= SIZE)
			index = index - SIZE;
		if (index == tempindex) {
			cout << "Bang bam khong con cho trong de them phan tu" << endl;
			return;
		}

	}
	cout << "Them cong ty thanh cong!" << endl;
	hash_table[index] = company;

}

Company* Search(Company* hash_table, string company_name) {

	Company*ans = new Company;

	int index = HashString(company_name) % SIZE;
	int tempindex = index;

	if (hash_table[index].name.empty()) {
		delete ans;
		return NULL;
	}

	while (hash_table[index].name != company_name)
	{
		index++;
		if (index >= SIZE)
			index = index - SIZE;
		if (hash_table[index].name.empty() || index == tempindex) {
			delete ans;
			return NULL;
		}

	}
	//cout << index << endl;//
	ans = &hash_table[index];

	return ans;

}