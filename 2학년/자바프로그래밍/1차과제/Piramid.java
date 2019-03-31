import java.util.Scanner;

public class Piramid{
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int size = in.nextInt();
		
		for(int i=0; i<size; i++) {
			for(int j=size; j>i+1; j--) {
				System.out.print(" ");
			}
			int output = i+1;
			for(int j=0; j<i+1; j++) {
				System.out.print(output);
				if(output != 0)
					output = output-1;				
			}
			output = output+2;
			for(int j=0; j<i; j++) {
				System.out.print(output++);	
			}
			System.out.println();
		}
	}
}
