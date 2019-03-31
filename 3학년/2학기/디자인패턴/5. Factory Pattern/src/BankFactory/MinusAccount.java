package BankFactory;

public class MinusAccount extends Account {
	protected int limit;
	
	public MinusAccount(String bankName, int limit){
		this.bankName = bankName;
		accountNum = String.format("%08d", LastAccountNum);
		LastAccountNum++;
		balance = 0;
		accountType = "Minus Account";
		this.limit = limit;
	}
	
	public void withdraw(int money) {
		if(balance - money < limit * -1) {
			System.out.println("�ѵ� �ʰ�! ��� �Ұ���");
			return;
		}
		
		balance = balance - money;
		System.out.println(money + "�� ��� �Ϸ�! ���� �ܾ��� " + balance+"�� �Դϴ�.");
	}
}
