#include "Edmonds_Karp_functions.h"
#include <fstream>
#include<cstdio>
#include<cstring> 
#include <stdexcept>

void read_file(map<string>*vertex)
{
	fstream fin;
	fin.open("input.txt", ios::in);
	if (fin.bad() || fin.eof()) throw out_of_range("error");
	string buf;
	int id = 0;
	do
	{
		int counter = 0;
		getline(fin, buf);
		while (counter != 2)
		{
			size_t found = buf.find(' ');
			if (vertex->insert(buf.substr(0, found), id))
				id++;
			buf.erase(0, found + 1);
			counter++;
		}

	} while (!fin.eof());

	fin.close();
}

int **create_graph_matrix(map<string> vertex, vector< vector<int>> &graph)
{
	int **matrix = new int*[vertex.get_size()];
	for (int i = 0; i < vertex.get_size(); i++)
	{
		matrix[i] = new int[vertex.get_size()];

	}

	for (int i = 0; i < vertex.get_size(); i++)
		for (int j = 0; j < vertex.get_size(); j++)
		matrix[i][j] = 0;
	fstream fin;
	fin.open("input.txt", ios::in);
	string buf;
	do
	{
		int counter = 0;
		getline(fin, buf);
		size_t found = buf.find(' ');
		//int column = vertex.find_id(buf.substr(0, found));
		int column = vertex.find_id(buf.substr(0, found));
		buf.erase(0, found + 1);
		int row = vertex.find_id(buf.substr(0, buf.find(' ')));
		buf.erase(0, found + 1);
		found = buf.find('\n');
		matrix[column][row] = stoi(buf.substr(0, found));
		graph[column].push_back(row);
		graph[row].push_back(column);
		
	} while (!fin.eof());

	fin.close();
	return matrix;
}

int BFS_(int startNode, int endNode, int *parentsList, int **flowPassed, int **capacities, vector< vector<int>> &graph, int*currentPathCapacity, size_t size)
{

	for (int i = 0; i < size; i++)
	{
		parentsList[i] = -1;
		currentPathCapacity[i] = 0;
	}

	queue<int> q(size);
	q.push(startNode);

	parentsList[startNode] = -2;
	currentPathCapacity[startNode] = 999;

	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();

		for (int i = 0; i < graph[currentNode].size(); i++)
		{
			int to = graph[currentNode][i];
			if (parentsList[to] == -1)
			{
				if (capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
				{
					parentsList[to] = currentNode;
					currentPathCapacity[to] = (currentPathCapacity[currentNode]<
						capacities[currentNode][to] - flowPassed[currentNode][to])?currentPathCapacity[currentNode]: capacities[currentNode][to] - flowPassed[currentNode][to];
					if (to == endNode)
					{
						return currentPathCapacity[endNode];
					}
					q.push(to);
				}
			}
		}
	}
	return 0;
}

int edmondsKarp(int startNode, int endNode, int *parentsList,int **flowPassed,int **capacities, vector< vector<int>>&graph, int*currentPathCapacity,size_t size)
{

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			flowPassed[i][j] = 0;
	int maxFlow = 0;
	while (true)
	{
		int flow = BFS_(startNode, endNode, parentsList, flowPassed, capacities, graph, currentPathCapacity,size);
		if (flow == 0)
		{
			break;
		}
		maxFlow += flow;
		int currentNode = endNode;
		while (currentNode != startNode)
		{
			int previousNode = parentsList[currentNode];
			flowPassed[previousNode][currentNode] += flow;
			//flowPassed[currentNode][previousNode] -= flow;
			currentNode = previousNode;
		}
	}
	return maxFlow;
}

int find_id(map<string> vertex, string ver)
{
	{ return vertex.find_id(ver); }
}
