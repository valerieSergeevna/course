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

			int matrix[7][7] = { {0,3,3,0,0,0,0},{0,0,0,0,2,6,0},{0,0,0,4,0,0,0},{3,1,0,0,2,0,0},{0,0,1,0,0,0,1},{0,0,0,0,0,0,9},{0,0,0,0,0,0,0} };
			int **check = new int*[7];
			for (int i = 0; i < 7; i++)
				check[i] = new int[7];
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 7; j++)
					check[i][j] = matrix[i][j];
			int **flowPassed = new int*[7];
			for (int i = 0; i < 7; i++)
				flowPassed[i] = new int[7];
			int *parentsList = new int[7];
			int *currentPathCapacity = new int[7];
			
			vector<vector<int>> graph(7);
			
			Assert::AreEqual(edmondsKarp(0, 6, parentsList, flowPassed, check, graph, currentPathCapacity, 7), 5);
		}

		TEST_METHOD(max_Capacity_test_2)
		{


			int matrix[6][6] = { {0,3,3,0,0,0},{0,0,2,3,0,0},{0,0,0,0,2,0},{0,0,0,0,4,2},{0,0,0,0,0,3},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					check[i][j] = matrix[i][j];
			int **flowPassed = new int*[6];
			for (int i = 0; i < 6; i++)
				flowPassed[i] = new int[6];
			int *parentsList = new int[6];
			int *currentPathCapacity = new int[6];
			
			vector<vector<int>> graph(6);

			Assert::AreEqual(edmondsKarp(0, 5, parentsList, flowPassed, check, graph, currentPathCapacity, 6), 5);
		}

		TEST_METHOD(max_Capacity_test_3)
		{

			int matrix[6][6] = { {0,4,6,0,0,0},{0,0,0,5,0,0},{0,7,0,0,3,0},{0,2,0,0,4,6},{0,0,0,0,0,4},{0,0,0,0,0,0} };
			int **check = new int*[6];
			for (int i = 0; i < 6; i++)
				check[i] = new int[6];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					check[i][j] = matrix[i][j];
			int **flowPassed = new int*[6];
			for (int i = 0; i < 6; i++)
				flowPassed[i] = new int[6];
			int *parentsList = new int[6];
			int *currentPathCapacity = new int[6];

			vector<vector<int>> graph(6);
			int maxcap = edmondsKarp(0, 5, parentsList, flowPassed, check, graph, currentPathCapacity, 6);
			Assert::AreEqual(maxcap, 8);
		}

		
	};
}