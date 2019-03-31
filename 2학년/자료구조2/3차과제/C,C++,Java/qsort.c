#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* p1, const void* p2)
{
	int num1 = *(int*)p1;
	int num2 = *(int*)p2;

	if (num1 < num2) return -1;
	else if (num1 > num2) return 1;
	else return 0;
}

void main()
{
	FILE *filePointer;
	filePointer = fopen("500000.txt", "r");
	
	int *arr;
	arr = (int*)malloc(sizeof(int) * 500000);

	int num;
	int cnt = 0;
	while (1)
	{
		fscanf(filePointer,"%d", &num);
		if (feof(filePointer)) break;
		arr[cnt++] = num;
	}
	fclose(filePointer);

	time_t start=0;
	time_t end=0;

	start = clock();
	qsort(arr, 500000, sizeof(int), compare);
	end = clock();
	
	float gap = (float)(end - start) / (CLOCKS_PER_SEC);
	printf("수행 시간 : %f \n", gap);
	free(arr);
}