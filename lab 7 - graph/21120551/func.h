#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void PrintVector(vector<vector<int>> a);
vector<vector<int>> CovertList(string filename);
vector<vector<int>> ConvertMatrix(string filename);
int DirectedOrUndirected(vector<vector<int>> matrix);
int VerticesNum(vector<vector<int>> matrix);
int EdgesNum(vector<vector<int>> matrix);

vector<int> DegreeUndirected(vector<vector<int>> matrix);
vector<vector<int>> DegreeDirected(vector<vector<int>> matrix);
vector<int> IsolatedVertices(vector<vector<int>> matrix);
vector<int> LeafVertices(vector<vector<int>> matrix);

bool CircularGraph(int v, bool visited[], int parent, vector<vector<int>> matrix);
bool isCircular(vector<vector<int>> matrix);

bool CircularGraphDirected(int v, bool visited[], bool cur[], vector<vector<int>> matrix);
bool isCircularDirected(vector<vector<int>> matrix);

int countTree(vector<vector<vector<int>>> subgraph);

bool isBigraph(vector<vector<int>> matrix, int source, vector<int> &ver0, vector<int> &ver1);
bool isCompleteBigraph(vector<vector<int>> matrix, vector<int> ver0, vector<int> ver1);

void SpecialGraph(vector<vector<int>> matrix);

void DFS(int v, vector<bool> &visited, vector<vector<int>> matrix, vector<vector<int>>& sub, vector<int> &list);
int ConnectedComponentsNum(vector<vector<int>> matrix, vector<vector<vector<int>>> &subgraph);

int bridgeCount(vector<vector<int>> matrix);
int countCutVertice(vector<vector<int>> matrix);

