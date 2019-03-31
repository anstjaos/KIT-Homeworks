#pragma once
#include "Insertion.h"
#include "Merge.h"
#include "Quick.h"
#include "Sort.h"
#include "Student.h"
#include "Radix.h"
#include <string>
#include <fstream>
#include <algorithm>

template<class T>
class TaskManager {										// 전체적인 프로그램 실행을 관리하는 클래스
private:
	void insertionSort(T* arr, int size);			
	void quickSort(T* arr, int size);
	void mergeSort(T*& arr, int size);
public:
	T* loadFile(string fileName, int size);				// int, double, string type의 파일을 읽어오는 함수
	T* loadStudentFile(string fileName, int size);		// student type의 파일을 읽어오는 함수
	void run(T*& arr,int size);							// 프로그램 실행을 관리하는 함수
};

template <class T>
void TaskManager<T> ::insertionSort(T* arr, int size)
{
	int select;
	while (1)
	{
		cout << "\n===============================================" << endl;
		cout << "\t\tSelect Insertion Sort" << endl;
		cout << "\t1) Insertion" << endl;
		cout << "\t2) Binary Insertion" << endl;
		cout << "\t3) List Insertion" << endl;
		cout << "===============================================" << endl;
		cout << "Select ? ";
		cin >> select;

		if (0 > select || select > 3) continue;
		else break;
	}

	Insertion<T> insert;

	switch (select)
	{
	case 1:
		insert.insertionSort(arr, size);			// 기본적인 삽입정렬
		break;
	case 2:
		insert.binaryInsertionSort(arr, size);		// 이원삽입정렬
		break;
	case 3:
		insert.listInsertionSort(arr, size);		// 리스트로 구성한 연결삽입정렬
		break;
	}
}

template <class T>
void TaskManager<T> ::quickSort(T* arr, int size)
{
	int select;
	while (1)
	{
		cout << "\n===============================================" << endl;
		cout << "\t\tSelect Quick Sort" << endl;
		cout << "\t1) Quick Sort" << endl;
		cout << "\t2) Recursive Three-median Quick Sort" << endl;
		cout << "\t3) Non-Recursive Three-median Quick Sort" << endl;
		cout << "\t4) std:: sort" << endl;
		cout << "===============================================" << endl;
		cout << "Select ? ";
		cin >> select;

		if (0 > select || select > 4) continue;
		else break;
	}

	Quick<T> q;
	clock_t start, end;
	switch (select)
	{
	case 1:
		start = clock();
		q.quickSort(arr, 0, size - 1);
		end = clock();
		break;
	case 2:
		start = clock();
		q.RecursiveMedianQuickSort(arr, 0, size - 1);
		end = clock();
		break;
	case 3:
		start = clock();
		q.NonRecursiveMedianQuickSort(arr, size - 1);
		end = clock();
		break;
	case 4:
		start = clock();
		sort(arr, arr + size);
		end = clock();
		break;
	}

	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
}

template <class T>
void TaskManager<T> ::mergeSort(T*& arr, int size)
{
	int select;
	while (1)
	{
		cout << "\n===============================================" << endl;
		cout << "\t\tSelect Merge Sort" << endl;
		cout << "\t1) Merge Sort" << endl;
		cout << "\t2) Recursive Merge Sort" << endl;
		cout << "\t3) Nature Merge Sort" << endl;
		cout << "===============================================" << endl;
		cout << "Select ? ";
		cin >> select;

		if (0 > select || select > 3) continue;
		else break;
	}

	Merge<T> m;
	int* link = NULL;
	T* temp = new T[size+1];
	copy(arr, arr + size, temp + 1);
	delete[] arr;
	
	arr = temp;										// 기존의 [0,n)의 배열이 아닌 [1,n] 배열로 변경
	
	clock_t start, end;
	switch (select)
	{
	case 1:
		m.mergeSort(arr, size);						
		break;
	case 2:
		link = new int[size + 1];					// 다음 값의 index를 가리키는 link 배열
		fill(link, link + size + 1, 0);
		start = clock();
		m.recursiveMergeSort(arr, link, 1, size);
		end = clock();
		delete[] link;
		break;
	case 3:
		T *mergedTemp = new T[size + 1];			// size+1 만큼의 공간을 더 사용한다.
		start = clock();
		m.natureMergeSort(arr, mergedTemp, size);
		end = clock();

		delete[] mergedTemp;
		break;
	}
	if(select != 1) cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
}

template <class T>
T* TaskManager<T> ::loadFile(string fileName, int size)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "존재하지 않는 파일입니다." << endl;
		return NULL;
	}

	T* arr = new T[size];
	int count = 0;

	while (!fin.eof())
	{
		fin >> arr[count++];
	}
	fin.close();
	return arr;
}

template <class T>
T* TaskManager<T>::loadStudentFile(string fileName, int size)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);

	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다." << endl;
		return NULL;
	}

	T* arr = new Student[size];
	int count = 0;

	int studentNum;
	int korScore;
	int engScore;
	int mathScore;

	while (!fin.eof())
	{
		fin >> studentNum >> korScore >> engScore >> mathScore;
		Student s(studentNum, korScore, engScore, mathScore);

		arr[count++] = s;
	}
	fin.close();
	return arr;
}

template <class T>
void TaskManager<T> ::run(T*& arr, int size)
{
	int selectSort;

	while (1)
	{
		cout << "\n===============================================" << endl;
		cout << "\t\tSelect Sort" << endl;
		cout << "\t1) Insertion" << endl;
		cout << "\t2) Quick" << endl;
		cout << "\t3) Merge" << endl;
		cout << "\t4) Heap" << endl;
		cout << "\t5) Bubble" << endl;
		cout << "\t6) Selection" << endl;
		cout << "===============================================" << endl;
		cout << "Select ? ";
		cin >> selectSort;

		if (0 > selectSort || selectSort > 6) continue;
		else break;
	}
	Sort<T> s;

	switch (selectSort)					// 선택한 정렬을 수행하게 해준다.
	{
	case 1:
		insertionSort(arr, size);
		break;
	case 2:
		quickSort(arr, size);
		break;
	case 3:
		mergeSort(arr, size);
		break;
	case 4:
		s.heapSort(arr, size);
		break;
	case 5:
		s.bubbleSort(arr, size);
		break;
	case 6:
		s.selectionSort(arr, size);
		break;
	}
}