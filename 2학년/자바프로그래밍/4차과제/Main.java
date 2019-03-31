import java.io.*;

abstract class Account implements Serializable {
	private int �ܰ�;
	
	public Account(int �ݾ�) { �ܰ� = �ݾ�; }

	public int getBalance() { return �ܰ�; }
	public void showAccount() { System.out.println("�ܰ�� " + getBalance()); }
	public abstract void deposit(int �ݾ�);
	public abstract void withdraw(int �ݾ�);
	public abstract void calInterest();

	protected void minusBalance(int �ݾ�) { �ܰ� -= �ݾ�; }
	protected void plusBalance(int �ݾ�) { �ܰ� += �ݾ�; }
}

class MinusAccount extends Account {
	private int �ѵ���;
	public MinusAccount(int �ݾ�, int �ѵ���) {
		super(�ݾ�);
		this.�ѵ��� = �ѵ���;
	}

	public void deposit(int �ݾ�) { plusBalance(�ݾ�); }
	public void withdraw(int �ݾ�) {
		if((getBalance() + �ѵ���) >= �ݾ�) minusBalance(�ݾ�);
		else System.out.println("�ܰ� �����մϴ�.");
	}
	public void calInterest() {
		if(getBalance() > 0) plusBalance((int)(getBalance() * 0.01));
		else minusBalance((int)(getBalance() * 0.05));
	}
}

class FreeAccount extends Account{
	public FreeAccount(int �ݾ�) {
		super(�ݾ�);
	}

	public void deposit(int �ݾ�) { plusBalance(�ݾ�); }
	public void withdraw(int �ݾ�) {
		if((getBalance() - �ݾ�) >= 0) minusBalance(�ݾ�);
		else System.out.println("�ܰ� �����մϴ�.");
	}
	public void calInterest() {
		plusBalance((int)(getBalance() * 0.02));
	}
}

public class Main {
	public static void main(String[] args) {
		try {	
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("accounts.txt"));
		Account ȫ = new FreeAccount(1000);
		ȫ.showAccount();
		ȫ.calInterest();
		ȫ.showAccount();
		
		Account �� = new MinusAccount(2000, 50000);
		��.showAccount();
		��.calInterest();
		��.showAccount();
		
		out.writeObject(ȫ);
		out.writeObject(��);
		out.flush();
		out.close();
		
		System.out.println();
	} catch (Exception e) {
		System.out.println("���� �߻�");
	}
	}
}