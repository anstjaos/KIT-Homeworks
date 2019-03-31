package javaAssignment;

public class CommandLine3 {
	public static void main(String[] args)
    {
        if (args.length > 0)
        {            
            int index = Integer.parseInt(args[1]);
            for(int i=0; i<Integer.parseInt(args[2]); i++) {
            	System.out.print(args[0].charAt(index++));
            }
        }
        else
            System.out.println("인수를 입력하세요.");
    }
}