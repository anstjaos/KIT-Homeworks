package UniqueBank;
import java.util.Scanner;

public class BankFactory {
	Scanner sc = new Scanner(System.in);
	public Account createAccount(String accountType, String branchName) {
		if(accountType.equals("�������")) return new NormalAccount(branchName);
		else if(accountType.equals("���̳ʽ�����")) {
			Scanner sc = new Scanner(System.in);
			
			System.out.print("��ü �ѵ��� �Է��ϼ���-> ");
			int limit = sc.nextInt();
			return new MinusAccount(branchName, limit);
		}
		else if(accountType.equals("���ǰ���")) return new SecuritiesAccount(branchName);
		
		return null;
	}
}
