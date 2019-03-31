#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

int* loadFile(string fileName, int size)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	if (fin.fail()) return NULL;

	int* arr = new int[size];
	int count = 0;
	while (!fin.eof())
	{
		fin >> arr[count++];
	}

	fin.close();
	return arr;
}

void main()
{
	int *arr = loadFile("500000.txt", 500000);

	clock_t start, end;

	start = clock();
	sort(arr, arr + 500000);
	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;

	delete[] arr;
}