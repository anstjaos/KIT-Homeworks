#pragma once
#include "Node.h"
#include <time.h>

template <class T>
class Insertion {
private:
	int binarySearch(T& e, T *arr, int index);
public:
	void binaryInsertionSort(T *arr, const int size);
	void insertionSort(T *arr, const int size);
	void listInsertionSort(T *arr, const int size);
};

template <class T>
int Insertion<T>::binarySearch(T& e, T *arr, int end)					// 이원탐색을 이용하여 삽입할 index를 return 한다.
{
	int start = 0;
	int mid = 0;
	
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (e < arr[mid]) end = mid - 1;
		else if (arr[mid] < e) start = mid + 1;
		else break;
	}

	if (mid > end) return mid;
	return mid + 1;
}

template <class T>
void Insertion<T>::binaryInsertionSort(T *arr, const int size)			// 이원삽입정렬
{
	clock_t start, end;
	start = clock();

	for (int i = 1; i < size; i++)
	{
		T temp = arr[i];

		int standard = binarySearch(temp, arr, i - 1);					// 삽입할 위치를 찾는다.
		
		for (int j = i-1; j >= standard; j--)							// 배열의 값을 한 칸씩 뒤로 옮긴다.
		{
			arr[j + 1] = arr[j];
		}
		arr[standard] = temp;
	}

	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
}

template <class T>
void Insertion<T>::insertionSort(T *arr, const int size)				// 삽입정렬
{
	clock_t start,end;
	start = clock();

	for (int j = 1; j < size; j++)
	{
		T temp = arr[j];												// arr[0]을 사용하는 것이 아닌 임시변수를 사용하였다.

		int i = j - 1;
		while (temp < arr[i])
		{
			arr[i + 1] = arr[i];
			i--;
			if (i < 0) break;
		}
		arr[i + 1] = temp;
	}

	end = clock();
	cout << "수행시간 " << (double)(end - start)/(CLOCKS_PER_SEC) << endl;
}

template <class T>
void Insertion<T> ::listInsertionSort(T *arr, const int size)			// 연결삽입정렬
{
	Node<T>* first = new Node<T>();
	Node<T>* curPtr = first;

	for (int i = 0; i < size; i++)										// 배열에 있는 데이터를 list로 구성한다.
	{
		curPtr->next = new Node<T>(arr[i], curPtr, NULL);

		if (i == size - 1)
		{
			curPtr = curPtr->next;
			curPtr->next = first;
			first->pre = curPtr;
		}
		else curPtr = curPtr->next;
	}

	clock_t start, end;
	start = clock();

	Node<T>* ptr = first->next->next;

	while(ptr != first)
	{
		curPtr = ptr;
		first->data = ptr->data;

		Node<T>* prePtr = curPtr->pre;
		while (ptr->data < prePtr->data)
		{
			prePtr = prePtr->pre;
		}
		ptr = ptr->next;

		ptr->pre = curPtr->pre;											// data 필드의 값을 바꾸지 않고, link 값을 수정한다.
		curPtr->pre->next = ptr;
		curPtr->pre = prePtr;
		curPtr->next = prePtr->next;
		prePtr->next->pre = curPtr;
		prePtr->next = curPtr;
	}

	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;

	
	first->pre->next = NULL;
	ptr = first->next;
	while(1)
	{
		if (ptr == NULL) break;

		curPtr = ptr;
		ptr = ptr->next;
		delete curPtr;
	}
	delete first;
}