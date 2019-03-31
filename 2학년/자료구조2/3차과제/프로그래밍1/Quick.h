#pragma once
#include "Stack.h"

template <class T>
class Quick {
private:
	int findMedianIndex(T arr[], const int left, const int right);
public:
	void quickSort(T *arr, const int left, const int right);
	void RecursiveMedianQuickSort(T *arr, const int left, const int right);
	void NonRecursiveMedianQuickSort(T *arr, const int end);
};

template <class T>
int Quick<T> ::findMedianIndex(T arr[], const int left, const int right)	// Median of three를 찾는다.
{
	T first = arr[left];
	T mid = arr[(left + right) / 2];
	T last = arr[right];

	int index = 0;
	if (mid < first)
	{
		if (last <mid) index = (left + right) / 2;
		else if (last < first) index = right;
		else index = left;
	}
	else
	{
		if (last <first) index = left;
		else if (last < mid) index = right;
		else index = (left + right) / 2;
	}

	return index;
}

template <class T>
void Quick<T> ::quickSort(T *arr, const int left, const int right)			// 재귀적 퀵정렬
{
	if (left < right)
	{
		int leftIndex = left + 1;
		int rightIndex = right;
		T pivot = arr[left];

		while (leftIndex <= rightIndex)
		{
			while (arr[leftIndex] < pivot && leftIndex < right) leftIndex++;
			while (pivot < arr[rightIndex] && left < rightIndex) rightIndex--;
			if (leftIndex <= rightIndex)
			{
				swap(arr[leftIndex], arr[rightIndex]);
				leftIndex++;
				rightIndex--;
			}
		}
		swap(arr[left], arr[rightIndex]);

		quickSort(arr, left, rightIndex - 1);
		quickSort(arr, rightIndex + 1, right);
	}
}

template <class T>
void Quick<T> ::RecursiveMedianQuickSort(T *arr, const int left, const int right)	// Median of three를 사용한 재귀적 퀵정렬
{
	if (left < right)
	{
		int leftIndex = left + 1;
		int rightIndex = right;

		int median = findMedianIndex(arr, left, right);
		swap(arr[median], arr[left]);
		T pivot = arr[left];

		while (leftIndex <= rightIndex)
		{
			while (arr[leftIndex] < pivot && leftIndex < right) leftIndex++;
			while (pivot < arr[rightIndex] && left < rightIndex) rightIndex--;

			if (leftIndex <= rightIndex)
			{
				swap(arr[leftIndex], arr[rightIndex]);
				leftIndex++;
				rightIndex--;
			}
		}
		swap(arr[left], arr[rightIndex]);

		quickSort(arr, left, rightIndex - 1);
		quickSort(arr, rightIndex + 1, right);
	}
}

template <class T>
void Quick<T> ::NonRecursiveMedianQuickSort(T *arr, const int end)		// Median of three를 사용한 반복적 퀵정렬
{
	Stack<int> stack;			// stack에 push 할 때 left, right 순으로 push

	stack.push(0);
	stack.push(end);

	int left, right;
	int leftIndex, rightIndex;
	int median;
	T pivot;

	while (!stack.isEmpty())
	{
		right = stack.getTop();
		stack.pop();
		left = stack.getTop();
		stack.pop();

		if (left < right)
		{
			median = findMedianIndex(arr, left, right);
			swap(arr[median], arr[left]);
			pivot = arr[left];

			leftIndex = left + 1;
			rightIndex = right;

			while (leftIndex <= rightIndex)
			{
				while (arr[leftIndex] < pivot && leftIndex < right) leftIndex++;
				while (pivot < arr[rightIndex] && left < rightIndex) rightIndex--;

				if (leftIndex <= rightIndex)
				{
					swap(arr[leftIndex], arr[rightIndex]);
					leftIndex++;
					rightIndex--;
				}
			}
			swap(arr[left], arr[rightIndex]);

			stack.push(rightIndex + 1);
			stack.push(right);				// 우측 서브리스트 left, right 순으로 push
			stack.push(left);
			stack.push(rightIndex - 1);		// 좌측 서브리스트를 뒤에 넣음으로써 점진적으로 메모리 스택공간을 줄여나간다.
		}
		
	}
}