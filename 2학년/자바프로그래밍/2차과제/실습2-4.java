
import java.util.Scanner;

class Account {
	// instance variables
   	private long ���¹�ȣ, �ܰ�;
	private String ������;
	// static variable
	private static long ���������¹�ȣ=0L;
	// static method
	private static long nextAccountNumber() { return ++���������¹�ȣ; }
	// instance methods
	public long getAccountNum() { return ���¹�ȣ; }
	public String getName() { return ������; }
	public long getBalance() { return �ܰ�; }
	public void setBalance(long money) {�ܰ� = money;}
	// ������ - �Ű������� ���� ������ ��ü�� ���¸� �ʱ�ȭ�Ѵ�.
	Account(String ������, long ���ݾ�) {
		���¹�ȣ = nextAccountNumber();
		this.������ = ������;
		�ܰ� = ���ݾ�;
   	}
	// default ������
   	Account() {}
   	
} //End of Account

public class Bank {
	// instance variables
	private Account []accountList = new Account[100];
	private int count;
	// instance methods
	public void openAccount()
	{
		String name = Iohandler.getString("�̸��� �Է��ϼ���.");
		long money = Iohandler.getLong("�Ա��� ���� �Է��ϼ���.");
		
		Account ac = new Account(name, money);
		accountList[count++] = ac;
		Iohandler.putString("���°� �����Ǿ����ϴ� !");
		Iohandler.putString("������ ���¹�ȣ�� "+ accountList[count-1].getAccountNum() + "�Դϴ�.");
	}
	
	public int findAccount()
	{
		String name = Iohandler.getString("������ �����ָ� �Է��ϼ���.");
		long accountNum =  Iohandler.getLong("������ ���¹�ȣ�� �Է��ϼ���.");
		for(int i = 0; i < count; i++)
		{
			if(accountList[i].getName().equals(name) && accountList[i].getAccountNum() == accountNum)
			{
				return i;
			}
		}
		Iohandler.putString("�Է��� ������ ��ġ�ϴ� ���� �����ϴ�!");
		return -1;
	}
	
	public void checkBalance(int i_count){
		Iohandler.putString("������ �ܰ�� " +accountList[i_count].getBalance() +"�Դϴ�." ); 
	}
	
	public void deposit(int i_count)
	{
		long ���ݾ� = Iohandler.getLong("���ݾ��� �Է��ϼ���.");
		long money = accountList[i_count].getBalance() + ���ݾ�;
		accountList[i_count].setBalance(money);
		checkBalance(i_count);
	}
	
	public void withdraw(int i_count)
	{
		long ��ݾ� = Iohandler.getLong("��ݾ��� �Է��ϼ���.");
		if(accountList[i_count].getBalance() <= ��ݾ�)
		{
			checkBalance(i_count);
			Iohandler.putString("���� " + accountList[i_count].getBalance() + "���� ��ݵǾ����ϴ�.");
			accountList[i_count].setBalance(0);
			checkBalance(i_count);
		}
		else
		{
			long money = accountList[i_count].getBalance() - ��ݾ�;
			accountList[i_count].setBalance(money);
			checkBalance(i_count);
		}
	}
	// ������
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
				b.openAccount();		// ���� ����
				break;
			case 2:
				int i_count = b.findAccount();	// �ܰ� ��ȸ
				if(i_count == -1) break;
				else 
					b.checkBalance(i_count);
					break;
			case 3:
				int d_count = b.findAccount();	// �Ա��ϱ�
				if(d_count == -1) break;
				else 
					b.deposit(d_count);
					break;
			case 4:
				int w_count = b.findAccount();	// ����ϱ�
				if(w_count == -1) break;
				else
					b.withdraw(w_count);
					break;
				default:
					Iohandler.putString("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�!");
					break;
					
			}
		}
   	} // End of main
   	
} // End of Bank

class Iohandler {			// ������� ����ϴ� Ŭ����
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
		System.out.println("�޴��� �����Ͽ� �ּ���.");
		System.out.println("1.���°���  2.�ܰ���ȸ  3.�Ա�  4.���");
		int num = input.nextInt();
		return num;
	}
	

	Iohandler() {}
}// End of Iohandler

