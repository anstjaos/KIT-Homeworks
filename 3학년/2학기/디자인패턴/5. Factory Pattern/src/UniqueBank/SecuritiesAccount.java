package UniqueBank;

public class SecuritiesAccount extends Account {
	public SecuritiesAccount(String branchName) {
		this.branchName = branchName;
		accountNum = String.format("%08d", LastAccountNum);
		LastAccountNum++;
		balance = 0;
		accountType = "Securities Account";
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
