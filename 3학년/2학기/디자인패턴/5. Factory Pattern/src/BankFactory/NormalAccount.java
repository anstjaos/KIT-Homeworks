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
			System.out.println("잔액 부족! 출금 불가능");
			return;
		}
		
		balance = balance - money;
		System.out.println(money + "원 출금 완료! 현재 잔액은 " + balance+"원 입니다.");
	}

}
