#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct Animal
{
	string en;
	string vn;
	string ph;
	int loai;
};
struct NodeAnimal
{
	Animal data;
	NodeAnimal*pNext;
};
struct AVLNode
{
	int key;
	AVLNode* pLeft;
	AVLNode* pRight;
	int height;
};
int height(AVLNode*a) {
	if (a == NULL)
		return 0;
	return a->height;

}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

void RotateRight(AVLNode*&a) {
	AVLNode*b = a->pLeft;
	AVLNode*T2 = b->pRight;
	b->pRight = a;
	a->pLeft = T2;

	a = b;
	b = a->pRight;
	b->height = max(height(b->pLeft), height(b->pRight)) + 1;
	a->height = max(height(a->pLeft), height(a->pRight)) + 1;
}
void RotateLeft(AVLNode*&a) {
	AVLNode*b = a->pRight;
	AVLNode*T2 = b->pLeft;
	b->pLeft = a;
	a->pRight = T2;

	a = b;
	b = a->pLeft;
	b->height = max(height(b->pLeft), height(b->pRight)) + 1;
	a->height = max(height(a->pLeft), height(a->pRight)) + 1;
}
AVLNode*CreateNode(int x) {

	AVLNode*a = new AVLNode;
	a->height = 1;
	a->key = x;
	a->pLeft = a->pRight = NULL;

	return a;
}
void Insert(AVLNode*&pRoot, int x) {

	if (pRoot == NULL)
		pRoot = CreateNode(x);

	else if (x < pRoot->key) {
		Insert(pRoot->pLeft, x);
		if ((height(pRoot->pLeft) - height(pRoot->pRight)) > 1) {
			if (x < pRoot->pLeft->key)
				RotateRight(pRoot);
			else {
				RotateLeft(pRoot->pLeft);
				RotateRight(pRoot);
			}
		}
	}

	else if (x > pRoot->key) {
		Insert(pRoot->pRight, x);
		if ((height(pRoot->pRight) - height(pRoot->pLeft)) > 1) {

			if (x > pRoot->pRight->key)
				RotateLeft(pRoot);
			else {
				RotateRight(pRoot->pRight);
				RotateLeft(pRoot);
			}

		}
	}

	else if (x == pRoot->key) {
		cout << "Node da ton tai tren cay AVL!" << endl;
		return;
	}

	pRoot->height = max(height(pRoot->pLeft), height(pRoot->pRight)) + 1;
	
}

AVLNode* createAVL(int* arr, int n) {
	
	AVLNode*pRoot = NULL;
	for (int i = 0; i < n; i++)
	{
		Insert(pRoot, arr[i]);
	}

	return pRoot;
}

bool isAVL(AVLNode* root){

	if (root == NULL)
		return true;
	int lh = height(root->pLeft);
	int rh = height(root->pRight);
	if ((abs(lh - rh) <= 1) && (isAVL(root->pLeft) == true) && (isAVL(root->pRight) == true))
		return true;
	return false;

}

//---------------------------------------------------- cau 2

vector<Animal> readAnimals(string filename) {

	vector<Animal> ans;
	Animal dv;
	string temp;

	ifstream f(filename);
	if (!f) {
		cout << "Khong the mo file " << filename << endl;
		return ans;
	}

	while (!f.eof())
	{
		getline(f, temp);
		dv.en = temp;
		getline(f,temp);
		dv.ph = temp;
		getline(f, temp);
		dv.vn = temp;
		getline(f, temp);
		dv.loai = stoi(temp);

		ans.push_back(dv);
	}

	f.close();

	return ans;
}

void printAnimal(vector<Animal> list) {
	for (int i = 0; i < list.size(); i++)
		cout << list[i].en << "-" << list[i].vn << "-" << list[i].ph << "-" << list[i].loai << endl;

}

int Hash(string name) {
	return (name[0] % 65);
}



NodeAnimal*CreateAnimal(Animal data) {

	NodeAnimal*a = new NodeAnimal;
	a->data = data;
	a->pNext = NULL;

	return a;
}

NodeAnimal** CreateHashTable(vector<Animal> list) {
	NodeAnimal**table = new NodeAnimal*[26];
	for (int i = 0; i < 26; i++)
	{
		table[i] = new NodeAnimal;
		table[i]->data.en = "";
	}

	int index = 0;
	NodeAnimal*count = NULL;

	for (int i = 0; i < list.size(); i++)
	{
		index = Hash(list[i].en) % 26;

		if (table[index]->data.en.empty() == true) { //neu rong
			table[index] = CreateAnimal(list[i]);
		}
		else {
			count = table[index];
			while (count->pNext != NULL)
				count = count->pNext;
			count->pNext = CreateAnimal(list[i]);
		}
	}

	return table;
}

//---------------------------------------------- cau 3

void DFS(int**graph, bool visited[], int dinh, int n, vector<int> &dinhDT) {

	dinhDT.push_back(dinh);
	visited[dinh] = true;
	for (int i = 0; i < n; i++)
	{
		if (graph[dinh][i] == 1 && visited[i] == false)
			DFS(graph, visited, i, n, dinhDT);
	}
}


int minimumEdges(int** graph, int n, int k) {

	vector < vector<int>> TPLT;
	vector<int> temp;
	bool*visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false) {
			DFS(graph, visited, i, n, temp);
			TPLT.push_back(temp);
			temp.clear();
		}
	}

	vector<vector<int>> dinhremove;
	vector<int>tempdinh;

	bool flagremove = true;
	for (int i = 0; i < TPLT.size(); i++)
	{
		for (int j = 0; j < TPLT[i].size(); j++) {

			//em chưa làm xong chỗ này

		}
	}

	bool flag = true;
	vector<int> index;
	for (int i = 0; i < TPLT.size(); i++)
	{
		if (TPLT[i].size() % k != 0) {
			flag = false;
			index.push_back(i);
		}
	}
	if (flag = true)
		return 0; // nếu số cạnh của các tp liên thông đều chia hết cho k => thêm 0 cạnh
	   
	return -1;
}

int main() {

	vector<Animal> list = readAnimals("data.txt");
	printAnimal(list);

	cout << endl << endl << "Hash Table" << endl << endl;

	NodeAnimal**table = CreateHashTable(list);

	NodeAnimal*count = NULL;
	for (int i = 0; i < 26; i++)
	{
		count = table[i];
		if (count->data.en.empty() == true) {
			cout << endl;
			continue;
		}
		while (count != NULL)
		{
			cout << count->data.en << "-" << count->data.vn << "-" << count->data.ph << "-" << count->data.loai << endl;
			count = count->pNext;
		}
	}

	delete[] table;

	return 0;
}