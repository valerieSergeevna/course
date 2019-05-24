#include "stdafx.h"
#include "CppUnitTest.h"
#include "../course_work_sem_2/Edmonds_Karp_functions.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Edmonds_Karp_UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(max_Capacity_test_1)
		{

			int matrix[7][7] = {{0,3,3,0,0,0,0},{0,0,0,0,2,6,0},{0,0,0,4,0,0,0},{3,1,0,0,2,0,0},{0,0,1,0,0,0,1},{0,0,0,0,0,0,9},{0,0,0,0,0,0,0} };
			int **check = new int*[7];
			vector<vector<int>> graph(7);
			for (int i = 0; i < 7; i++)
				check[i] = new int[7];
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 7; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			int **flowPassed = new int*[7];
			for (int i = 0; i < 7; i++)
				flowPassed[i] = new int[7];
			int *parentsList = new int[7];
			int *currentPathCapacity = new int[7];
			
			
			
			Assert::AreEqual(edmondsKarp(0, 6, parentsList, flowPassed, check, graph, currentPathCapacity, 7), 4);
		}

		TEST_METHOD(max_Capacity_test_2)
		{


			int matrix[6][6] = { {0,3,3,0,0,0},{0,0,2,3,0,0},{0,0,0,0,2,0},{0,0,0,0,4,2},{0,0,0,0,0,3},{0,0,0,0,0,0} };
			int **check = new int*[6];
			vector<vector<int>> graph(6);
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			int **flowPassed = new int*[6];
			for (int i = 0; i < 6; i++)
				flowPassed[i] = new int[6];
			int *parentsList = new int[6];
			int *currentPathCapacity = new int[6];
			
			

			Assert::AreEqual(edmondsKarp(0, 5, parentsList, flowPassed, check, graph, currentPathCapacity, 6), 5);
		}

		TEST_METHOD(max_Capacity_test_3)
		{

			int matrix[6][6] = { {0,4,6,0,0,0},{0,0,0,5,0,0},{0,7,0,0,3,0},{0,2,0,0,4,6},{0,0,0,0,0,4},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			vector<vector<int>> graph(6);
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] !=0) graph[i].push_back(j);
				}
			int **flowPassed = new int*[6];
			for (int i = 0; i < 6; i++)
				flowPassed[i] = new int[6];
			int *parentsList = new int[6];
			int *currentPathCapacity = new int[6];

		
			int maxcap = edmondsKarp(0, 5, parentsList, flowPassed, check, graph, currentPathCapacity, 6);
			Assert::AreEqual(maxcap, 8);
		}

		TEST_METHOD(test_except_size)
		{

			int matrix[1][1] = { {0} };
			int **check = new int*[1];
			vector<vector<int>> graph(1);
			for (int i = 0; i < 1; i++)
				check[i] = new int[1];
			for (int i = 0; i < 1; i++)
				for (int j = 0; j < 1; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			int **flowPassed = new int*[1];
			for (int i = 0; i < 1; i++)
				flowPassed[i] = new int[1];
			int *parentsList = new int[1];
			int *currentPathCapacity = new int[1];

			try { edmondsKarp(0, 0, parentsList, flowPassed, check, graph, currentPathCapacity, 1); }
			catch(const std::out_of_range& error)
			{
				Assert::AreEqual("error", error.what());
			}

		}
		TEST_METHOD(test_except_endVertex)
		{

			int matrix[6][6] = { {0,4,6,0,0,0},{0,0,0,5,0,0},{0,7,0,0,3,0},{0,2,0,0,4,6},{0,0,0,0,0,4},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			vector<vector<int>> graph(6);
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			int **flowPassed = new int*[6];
			for (int i = 0; i < 6; i++)
				flowPassed[i] = new int[6];
			int *parentsList = new int[6];
			int *currentPathCapacity = new int[6];

			try {
				edmondsKarp(0, 3, parentsList, flowPassed, check, graph, currentPathCapacity, 6);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("error", error.what());
			}

		}

		
		TEST_METHOD(test_except_startVertex)
		{

			int matrix[6][6] = { {0,4,6,0,0,0},{0,0,0,5,0,0},{0,7,0,0,3,0},{0,2,0,0,4,6},{0,0,0,0,0,4},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			vector<vector<int>> graph(6);
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			int **flowPassed = new int*[6];
			for (int i = 0; i < 6; i++)
				flowPassed[i] = new int[6];
			int *parentsList = new int[6];
			int *currentPathCapacity = new int[6];

			try {
				edmondsKarp(5, 6, parentsList, flowPassed, check, graph, currentPathCapacity, 6);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("error", error.what());
			}

		}

		TEST_METHOD(test_incoherence)
		{

			int matrix[6][6] = { {0,4,6,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,4,0},{0,0,0,0,0,4},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			vector<vector<int>> graph(6);
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			Assert::IsFalse(IsConnect(0, 5, graph,6));
		}

		TEST_METHOD(test_coherence)
		{

			int matrix[6][6] = { {0,4,6,0,0,0},{0,0,0,5,0,0},{0,7,0,0,3,0},{0,2,0,0,4,6},{0,0,0,0,0,4},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			vector<vector<int>> graph(6);
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					check[i][j] = matrix[i][j];
					if (matrix[i][j] != 0) graph[i].push_back(j);
				}
			Assert::IsTrue(IsConnect(0, 5, graph, 6));
		}
	};
}