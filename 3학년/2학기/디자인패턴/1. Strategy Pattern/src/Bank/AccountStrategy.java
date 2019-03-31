
public class AccountStrategy {

	public static void main(String[] args) {
		Account na = new NormalAccount();
		na.deposit(10000);
		System.out.println("Normal Account�� �ܰ�� " +na.getBalance() + "�� �Դϴ�." );
		na.calcuateInterest();
		System.out.println("Normal Account�� �ܰ�� " +na.getBalance() + "�� �Դϴ�." );
		na.withdraw(10000);
		System.out.println("Normal Account�� �ܰ�� " +na.getBalance() + "�� �Դϴ�." );
		System.out.println("==========================================" );
		
		Account ma = new MinusAccount(-10000);
		ma.deposit(1000);
		System.out.println("Minus Account�� �ܰ�� " +ma.getBalance() + "�� �Դϴ�." );
		ma.withdraw(3000);
		System.out.println("Minus Account�� �ܰ�� " +ma.getBalance() + "�� �Դϴ�." );
		ma.calcuateInterest();
		System.out.println("Minus Account�� �ܰ�� " +ma.getBalance() + "�� �Դϴ�." );
		System.out.println("==========================================" );
		
		Account sa = new SavingAccount();
		sa.deposit(10000);
		System.out.println("Saving Account�� �ܰ�� " +sa.getBalance() + "�� �Դϴ�." );
		sa.withdraw(1000);
		sa.calcuateInterest();
		System.out.println("Saving Account�� �ܰ�� " +sa.getBalance() + "�� �Դϴ�." );
		System.out.println("==========================================" );
	}

}
