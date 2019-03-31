import java.io.*;
import java.util.Scanner;

public class QuickSort {
	QuickSort() {}
	
	void quickSort(int[] arr,int left, int right)
	{
		if (left < right)
		{
			int leftIndex = left + 1;
			int rightIndex = right;
			int pivot = arr[left];

			while (leftIndex <= rightIndex)
			{
				while (arr[leftIndex] < pivot && leftIndex <= right) leftIndex++;
				while (pivot < arr[rightIndex] && left < rightIndex) rightIndex--;
				if (leftIndex <= rightIndex)
				{
					int temp = arr[leftIndex];
					arr[leftIndex] = arr[rightIndex];
					arr[rightIndex] = temp;
		
					leftIndex++;
					rightIndex--;
				}
			}
			int temp = arr[left];
			arr[left] = arr[rightIndex];
			arr[rightIndex] = temp;
			
			quickSort(arr, left, rightIndex - 1);
			quickSort(arr, rightIndex + 1, right);
		}
	}
	
	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(new File("C:\\Users\\document\\eclipse-workspace\\Test\\src\\500000.txt"));
			int[] arr = new int[500001];
			int num;
			int cnt = 0;
			
			while(sc.hasNext())
			{
				num = sc.nextInt();
				arr[cnt++] = num;
			}
			
			sc.close();
			QuickSort qs = new QuickSort();
			
			long start = System.currentTimeMillis();
			qs.quickSort(arr, 0, 499999);
			long end = System.currentTimeMillis();
			
			System.out.println("수행 시간 : " + (end - start) / 1000.0);
		} catch (IOException e)
		{
			
		}

	}

}
