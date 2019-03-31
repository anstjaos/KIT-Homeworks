package javaAssignment;

public class CommandLine2 {
	public static void main(String[] args)
    {
		int intSum = 0;
		float sum = 0;
        if (args.length > 0)
        {
            for (String val : args) {
                System.out.print(val+" ");
                float tmp = Float.parseFloat(val);
                
                if(tmp-(int)tmp > 0) // 실수인 경우
                	sum = sum +  tmp;
                else
                	intSum = (int) (intSum + tmp);
            }
            System.out.println();
            System.out.println("실수의 합 : " + sum);
            System.out.println("정수의 합 : " + intSum);
        }
        else
            System.out.println("인수를 입력하세요.");
    }
}