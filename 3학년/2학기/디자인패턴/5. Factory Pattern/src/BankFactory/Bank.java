package BankFactory;
import java.util.Scanner;

public abstract class Bank {
	protected String bankName;
	Scanner sc = new Scanner(System.in);
	
	protected abstract Account createAccount(String accountType);
	public Account newAccount(String accountType) {
		Account ac = createAccount(accountType);
		
		return ac;
	}
}