// QuickSort algorithm was contributed by geeksforgeeks.com. This is a benchmark test of its performance. 
// Test harness was authored by Parker Folkman. 
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

int partition(vector<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j<q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			swap(A[i], A[j]);
		}

	}

	swap(A[i], A[p]);
	return i;
}

void quickSort(vector<int>& A, int p, int q)
{
	int r;
	if (p<q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}

int main()
{


	for (int i = 0; i < 100; i++) {
		ifstream inputFile;
		inputFile.open("SortingInputs.txt");
		vector<int> inputVector;
		int number;
		while (inputFile >> number)
		{
			inputVector.push_back(number);
		}
		high_resolution_clock::time_point startTime = high_resolution_clock::now();
		quickSort(inputVector, 0, inputVector.size());
		high_resolution_clock::time_point endTime = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(endTime - startTime).count();
		cout << duration << endl;
	}
	
    return 0;
}

