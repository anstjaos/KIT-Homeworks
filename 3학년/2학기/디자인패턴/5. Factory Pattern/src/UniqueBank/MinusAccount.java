package UniqueBank;

public class MinusAccount extends Account {
	private int limit;
	public MinusAccount(String branchName, int limit){
		this.branchName = branchName;
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
