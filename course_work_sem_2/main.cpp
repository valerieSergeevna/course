
#include<iostream>
#include<conio.h>
#include"Edmonds_Karp_functions.h"

using namespace std;

void main()
{

	setlocale(LC_ALL, "rus");
	map <string> vertex;
	read_file(&vertex);
	vector<vector<int>> graph(vertex.get_size());
	int **capacities;
	capacities = create_graph_matrix(vertex, graph);
	for (int i = 0; i < vertex.get_size(); i++)
	{
		cout << '\n';
		for (int j = 0; j < vertex.get_size(); j++)
			cout << capacities[i][j] << ' ';
	}
	if (!IsConnect(0, vertex.get_size() - 1, graph, vertex.get_size())) { 
		cout << "неверно заданный граф";
		return;
	}
	cout << '\n';
	int **flowPassed = new int*[vertex.get_size()];
	for (int i = 0; i < vertex.get_size(); i++)
		flowPassed[i] = new int[vertex.get_size()];
	int *parentsList = new int[vertex.get_size()];
	int *currentPathCapacity = new int[vertex.get_size()];
	const int graph_size = vertex.get_size();


	string str = "S T";
	int found = str.find(' ');
	int source = vertex.find_id(str.substr(0, found));
	str.erase(0, found + 1);
	found = str.find('\0');
	int sink = vertex.find_id(str.substr(0, found));
	int maxFlow = edmondsKarp(source, sink, parentsList, flowPassed, capacities,graph, currentPathCapacity, vertex.get_size());


	cout << maxFlow;
	

	_getch();
}