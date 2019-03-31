
public class NormalAccount extends Account {
	public NormalAccount() {
		accountNum = String.format("%08d", lastAccountNum);
		lastAccountNum++;
		
		ic = new NormalInterest();
	}
	
	public void withdraw(int money) {
		if(balance - money < 0) {
			System.out.println("잔고 부족 출금 실패!");
			return;
		}
		
		balance -= money;
		System.out.println("Normal Account 출금 완료!");
	}
}
