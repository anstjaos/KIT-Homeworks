package BankFactory;

public class NormalAccount extends Account {
	public NormalAccount(String bankName) {
		this.bankName = bankName;
		accountNum = String.format("%08d", LastAccountNum);
		LastAccountNum++;
		balance = 0;
		accountType = "Normal Account";
	}
	
	public void withdraw(int money) {
		if(balance - money < 0) {
			System.out.println("�ܾ� ����! ��� �Ұ���");
			return;
		}
		
		balance = balance - money;
		System.out.println(money + "�� ��� �Ϸ�! ���� �ܾ��� " + balance+"�� �Դϴ�.");
	}

}
