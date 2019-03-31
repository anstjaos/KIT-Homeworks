package BankFactory;
import java.util.Scanner;

public class BankB extends Bank {
	public BankB() { bankName = "Bank B"; }
	
	public Account createAccount(String accountType) {
		if(accountType.equals("�������")) return new NormalAccountB();
		else if(accountType.equals("���̳ʽ�����")) {
			System.out.print("�ѵ��� �Է��ϼ��� -> ");
			int limit = Integer.parseInt(sc.nextLine());
			return new MinusAccountB(limit);
		}
		else if(accountType.equals("���ǰ���")) return new SecuritiesAccountB();
		
		return null;
	}
}
