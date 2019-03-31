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
		System.out.println(money + "원 입금 완료. 현재 잔액은 " + balance + "원 입니다.");
	}
	
	public String getAccountInform() {
		return "지점명 : " + branchName + "\n계좌 번호 : " + accountNum + "\n계좌 타입 : " + accountType + "\n현재 잔액 : "+ balance + "\n";
	}
}
