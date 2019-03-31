
import java.io.*
import java.util.Scanner;

public class FileIO{

	public static void main(String[] args) throws IOException {

		
		try{
			BufferedReader br = new BufferedReader(new FileReader("output.txt"));
			String department = br.readLine();
			
			byte grade = Byte.parseByte(br.readLine());
			
			int departmentNumber = Integer.parseInt(br.readLine());
			
			String name = br.readLine();
			
			String sex = br.readLine();
			
			String birthday = br.readLine();
			
			float wight = Float.parseFloat(br.readLine());
			
			String address = br.readLine();
		}catch(Exception e){
			PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
			
			Scanner input = new Scanner(System.in);
			System.out.println("소속 적어라");
			String department = input.nextLine();
			
			System.out.println("학년 적어라");
			byte grade = input.nextByte();
			
			System.out.println("학번 적어라");
			int departmentNumber =input.nextInt(); input.nextLine();
			
			System.out.println("이름 적어라");
			String name = input.nextLine();
			
			System.out.println("성별 적어라");
			String sex = input.nextLine();
			
			System.out.println("생일 적어라");
			String birthday = input.nextLine();
			
			System.out.println("몸무게 적어라");
			float wight = input.nextFloat();input.nextLine();
			
			System.out.println("주소 적어라");
			String address = input.nextLine();
			
			pw.println(department);
			pw.println(Byte.toString(grade));
			pw.println(Integer.toString(departmentNumber));
			pw.println(name);
			pw.println(sex);
			pw.println(birthday);
			pw.println(Float.toString(wight));
			pw.println(address);
			pw.close();
		}
		
		
	
			
		
	}

}
