#include "func.h"

int main() {

	string file_name = "data.txt";
	vector<Company> list = ReadCompanyList(file_name);
	Company*table = CreateHashTable(list);	

	/*ofstream fout("hash.txt");
	for (int i = 0; i < SIZE; i++)
	{
		fout << table[i].name << "|" << table[i].tax_code << "|" << table[i].address << endl;
	}
	fout.close();*/


	string comp_name;
	Company temp;

	cout << "[Them cong ty]" << endl;
	cout << "Nhap ten cong ty: ";
	getline(cin, temp.name);
	cout << "Nhap ma so thue: ";
	getline(cin, temp.tax_code);
	cout << "Nhap dia chi: ";
	getline(cin, temp.address);
	Insert(table, temp);

	cout << endl;
	cout << "[Tim cong ty]" << endl;
	cout << "Nhap ten cong ty: ";
	getline(cin, comp_name);
	Company*search = Search(table, comp_name);
	if (search == NULL)
		cout << "Cong ty can tim khong ton tai!" << endl;
	else {
		cout << "Ten cong ty: " << search->name << endl;
		cout << "Ma so thue: " << search->tax_code << endl;
		cout << "Dia chi: " << search->address << endl;
	}


	delete[] table;
	search = NULL;
	return 0;
}