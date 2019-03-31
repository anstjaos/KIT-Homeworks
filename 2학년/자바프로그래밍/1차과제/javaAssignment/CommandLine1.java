
public class CommandLine1{
	public static void main(String[] args)
    {
		float sum = 0;
        if (args.length > 0)
        {
            for (String val : args) {
                System.out.print(val+" ");
                float tmp = Float.parseFloat(val);
                sum = sum +  tmp;
            }
            System.out.println();
            System.out.print("합 : " + sum);
        }
        else
            System.out.println("인수를 입력하세요.");
    }
}