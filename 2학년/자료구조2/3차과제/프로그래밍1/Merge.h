#pragma once
#include <iostream>
using namespace std;

template <class T>
class Merge {
private:
	int listMerge(T* arr, int* link, const int start1, const int start2);
	void mergePass(T* initList, T* resultList, const int recordCnt, const int size);
	void merge(T* initList, T* mergedList, const int left, const int mid, const int right);
	int makeRun(T* arr, const int start, const int size);
public:
	int recursiveMergeSort(T* arr, int* link, const int left,const int right);
	void mergeSort(T* arr, const int size);
	void natureMergeSort(T* initList, T* mergedList, const int size);
};

template <class T>
int Merge<T> ::listMerge(T* arr, int* link, const int start1, const int start2)
{
	int result = 0;
	int i = start1;
	int j = start2;
	for(i = start1, j =start2; i&& j;)
	{
		if (arr[i] <= arr[j])
		{
			link[result] = i;
			result = i;
			i = link[i];
		}
		else
		{
			link[result] = j;
			result = j;
			j = link[j];
		}
	}

	if (i == 0) link[result] =j;
	else link[result] = i;
	return link[0];
}

template <class T>
void Merge<T>::mergePass(T* initList, T* resultList, const int recordCnt, const int size)
{
	int index = 1;
	for (index; index <= recordCnt - 2 * size + 1; index += 2 * size)
	{
		merge(initList, resultList, index, index + size - 1, index + 2 * size - 1);
	}

	if ((index + size - 1) < recordCnt) merge(initList, resultList, index, index + size - 1, recordCnt);
	else copy(initList + index, initList + recordCnt + 1, resultList + index);
}

template <class T>
void Merge<T>:: merge(T* initList, T* mergedList, const int left, const int mid, const int right) // 두 개의 리스트를 합병한다.
{
	int index1 = left;
	int index2 = mid + 1;
	int result = left;

	for (; index1 <= mid && index2 <= right; result++)
	{
		if (initList[index1] <= initList[index2])
		{
			mergedList[result] = initList[index1];
			index1++;
		}
		else
		{
			mergedList[result] = initList[index2];
			index2++;
		}
	}

	copy(initList + index1, initList + mid + 1, mergedList + result);
	copy(initList + index2, initList + right + 1, mergedList + result);
}

template <class T>
int Merge<T> ::makeRun(T* arr, const int start, const int size)		// 자연합병 정렬에서 사용되는 리스트를 구성한다.
{
	if (start >= size) return size;

	int end = start;
	for (int i = start; i < size; i++)
	{
		if (arr[i] <= arr[i + 1]) end++;
		else break;
	}

	return end;
}

template <class T>
int Merge<T> ::recursiveMergeSort(T* arr, int* link, const int left, const int right)		// 1부터 n까지 정렬
{																							// 재귀적 합병정렬
	if (left >= right) return left;
	int mid = (left + right) / 2;
	return listMerge(arr, link, recursiveMergeSort(arr, link, left, mid), recursiveMergeSort(arr, link, mid + 1, right));
}


template <class T>
void Merge<T> ::mergeSort(T* arr, const int size)		// 비재귀적 합병정렬
{
	clock_t start, end;
	start = clock();

	T* tempList = new T[size + 1];

	for (int i = 1; i < size; i *= 2)
	{
		mergePass(arr, tempList, size, i);
		i *= 2;
		mergePass(tempList, arr, size, i);
	}
	end = clock();
	cout << "수행시간 " << (double)(end - start) / (CLOCKS_PER_SEC) << endl;
	
	delete[] tempList;
}

template <class T>
void Merge<T> ::natureMergeSort(T* initList, T* mergedList, const int size)		// 자연 합병정렬
{
	int count = 0;

	for (int i = 1; i <= size; i++)
	{
		int left = i;
		int mid = makeRun(initList, left, size);
		int right = makeRun(initList, mid + 1, size);

		merge(initList, mergedList, left, mid, right);
		merge(mergedList, initList, left, mid, right);
		i = right;
		count++;
	}
	if (count == 1) return;
	natureMergeSort(initList, mergedList, size);
}