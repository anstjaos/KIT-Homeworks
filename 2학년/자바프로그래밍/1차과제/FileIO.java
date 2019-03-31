
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
			System.out.println("�Ҽ� �����");
			String department = input.nextLine();
			
			System.out.println("�г� �����");
			byte grade = input.nextByte();
			
			System.out.println("�й� �����");
			int departmentNumber =input.nextInt(); input.nextLine();
			
			System.out.println("�̸� �����");
			String name = input.nextLine();
			
			System.out.println("���� �����");
			String sex = input.nextLine();
			
			System.out.println("���� �����");
			String birthday = input.nextLine();
			
			System.out.println("������ �����");
			float wight = input.nextFloat();input.nextLine();
			
			System.out.println("�ּ� �����");
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
