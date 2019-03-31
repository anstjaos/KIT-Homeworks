package BankFactory;
import java.util.Scanner;

public class BankC extends Bank {
	public BankC() { bankName = "Bank C"; }
	
	public Account createAccount(String accountType) {
		if(accountType.equals("보통계좌")) return new NormalAccountC();
		else if(accountType.equals("마이너스계좌")) {
			System.out.print("한도를 입력하세요 -> ");
			int limit = Integer.parseInt(sc.nextLine());
			return new MinusAccountC(limit);
		}
		
		return null;
	}
}
