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
			System.out.println("한도 초과! 출금 불가능");
			return;
		}
		
		balance = balance - money;
		System.out.println(money + "원 출금 완료! 현재 잔액은 " + balance+"원 입니다.");
	}
}
