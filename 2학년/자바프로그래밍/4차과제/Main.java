import java.io.*;

abstract class Account implements Serializable {
	private int 잔고;
	
	public Account(int 금액) { 잔고 = 금액; }

	public int getBalance() { return 잔고; }
	public void showAccount() { System.out.println("잔고는 " + getBalance()); }
	public abstract void deposit(int 금액);
	public abstract void withdraw(int 금액);
	public abstract void calInterest();

	protected void minusBalance(int 금액) { 잔고 -= 금액; }
	protected void plusBalance(int 금액) { 잔고 += 금액; }
}

class MinusAccount extends Account {
	private int 한도액;
	public MinusAccount(int 금액, int 한도액) {
		super(금액);
		this.한도액 = 한도액;
	}

	public void deposit(int 금액) { plusBalance(금액); }
	public void withdraw(int 금액) {
		if((getBalance() + 한도액) >= 금액) minusBalance(금액);
		else System.out.println("잔고가 부족합니다.");
	}
	public void calInterest() {
		if(getBalance() > 0) plusBalance((int)(getBalance() * 0.01));
		else minusBalance((int)(getBalance() * 0.05));
	}
}

class FreeAccount extends Account{
	public FreeAccount(int 금액) {
		super(금액);
	}

	public void deposit(int 금액) { plusBalance(금액); }
	public void withdraw(int 금액) {
		if((getBalance() - 금액) >= 0) minusBalance(금액);
		else System.out.println("잔고가 부족합니다.");
	}
	public void calInterest() {
		plusBalance((int)(getBalance() * 0.02));
	}
}

public class Main {
	public static void main(String[] args) {
		try {	
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("accounts.txt"));
		Account 홍 = new FreeAccount(1000);
		홍.showAccount();
		홍.calInterest();
		홍.showAccount();
		
		Account 김 = new MinusAccount(2000, 50000);
		김.showAccount();
		김.calInterest();
		김.showAccount();
		
		out.writeObject(홍);
		out.writeObject(김);
		out.flush();
		out.close();
		
		System.out.println();
	} catch (Exception e) {
		System.out.println("예외 발생");
	}
	}
}