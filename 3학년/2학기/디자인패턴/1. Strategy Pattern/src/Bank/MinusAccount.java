
public class MinusAccount extends Account {
	private int creditLimit;
	
	public MinusAccount(int i_creditLimit) {
		accountNum = String.format("%08d", lastAccountNum);
		lastAccountNum++;
		creditLimit = i_creditLimit;
		
		ic = new MinusInterest();
	}
	
	public void withdraw(int money) {
		if(balance - money < creditLimit) {
			System.out.println("��� ����!");
			return;
		}
		
		balance -= money;
		System.out.println("Minus Account ��� �Ϸ�!");
	}
	
	public void setCreditLimit(int i_creditLimit) { creditLimit = i_creditLimit; }
}
