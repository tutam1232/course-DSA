#include "func.h"

int main() {

	vector<vector<vector<int>>> subgraph;
	vector<vector<int>> degdirected;
	vector<int> degundirected;
	vector<int> isolated;
	vector<int> leaf;

	//file graph1.txt va graph2.txt la do thi co huong (file goc cua lab nay)

	//cac file dung de test:

	//file graph11.txt va graph12.txt la do thi vo huong
	//file graph14.txt va graph24.txt la do thi vo huong, co 2 thanh phan lien thong, 0 circular, 2 tree
	//file graph15.txt va graph25.txt la do thi vo huong, co 4 thanh phan lien thong, 1 circular, 3 tree
	// file graph16.txt va graph26.txt la do thi vo huong, bigraph, complete bigraph
	//file graph17.txt va graph27.txt la do thi co huong, bigraph, not complete bigraph

	string name1 = "graph1.txt";
	vector<vector<int>> list = CovertList(name1);
	cout << "[ Adjacency List ]" << endl;
	PrintVector(list);

	string name2 = "graph2.txt";
	vector<vector<int>> matrix = ConvertMatrix(name2);
	cout << "[ Adjacency Matrix ]" << endl;
	PrintVector(matrix);

	cout << endl;

	cout << "[ Input: Adjacency matrix ]" << endl;
	if (DirectedOrUndirected(matrix) == 1) { //directed
		cout << "Directed graph" << endl;
		degdirected = DegreeDirected(matrix);//out truoc, in sau

		for (int i = 0; i < degdirected[0].size(); i++)
		{
			cout << "Out-degree of vertice " << i << ": " << degdirected[0][i] << endl;
		}
		for (int i = 0; i < degdirected[1].size(); i++)
		{
			cout << "In-degree of vertice " << i << ": " << degdirected[1][i] << endl;
		}
		cout << "No connected components because this is a directed graph" << endl;

	}
	else {
		cout << "Undirected graph" << endl;
		degundirected = DegreeUndirected(matrix); 

		for (int i = 0; i < degundirected.size(); i++)
		{
			cout << "Degree of vertice " << i << ": " << degundirected[i] << endl;
		}
		cout << "Number of connected components: " << ConnectedComponentsNum(matrix, subgraph) << ". ";
		cout << "There are " << countTree(subgraph) << " tree(s) among them." << endl;

	}
	cout << "Number of edges: " << EdgesNum(matrix) << endl;
	cout << "Number of vertices: " << VerticesNum(matrix) << endl;
	cout << "Isolated vertices: ";
	isolated = IsolatedVertices(matrix);
	if (isolated.empty())
		cout << "no isolated vertice in this graph!" << endl;
	else {
		for (int i = 0; i < isolated.size(); i++)
			cout << isolated[i] << " ";
		cout << endl;
	}
	//
	cout << "Leaf vertices: ";
	leaf = LeafVertices(matrix);
	if (leaf.empty())
		cout << "no leaf vertice in this graph!" << endl;
	else {
		for (int i = 0; i < leaf.size(); i++)
			cout << leaf[i] << " ";
		cout << endl;
	}
	//
	SpecialGraph(matrix);
	cout << "Number of bridge edges: " << bridgeCount(matrix) << endl;
	cout << "Number of cut vertices: " << countCutVertice(matrix) << endl;
		


	cout << endl;
	subgraph.clear();




	cout << "[ Input: Adjacency list ]" << endl;
	if (DirectedOrUndirected(list) == 1) {

		cout << "Directed graph" << endl;
		degdirected = DegreeDirected(list);//out truoc, in sau

		for (int i = 0; i < degdirected[0].size(); i++)
		{
			cout << "Out-degree of vertice " << i << ": " << degdirected[0][i] << endl;
		}
		for (int i = 0; i < degdirected[1].size(); i++)
		{
			cout << "In-degree of vertice " << i << ": " << degdirected[1][i] << endl;
		}
		cout << "No connected components because this is a directed graph" << endl;
	}
	else {
		cout << "Undirected graph" << endl;
		degundirected = DegreeUndirected(list);

		for (int i = 0; i < degundirected.size(); i++)
		{
			cout << "Degree of vertice " << i << ": " << degundirected[i] << endl;
		}
		cout << "Number of connected components: " << ConnectedComponentsNum(list, subgraph) << ". ";
		cout << "There are " << countTree(subgraph) << " tree(s) among them." << endl;
	}
	cout << "Number of edges: " << EdgesNum(list) << endl;
	cout << "Number of vertices: " << VerticesNum(list) << endl;
	cout << "Isolated vertices: ";
	isolated = IsolatedVertices(list);
	if (isolated.empty())
		cout << "no isolated vertice in this graph!" << endl;
	else {
		for (int i = 0; i < isolated.size(); i++)
			cout << isolated[i] << " ";
		cout << endl;
	}
	//
	cout << "Leaf vertices: ";
	leaf = LeafVertices(list);
	if (leaf.empty())
		cout << "no leaf vertice in this graph!" << endl;
	else {
		for (int i = 0; i < leaf.size(); i++)
			cout << leaf[i] << " ";
		cout << endl;
	}
	//
	SpecialGraph(list);
	cout << "Number of bridge edges: " << bridgeCount(list) << endl;
	cout << "Number of cut vertices: " << countCutVertice(list) << endl;
	   
	return 0;
}

