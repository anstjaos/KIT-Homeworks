import java.util.Scanner;


public class Factorial{

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner input =new Scanner(System.in);
		int num = input.nextInt();
		long a = recursiveFactorial(num);
		long b = repetitionFactorial(num);
		System.out.println("Àç±Í ->" + a);
		System.out.println("¹Ýº¹ ->" + b);
	}

	public static long recursiveFactorial(int n){
		
		if(n == 1){
            return 1;
        }
        return n * (recursiveFactorial(n-1));
		
	}
	public static long  repetitionFactorial(int n){
		long fact = 1;
		for(int i = 1; i <= n ; i++){
			fact *= i;
		}
		return fact;
		
	}
}
