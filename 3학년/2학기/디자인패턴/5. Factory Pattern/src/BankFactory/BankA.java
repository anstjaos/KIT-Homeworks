package BankFactory;
import java.util.Scanner;

public class BankA extends Bank {
	public BankA() { bankName = "Bank A"; }
	
	public Account createAccount(String accountType) {
		if(accountType.equals("보통계좌")) return new NormalAccountA();
		else if(accountType.equals("마이너스계좌")) {
			System.out.print("한도를 입력하세요 -> ");
			int limit = Integer.parseInt(sc.nextLine());
			return new MinusAccountA(limit);
		}
		else if(accountType.equals("증권계좌")) return new SecuritiesAccountA();
		
		return null;
	}
}