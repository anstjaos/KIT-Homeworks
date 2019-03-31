package UniqueBank;

public abstract class Account {
	protected String branchName;
	protected String accountNum;
	protected int balance;
	protected String accountType;
	protected static int LastAccountNum = 1;
	
	public abstract void withdraw(int money);
	
	public void deposit(int money) {
		balance += money;
		System.out.println(money + "�� �Ա� �Ϸ�. ���� �ܾ��� " + balance + "�� �Դϴ�.");
	}
	
	public String getAccountInform() {
		return "������ : " + branchName + "\n���� ��ȣ : " + accountNum + "\n���� Ÿ�� : " + accountType + "\n���� �ܾ� : "+ balance + "\n";
	}
}
