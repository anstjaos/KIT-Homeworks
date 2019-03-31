package BankFactory;

public abstract class Account {
	protected String bankName;
	protected String accountNum;
	protected int balance;
	protected String accountType;
	protected static int LastAccountNum = 1;
	
	public abstract void withdraw(int money);
	public void deposit(int money) {
		balance = balance + money;
		System.out.println(money + "�� �Ա� �Ϸ�! ���� �ܾ��� " + balance + "�� �Դϴ�.");
	}
	
	public String getAccountInform() {
		return "����� : " + bankName + "\n���� ��ȣ : " + accountNum + "\n���� Ÿ�� : " + accountType + "\n���� �ܾ� : "+ balance + "\n"; 
	}
}