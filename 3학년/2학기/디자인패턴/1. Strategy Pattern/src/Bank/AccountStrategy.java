
public class AccountStrategy {

	public static void main(String[] args) {
		Account na = new NormalAccount();
		na.deposit(10000);
		System.out.println("Normal Account의 잔고는 " +na.getBalance() + "원 입니다." );
		na.calcuateInterest();
		System.out.println("Normal Account의 잔고는 " +na.getBalance() + "원 입니다." );
		na.withdraw(10000);
		System.out.println("Normal Account의 잔고는 " +na.getBalance() + "원 입니다." );
		System.out.println("==========================================" );
		
		Account ma = new MinusAccount(-10000);
		ma.deposit(1000);
		System.out.println("Minus Account의 잔고는 " +ma.getBalance() + "원 입니다." );
		ma.withdraw(3000);
		System.out.println("Minus Account의 잔고는 " +ma.getBalance() + "원 입니다." );
		ma.calcuateInterest();
		System.out.println("Minus Account의 잔고는 " +ma.getBalance() + "원 입니다." );
		System.out.println("==========================================" );
		
		Account sa = new SavingAccount();
		sa.deposit(10000);
		System.out.println("Saving Account의 잔고는 " +sa.getBalance() + "원 입니다." );
		sa.withdraw(1000);
		sa.calcuateInterest();
		System.out.println("Saving Account의 잔고는 " +sa.getBalance() + "원 입니다." );
		System.out.println("==========================================" );
	}

}
