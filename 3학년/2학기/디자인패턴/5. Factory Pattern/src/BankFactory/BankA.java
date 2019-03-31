package BankFactory;
import java.util.Scanner;

public class BankA extends Bank {
	public BankA() { bankName = "Bank A"; }
	
	public Account createAccount(String accountType) {
		if(accountType.equals("�������")) return new NormalAccountA();
		else if(accountType.equals("���̳ʽ�����")) {
			System.out.print("�ѵ��� �Է��ϼ��� -> ");
			int limit = Integer.parseInt(sc.nextLine());
			return new MinusAccountA(limit);
		}
		else if(accountType.equals("���ǰ���")) return new SecuritiesAccountA();
		
		return null;
	}
}