#pragma once
#include<vector>
#include <string>
#include "map.cpp"

using namespace std;


void read_file(map<string>*);
int** create_graph_matrix(map<string>, vector< vector<int>>&);
//int BFS_(int , int , int *, int **, int **, vector<int> *, int*, size_t );
int edmondsKarp(int startNode, int endNode, int *parentsList, int **flowPassed, int **capacities, vector< vector<int>> &graph, int*currentPathCapacity, size_t size);
int find_id(map<string> vertex, string ver);