
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
			System.out.println("출금 실패!");
			return;
		}
		
		balance -= money;
		System.out.println("Minus Account 출금 완료!");
	}
	
	public void setCreditLimit(int i_creditLimit) { creditLimit = i_creditLimit; }
}
