package BankFactory;

public class BankTest {

	public static void main(String[] args) {
		Account ac; Bank b;
		
		b = new BankA();
		
		ac = b.createAccount("보통계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else {
			ac.deposit(1000);
			ac.withdraw(500);
			System.out.println(ac.getAccountInform());
		}

		ac = b.createAccount("마이너스계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else {
			ac.deposit(1000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}
		
		b = new BankB();
		ac = b.createAccount("마이너스계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else {
			ac.deposit(10000);
			ac.withdraw(50000);
			System.out.println(ac.getAccountInform());
		}

		ac = b.createAccount("증권계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else {
			ac.deposit(1000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}

		b = new BankC();
		ac = b.createAccount("보통계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else {
			ac.deposit(10000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}
		
		ac = b.createAccount("증권계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else {
			ac.deposit(100000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}
	}

}
