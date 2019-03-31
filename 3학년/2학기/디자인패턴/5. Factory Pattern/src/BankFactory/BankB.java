package BankFactory;
import java.util.Scanner;

public class BankB extends Bank {
	public BankB() { bankName = "Bank B"; }
	
	public Account createAccount(String accountType) {
		if(accountType.equals("보통계좌")) return new NormalAccountB();
		else if(accountType.equals("마이너스계좌")) {
			System.out.print("한도를 입력하세요 -> ");
			int limit = Integer.parseInt(sc.nextLine());
			return new MinusAccountB(limit);
		}
		else if(accountType.equals("증권계좌")) return new SecuritiesAccountB();
		
		return null;
	}
}
