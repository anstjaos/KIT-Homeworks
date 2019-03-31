import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class CollectionSort {

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(new File("C:\\Users\\document\\eclipse-workspace\\Test\\src\\500000.txt"));
			ArrayList<Integer> arr= new ArrayList<Integer>();
			int num;
			
			while(sc.hasNext())
			{
				num = sc.nextInt();
				arr.add(num);
			}
			
			sc.close();
	
			long start = System.currentTimeMillis();
			Collections.sort(arr);
			long end = System.currentTimeMillis();
			
			System.out.println("수행 시간 : " + (end - start) / 1000.0);
		} catch (IOException e) {
			
		}

	}

}
