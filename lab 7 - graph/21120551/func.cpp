#include "func.h"

//nam vung BFS, DFS de thi

void PrintVector(vector<vector<int>> a) {
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> CovertList(string filename) {

	vector<vector<int>> ans;

	ifstream f(filename);
	if (!f) {
		cout << "Cannot open file " << filename << endl;
		return ans;
	}
	int n = 0;
	f >> n;

	int value = 0;
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f >> value;
			if (value == 1)
				temp.push_back(j);
		}
		ans.push_back(temp);
		temp.clear();
	}

	f.close();
	return ans;
}

vector<vector<int>> ConvertMatrix(string filename) {

	vector<vector<int>> ans;

	ifstream f(filename);
	if (!f)
	{
		cout << "Cannot open file " << filename << endl;
		return ans;
	}

	int n = 0;
	f >> n;
	
	
	vector<string> list;
	string temp;
	getline(f, temp);

	for (int i = 0; i < n; i++)
	{		
		getline(f, temp);
		list.push_back(temp);
		temp.clear();
	}

	vector<int> row;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)//
		{

			if (list[i].size() == 0) {
				row.push_back(0);
				continue;
			}

			else if (list[i][count] == ' ') {
				count++;
				//row.push_back(0);
				//if (count == list[i].size())
					//count--;
			}				

			if (list[i][count] == (j + 48)) {
				row.push_back(1);
				count++;
				if (count == list[i].size())
					count--;
			}
			else
				row.push_back(0);

		}
		ans.push_back(row);
		row.clear();
	}

	f.close();
	return ans;
	
}

int DirectedOrUndirected(vector<vector<int>> matrix) {
	//directed will return 1, undirected will return 0

	bool flag = true;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == true)
	{
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				if (matrix[i][j] != matrix[j][i])
					return 1;
			}
		}
		return 0;
	}
	else{

		ofstream f("file.txt");
		if (!f)
		{
			cout << "Cannot open file file.txt";
			return -1;
		}
		f << matrix.size() << endl;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++) {
				f << matrix[i][j];
				if (j != (matrix[i].size() - 1))
					f << " ";
			}
			if (i != (matrix.size() - 1))
				f << endl;
		}
		f.close();

		vector<vector<int>> matrix2 = ConvertMatrix("file.txt");

		for (int i = 0; i < matrix2.size(); i++) {
			for (int j = 0; j < matrix2.size(); j++) {
				if (matrix2[i][j] != matrix2[j][i])
					return 1;
			}
		}
		return 0;
	}

}

int VerticesNum(vector<vector<int>> matrix) {
	return matrix.size();
}

int EdgesNum(vector<vector<int>> matrix) {

	if (DirectedOrUndirected(matrix) == 1) { //if directed

		bool flag = true;
		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[i].size() != matrix.size())
				flag = false;
			break;
		}

		if (flag == true) { //matrix 
			int count = 0;
			for (int i = 0; i < matrix.size(); i++)
				for (int j = 0; j < matrix[i].size(); j++)
					if (matrix[i][j] == 1)
						count++;
			return count;
		}

		else { //list
			int count = 0;
			for (int i = 0; i < matrix.size(); i++)
				count += matrix[i].size();
			return count;
		}

	}

	else { //if undirected

		bool flag = true;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i].size() != matrix.size())
				flag = false;
			break;
		}

		if (flag == true) { //if matrix
			int count = 0;
			for (int i = 0; i < matrix.size(); i++)
				for (int j = 0; j < matrix[i].size(); j++)
					if (matrix[i][j] == 1)
						count++;
			return (count / 2);
		}

		else { //if list
			int count = 0;
			for (int i = 0; i < matrix.size(); i++)
				count += matrix[i].size();
			return (count / 2);
		}

	}

}

vector<int> DegreeUndirected(vector<vector<int>> matrix) {

	vector<int> ans;

	bool flag = true;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == true) { //matrix
		int count = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			count = 0;
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 1)
					count++;
			}
			ans.push_back(count);
		}

	}

	else { //list
		for (int i = 0; i < matrix.size(); i++)
		{
			ans.push_back(matrix[i].size());
		}
	}

	return ans;
}

vector<vector<int>> DegreeDirected(vector<vector<int>> matrix) {

	vector<vector<int>> ans;
	vector<int> temp;

	bool flag = true;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == true) {//matrix


		int outdeg = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			outdeg = 0;
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 1)
					outdeg++;
			}
			temp.push_back(outdeg);
		}

		ans.push_back(temp);
		temp.clear();

		int indeg = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			indeg = 0;
			for (int j = 0; j < matrix.size(); j++) {
				if (matrix[j][i] == 1)
					indeg++;
			}
			temp.push_back(indeg);
		}
		ans.push_back(temp);

	}
	else {//list

		for (int i = 0; i < matrix.size(); i++)
		{
			temp.push_back(matrix[i].size());
		}
		ans.push_back(temp);
		temp.clear();


		int indeg = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			indeg = 0;
			for (int j = 0; j < matrix.size(); j++)
			{
				for (int k = 0; k < matrix[j].size(); k++)
				{
					if (matrix[j][k] == i)
						indeg++;
				}
			}
			temp.push_back(indeg);
		}
		ans.push_back(temp);

	}

	return ans;

}

vector<int> IsolatedVertices(vector<vector<int>> matrix) {

	vector<int> ans;

	if (DirectedOrUndirected(matrix) == 1) { //directed
		vector <vector<int>> deg = DegreeDirected(matrix);

		for (int i = 0; i < deg[0].size(); i++)
		{
			if (deg[0][i] == 0 && deg[1][i] == 0)
				ans.push_back(i);
		}

	}

	else { //undirected
		vector<int> deg = DegreeUndirected(matrix);

		for (int i = 0; i < deg.size(); i++)
		{
			if (deg[i] == 0)
				ans.push_back(i);
		}

	}

	return ans;

}

vector<int> LeafVertices(vector<vector<int>> matrix) {  //check directed leaf?

	vector<int> ans;

	if (DirectedOrUndirected(matrix) == 1) { //directed
	
		vector <vector<int>> deg = DegreeDirected(matrix);

		for (int i = 0; i < deg[0].size(); i++)
		{
			if ((deg[0][i] == 1 && deg[1][i] == 0) || (deg[0][i] == 0 && deg[1][i] == 1))
				ans.push_back(i);
		}

	}

	else { //undirected //check?

		vector<int> deg = DegreeUndirected(matrix);
		for (int i = 0; i < deg.size(); i++)
		{
			if (deg[i] == 1)
				ans.push_back(i);
		}

	}


	return ans;
}


bool CircularGraph(int v, bool visited[], int parent, vector<vector<int>> matrix) { //true: is circular, false: not circular

	visited[v] = true;

	for (int i = 0; i < matrix[v].size(); i++) {

		if (matrix[v][i] == 0)
			continue;

		if (matrix[v][i] == 1 && visited[i] == false) {
			if (CircularGraph(i, visited, v, matrix) == true)
				return true;
		}
		else if (i != parent)
			return true;
		
	}
	return false;
}

bool isCircular(vector<vector<int>> matrix) {

	bool *visited = new bool[matrix.size()];
	for (int i = 0; i < matrix.size(); i++)
		visited[i] = false;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (visited[i] == false)
			if (CircularGraph(i, visited, -1, matrix) == true)
			{
				delete[] visited;
				return true;
			}
	}

	delete[] visited;
	return false;

}

bool CircularGraphDirected(int v, bool visited[], bool cur[], vector<vector<int>> matrix){
	
	if (visited[v] == false)
	{
		visited[v] = true;
		cur[v] = true;

		for (int i = 0; i < matrix[v].size(); i++)
		{
			if (matrix[v][i] == 0)
				continue;
			if (matrix[v][i] == 1 && visited[i] == false && CircularGraphDirected(i, visited, cur, matrix))
				return true;
			else if (cur[i] == true)
				return true;
		}

	}
	cur[v] = false;
	return false;
}

bool isCircularDirected(vector<vector<int>> matrix) {

	bool *visited = new bool[matrix.size()];
	bool *cur = new bool[matrix.size()];
	for (int i = 0; i < matrix.size(); i++)
	{
		visited[i] = false;
		cur[i] = false;
	}

	for (int i = 0; i < matrix.size(); i++)
		if (visited[i] == false && CircularGraphDirected(i, visited, cur, matrix) == true) {
			delete[] visited;
			delete[] cur;
			return true;
		}

	delete[] visited;
	delete[] cur;
	return false;

}

//DFS 
//int CircularGraph(vector<vector<int>> matrix, int v) { //ref: https://nhannguyen95.github.io/kiem-tra-chu-trinh-trong-do-thi-co-huong/
//			
//	//duyet dinh v
//
//	static int*visited = new int[matrix.size()]();
//
//	visited[v] == 1;
//	
//	for (int u = 0; u < matrix[v].size(); u++) {
//
//		if (matrix[v][u] == 1 && visited[u] == 0) {
//			int z = CircularGraph(matrix, u);
//			if (z == 1)
//				return 1;
//		}
//		if (matrix[v][u] == 1 && visited[u] == 1) {
//			return 1; //1 is circular graph
//		}
//	}
//
//	visited[v] = 2;
//
//	return 0; //0 is not a circular graph
//
//}

bool isBigraph(vector<vector<int>> matrix, int source, vector<int> &ver0, vector<int> &ver1) {
	vector<int> color;
	for (int i = 0; i < matrix.size(); ++i)
		color.push_back(-1);

	color[source] = 1;
	ver1.push_back(source);

	queue <int> q;
	q.push(source);

	while (q.empty() == false)
	{
		int u = q.front();
		q.pop();

		if (matrix[u][u] == 1)
			return false;

		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[u][i] == 1 && color[i] == -1)
			{
				color[i] = 1 - color[u];
				q.push(i);

				if (color[i] == 1)
					ver1.push_back(i);
				else
					ver0.push_back(i);
			}

			else if (matrix[u][i] == 1 && color[i] == color[u])
				return false;
		}
	}
	return true;
}

bool isCompleteBigraph(vector<vector<int>> matrix, vector<int> ver0, vector<int> ver1) {

	//sort(ver0.begin(), ver0.end()); //tang dan
	//sort(ver1.begin(), ver1.end());

	for (int i = 0; i < ver0.size(); i++)
	{
		for (int j = 0; j < ver1.size(); j++) {

			if (matrix[ver0[i]][ver1[j]] == 0)
				return false;

		}
	}

	for (int i = 0; i < ver1.size(); i++)
	{
		for (int j = 0; j < ver0.size(); j++) {

			if (matrix[ver1[i]][ver0[j]] == 0)
				return false;

		}
	}


	return true;

}

void SpecialGraph(vector<vector<int>> matrix) {
	//0: not special
	//1: complete graph
	//2: circular graph
	//3: bigraph
	//4: complete bigraph

	int edge = EdgesNum(matrix);
	int vertice = VerticesNum(matrix);

	if (edge == (vertice*(vertice - 1) / 2))
		cout << "This is a Complete graph!" << endl;
	else
		cout << "This is not a Complete graph" << endl;

	bool flag = true;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == false) {

		ofstream f("file.txt");
		if (!f)
		{
			cout << "Cannot open file file.txt";
			return;
		}
		f << matrix.size() << endl;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++) {
				f << matrix[i][j];
				if (j != (matrix[i].size() - 1))
					f << " ";
			}
			if (i != (matrix.size() - 1))
				f << endl;
		}
		f.close();
		matrix = ConvertMatrix("file.txt");
	}

	if (DirectedOrUndirected(matrix) == 1) {
		if (isCircularDirected(matrix) == true)
			cout << "This is a circular graph!" << endl;
		else
			cout << "This is not a circular graph" << endl;
	}
	else {
		if (isCircular(matrix) == true)
			cout << "This is a circular graph!" << endl;
		else
			cout << "This is not a circular graph" << endl;
	}


	vector<int> ver0;
	vector<int> ver1;
	//
	if (isBigraph(matrix, 0, ver0, ver1) == true) {
		cout << "This is a bigraph!" << endl;
		if (isCompleteBigraph(matrix, ver0, ver1) == true)
			cout << "This is a complete bigraph!" << endl;
		else
			cout << "This is not a complete bigraph" << endl;
	}
	else
		cout << "This is not a bigraph" << endl << "This is not a complete bigraph" << endl;

}

int ConnectedComponentsNum(vector<vector<int>> matrix, vector<vector<vector<int>>> &subgraph) {

	bool flag = true;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == false) {

		ofstream f("file.txt");
		if (!f)
		{
			cout << "Cannot open file file.txt";
			return -1;
		}
		f << matrix.size() << endl;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++) {
				f << matrix[i][j];
				if (j != (matrix[i].size() - 1))
					f << " ";
			}
			if (i != (matrix.size() - 1))
				f << endl;
		}
		f.close();
		matrix = ConvertMatrix("file.txt");
	}

	//----------------------------------------------

	vector<bool> visited;
	for (int i = 0; i < matrix.size(); i++)
		visited.push_back(false);

	int count = 0;
	vector<vector<int>>sub;
	vector<int>list;
	vector<int> listremove;

	vector<int>temp;
	int templist;

	for (int i = 0; i < matrix.size(); i++) {
		if (visited[i] == false) {
			DFS(i, visited, matrix,sub,list);
			count++;

			for (int i = 0; i < matrix.size(); i++)
				listremove.push_back(i);

			for (int i = 0; i < sub.size()-1; i++)
			{
				for (int j = i + 1; j < sub.size(); j++)
					if (list[i] > list[j]) {
						temp = sub[i];
						sub[i] = sub[j];
						sub[j] = temp;

						templist = list[i];
						list[i] = list[j];
						list[j] = templist;
					}
			}

			sort(list.begin(), list.end(), greater<>());

			for (int i = 0; i < list.size(); i++)
				listremove.erase(listremove.begin()+list[i]);

			sort(listremove.begin(), listremove.end(), greater<>());

			for (int i = 0; i < sub.size(); i++)
				for (int j = 0; j < listremove.size(); j++)
					sub[i].erase(sub[i].begin() + listremove[j]);				
			subgraph.push_back(sub);

		}
		sub.clear();
		list.clear();
		listremove.clear();

	}

	return count;

}

void DFS(int v, vector<bool> &visited, vector<vector<int>> matrix, vector<vector<int>>& sub, vector<int> &list) {

	visited[v] = true;
	sub.push_back(matrix[v]);
	list.push_back(v);

	for (int i = 0; i < matrix[v].size(); i++)
		if (matrix[v][i] == 1 && visited[i] == false) 
			DFS(i, visited, matrix,sub,list);
		
	

}

int countTree(vector<vector<vector<int>>> subgraph){

	int count = 0;

	for (int k = 0; k < subgraph.size(); k++)
	{		

		if (isCircular(subgraph[k]) == true)
			continue;
		
		count++;
	}
	
	return count;
}

void Bridge(vector<vector<int>> matrix, int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, int &count) {

	static int time = 0;

	visited[u] = true;

	disc[u] = low[u] = ++time;

	for (int i = 0; i < matrix[u].size(); i++) {

		if (matrix[u][i] == 1 && visited[i] == false) {

			parent[i] = u;
			Bridge(matrix, i, visited, disc, low, parent, count);

			low[u] = min(low[u], low[i]);

			if (low[i] > disc[u]) {
				count++;
				//cout << u << " " << i << endl;
			}
		}

		else if (matrix[u][i] == 1 && i != parent[u])
			low[u] = min(low[u], disc[i]);
	}
}
int bridgeCount(vector<vector<int>> matrix) {

	bool flag = true;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == false) {

		ofstream f("file.txt");
		if (!f)
		{
			cout << "Cannot open file file.txt";
			return NULL;
		}
		f << matrix.size() << endl;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++) {
				f << matrix[i][j];
				if (j != (matrix[i].size() - 1))
					f << " ";
			}
			if (i != (matrix.size() - 1))
				f << endl;
		}
		f.close();
		matrix = ConvertMatrix("file.txt");
	}

	//------------------------------------------

	vector<bool> visited;
	vector<int> disc;
	vector<int> low;
	vector<int> parent;
	int count = 0;

	for (int i = 0; i < matrix.size(); i++)
	{		
		visited.push_back(false);
		disc.push_back(NULL);
		low.push_back(NULL);
		parent.push_back(NULL);
	}

	for (int i = 0; i < matrix.size(); i++)
		if (visited[i] == false)
			Bridge(matrix, i, visited, disc, low, parent, count);

	return count;
}

void CutVertice(vector<vector<int>> matrix , int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, int& time, int parent, vector<bool> &isCV)
{

	int child = 0;
	visited[u] = true;
	disc[u] = low[u] = time++;

	for (int i = 0; i < matrix[u].size(); i++) {
		
		if (matrix[u][i] == 1 && visited[i]==false) {
			child++;
			CutVertice(matrix, i, visited, disc, low, time, u, isCV);

			low[u] = min(low[u], low[i]);

			if (parent != -1 && low[i] >= disc[u])
				isCV[u] = true;
		}

		else if (matrix[u][i] == 1 && i != parent)
			low[u] = min(low[u], disc[i]);
	}

	if (parent == -1 && child > 1)
		isCV[u] = true;
}

int countCutVertice(vector<vector<int>> matrix) {

	bool flag = true;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			flag = false;
		break;
	}

	if (flag == false) {

		ofstream f("file.txt");
		if (!f)
		{
			cout << "Cannot open file file.txt";
			return NULL;
		}
		f << matrix.size() << endl;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++) {
				f << matrix[i][j];
				if (j != (matrix[i].size() - 1))
					f << " ";
			}
			if (i != (matrix.size() - 1))
				f << endl;
		}
		f.close();
		matrix = ConvertMatrix("file.txt");
	}

	vector<int> disc;
	vector<int> low;
	vector<bool> visited;
	vector<bool> isCV;
	int time = 0;
	int par = -1;
	int count = 0;

	for (int i = 0; i < matrix.size(); i++)
	{
		disc.push_back(0);
		low.push_back(NULL);
		visited.push_back(false);
		isCV.push_back(false);

	}
	
	for (int i = 0; i < matrix.size(); i++)
		if (visited[i] == false)
			CutVertice(matrix, i, visited, disc, low, time, par, isCV);

	for (int i = 0; i < matrix.size(); i++)
		if (isCV[i] == true)
			count++;

	return count;
}

//void DegreeOfVertices(vector<vector<int>> matrix) {
//
//	if (DirectedOrUndirected(matrix) == 1) { //directed
//		bool flag = true;
//		for (int i = 0; i < matrix.size(); i++)
//		{
//			if (matrix[i].size() != matrix.size())
//				flag = false;
//			break;
//		}
//
//		if (flag == true) {//matrix
//			
//			
//			int outdeg = 0;
//			for (int i = 0; i < matrix.size(); i++)
//			{
//				outdeg = 0;
//				for (int j = 0; j < matrix[i].size(); j++)
//				{
//					if (matrix[i][j] == 1)
//						outdeg++;
//				}
//				cout << "Out-degree of vertice " << i << ": " << outdeg << endl;
//			}
//
//			cout << endl;
//
//			int indeg = 0;
//			for (int i = 0; i < matrix.size(); i++)
//			{
//				indeg = 0;
//				for (int j = 0; j < matrix.size(); j++) {
//					if (matrix[j][i] == 1)
//						indeg++;
//				}
//				cout << "In-degree of vertice " << i << ": " << indeg << endl;
//			}
//
//		}
//		else {//list
//
//			for (int i = 0; i < matrix.size(); i++)
//			{
//				cout << "Out-degree of vertice " << i << ": " << matrix[i].size() << endl;
//			}
//			cout << endl;
//
//			int indeg = 0;
//
//			for (int i = 0; i < matrix.size(); i++)
//			{
//				indeg = 0;
//				for (int j = 0; j < matrix.size(); j++)
//				{
//					for (int k = 0; k < matrix[j].size(); k++)
//					{
//						if (matrix[j][k] == i)
//							indeg++;
//					}
//				}
//				cout << "In-degree of vertice " << i << ": " << indeg << endl;
//			}
//
//		}
//	}
//
//	else { //undirected
//
//		bool flag = true;
//		for (int i = 0; i < matrix.size(); i++)
//		{
//			if (matrix[i].size() != matrix.size())
//				flag = false;
//			break;
//		}
//
//		if (flag == true) { //matrix
//			int count = 0;
//			for (int i = 0; i < matrix.size(); i++)
//			{
//				count = 0;
//				for (int j = 0; j < matrix[i].size(); j++)
//				{
//					if (matrix[i][j] == 1)
//						count++;
//				}
//				cout << "Degree of vertice " << i << ": " << count << endl;
//			}
//
//		}
//
//		else { //list
//			for (int i = 0; i < matrix.size(); i++)
//			{
//				cout << "Degree of vertice " << i << ": " << matrix[i].size() << endl;
//			}
//		}
//	}
//
//}