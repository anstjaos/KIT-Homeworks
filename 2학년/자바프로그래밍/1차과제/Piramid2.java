import java.util.Scanner;

public class Piramid2{
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		
		int size = in.nextInt();
		
		
		
		int output = 1;
		for(int i=0; i<size; i++) {
			for(int j=size-1; j>i; j--){
				if(i!=3)
					System.out.print("   ");
				else
					System.out.print("  ");
			}
			for(int j=0; j<(i+1)*2-1; j++) {				
				if(output < 10)
					System.out.print(output++ + "  ");
				else
					System.out.print(output++ + " ");
			}
			System.out.println();
		}
	}
}
