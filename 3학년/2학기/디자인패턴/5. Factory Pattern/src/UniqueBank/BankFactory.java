package UniqueBank;
import java.util.Scanner;

public class BankFactory {
	Scanner sc = new Scanner(System.in);
	public Account createAccount(String accountType, String branchName) {
		if(accountType.equals("보통계좌")) return new NormalAccount(branchName);
		else if(accountType.equals("마이너스계좌")) {
			Scanner sc = new Scanner(System.in);
			
			System.out.print("이체 한도를 입력하세요-> ");
			int limit = sc.nextInt();
			return new MinusAccount(branchName, limit);
		}
		else if(accountType.equals("증권계좌")) return new SecuritiesAccount(branchName);
		
		return null;
	}
}
