#pragma once
#include <iostream>
using namespace std;

template <class T>
class Sort {										// �پ��� ������ ����Ǿ��ִ� Ŭ����
private:
	void adjustHeap(T* arr, const int root, const int size);
public:
	void heapSort(T*& arr, const int size);
	void bubbleSort(T* arr, const int size);
	void selectionSort(T* arr, const int size);
};

template <class T>
void Sort<T> ::adjustHeap(T* arr, const int root, const int size)	// Heapify�� �ϴ� �Լ�
{
	T temp = arr[root];

	int index;
	for (index= 2 * root; index <= size; index *=2)
	{
		if (index < size && arr[index] < arr[index + 1]) index++;
		if (arr[index] < temp) break;
		arr[index / 2] = arr[index];
	}
	arr[index / 2] = temp;
}

template <class T>
void Sort<T> ::heapSort(T*& arr, const int size)			// Max heap�� ����� ������
{
	clock_t start, end;

	T* temp = new T[size+1];								// [0,n)�� �迭�� [1,n]�� ����
	copy(arr, arr + size, temp + 1);
	delete[] arr;

	arr = temp;

	start = clock();
	for (int i = (size) / 2; i >= 1; i--) adjustHeap(arr, i, size);
	
	for (int i = size-1; i >= 1; i--)
	{
		swap(arr[1], arr[i + 1]);
		adjustHeap(arr, 1, i);
	}
	end = clock();
	cout << "����ð� " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
}

template <class T>
void Sort<T> ::bubbleSort(T* arr, const int size)			// ���� ����
{
	clock_t start, end;
	start = clock();

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j + 1] < arr[j]) swap(arr[j], arr[j + 1]);
		}
	}
	end = clock();
	cout << "����ð� " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
}

template <class T>
void Sort<T> ::selectionSort(T* arr, const int size)		// ���� ����
{
	clock_t start, end;

	start = clock();
	for (int i = 0; i < size-1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min]) min = j;
		}
		swap(arr[i], arr[min]);
	}
	end = clock();
	cout << "����ð� " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
}