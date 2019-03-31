package UniqueBank;

public class BankTest {

	public static void main(String[] args) {
		BankFactory bf = new BankFactory();
		SEBank sb; Account ac;
		
		sb = new SEBankKIT(bf);
		ac = sb.newAccount("보통계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else System.out.println("계좌 생성 완료!\n" + ac.getAccountInform());
		
		ac.deposit(10000);
		ac.withdraw(9000);
		
		ac = sb.newAccount("마이너스계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else System.out.println("계좌 생성 완료!\n" + ac.getAccountInform());
		
		ac.deposit(10000);
		ac.withdraw(13000);
		
		sb = new SEBankOkgye(bf);
		ac = sb.newAccount("증권계좌");
		if(ac == null) System.out.println("계좌 생성 실패!");
		else System.out.println("계좌 생성 완료!\n" + ac.getAccountInform());
		
		ac.deposit(10000);
		ac.withdraw(13000);
		ac.withdraw(3000);
	}

}
