
public abstract class Account {
	protected String accountNum;
	protected int balance;
	static int lastAccountNum = 1;
	InterestCalculator ic;
	
	public int getBalance() { return balance; }
	public void deposit(int money) { balance += money; }
	public abstract void withdraw(int money);
	public void calcuateInterest() { balance += ic.calculateInterest(balance); }
}
