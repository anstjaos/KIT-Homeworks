package BankFactory;
import java.util.Scanner;

public class BankC extends Bank {
	public BankC() { bankName = "Bank C"; }
	
	public Account createAccount(String accountType) {
		if(accountType.equals("�������")) return new NormalAccountC();
		else if(accountType.equals("���̳ʽ�����")) {
			System.out.print("�ѵ��� �Է��ϼ��� -> ");
			int limit = Integer.parseInt(sc.nextLine());
			return new MinusAccountC(limit);
		}
		
		return null;
	}
}
