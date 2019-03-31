import java.util.Scanner;

public class FizzBuzz_switch{
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		String resultStr="";
		
		int inputNum;
		while((inputNum = in.nextInt()) != -1) {
			
			int resultNum = 0;
			
			if(inputNum%5 == 0&& inputNum%7 != 0)
				resultNum = 1;
			else if(inputNum%7 == 0 && inputNum%5 != 0)
				resultNum = 2;
			else if(inputNum%5 == 0 && inputNum%7 == 0)
				resultNum = 3;
			
			
			switch(resultNum) {
			case 1:
				resultStr = "fizz";
				break;
			case 2:
				resultStr = "buzz";
				break;
			case 3:
				resultStr = "fizzbuzz";
				break;
			default:
				resultStr = "EEEERRROOORRR";
				break;
			}
			
			System.out.println(resultStr);
		}
	}
}
