
import java.util.Scanner;

class Account {
	// instance variables
   	private long 계좌번호, 잔고;
	private String 예금주;
	// static variable
	private static long 마지막계좌번호=0L;
	// static method
	private static long nextAccountNumber() { return ++마지막계좌번호; }
	// instance methods
	public long getAccountNum() { return 계좌번호; }
	public String getName() { return 예금주; }
	public long getBalance() { return 잔고; }
	public void setBalance(long money) {잔고 = money;}
	// 생성자 - 매개변수로 받은 값으로 객체의 상태를 초기화한다.
	Account(String 예금주, long 예금액) {
		계좌번호 = nextAccountNumber();
		this.예금주 = 예금주;
		잔고 = 예금액;
   	}
	// default 생성자
   	Account() {}
   	
} //End of Account

public class Bank {
	// instance variables
	private Account []accountList = new Account[100];
	private int count;
	// instance methods
	public void openAccount()
	{
		String name = Iohandler.getString("이름을 입력하세요.");
		long money = Iohandler.getLong("입금할 돈을 입력하세요.");
		
		Account ac = new Account(name, money);
		accountList[count++] = ac;
		Iohandler.putString("계좌가 개설되었습니다 !");
		Iohandler.putString("고객님의 계좌번호는 "+ accountList[count-1].getAccountNum() + "입니다.");
	}
	
	public int findAccount()
	{
		String name = Iohandler.getString("계좌의 예금주를 입력하세요.");
		long accountNum =  Iohandler.getLong("계좌의 계좌번호를 입력하세요.");
		for(int i = 0; i < count; i++)
		{
			if(accountList[i].getName().equals(name) && accountList[i].getAccountNum() == accountNum)
			{
				return i;
			}
		}
		Iohandler.putString("입력한 정보와 일치하는 고객이 없습니다!");
		return -1;
	}
	
	public void checkBalance(int i_count){
		Iohandler.putString("고객님의 잔고는 " +accountList[i_count].getBalance() +"입니다." ); 
	}
	
	public void deposit(int i_count)
	{
		long 예금액 = Iohandler.getLong("예금액을 입력하세요.");
		long money = accountList[i_count].getBalance() + 예금액;
		accountList[i_count].setBalance(money);
		checkBalance(i_count);
	}
	
	public void withdraw(int i_count)
	{
		long 출금액 = Iohandler.getLong("출금액을 입력하세요.");
		if(accountList[i_count].getBalance() <= 출금액)
		{
			checkBalance(i_count);
			Iohandler.putString("따라서 " + accountList[i_count].getBalance() + "원만 출금되었습니다.");
			accountList[i_count].setBalance(0);
			checkBalance(i_count);
		}
		else
		{
			long money = accountList[i_count].getBalance() - 출금액;
			accountList[i_count].setBalance(money);
			checkBalance(i_count);
		}
	}
	// 생성자
	Bank()
	{ 
		for(int i = 0; i < 100; i++)
		{
			accountList[i] = new Account();
		}
		count = 0;
	}
	
   	public static void main(String[] args) {
		Bank b = new Bank();
		
		while(true)
		{
			int menu = Iohandler.getMenu();
			switch(menu)
			{
			case 1:
				b.openAccount();		// 계좌 개설
				break;
			case 2:
				int i_count = b.findAccount();	// 잔고 조회
				if(i_count == -1) break;
				else 
					b.checkBalance(i_count);
					break;
			case 3:
				int d_count = b.findAccount();	// 입금하기
				if(d_count == -1) break;
				else 
					b.deposit(d_count);
					break;
			case 4:
				int w_count = b.findAccount();	// 출금하기
				if(w_count == -1) break;
				else
					b.withdraw(w_count);
					break;
				default:
					Iohandler.putString("잘못된 번호를 입력하셨습니다!");
					break;
					
			}
		}
   	} // End of main
   	
} // End of Bank

class Iohandler {			// 입출력을 담당하는 클래스
	// static methods
	public static Scanner input = new Scanner(System.in);
	public static String getString(String msg)
	{
		System.out.println(msg);
		String str = input.next();
		return str;
	}
	public static long getLong(String msg)
	{
		System.out.println(msg);
		long str = input.nextLong();
		return str;
	}
	public static void putString(String msg) { System.out.println(msg); }
	
	public static int getMenu() {
		System.out.println("메뉴를 선택하여 주세요.");
		System.out.println("1.계좌개설  2.잔고조회  3.입금  4.출금");
		int num = input.nextInt();
		return num;
	}
	

	Iohandler() {}
}// End of Iohandler

