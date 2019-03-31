package BankFactory;

public class BankTest {

	public static void main(String[] args) {
		Account ac; Bank b;
		
		b = new BankA();
		
		ac = b.createAccount("�������");
		if(ac == null) System.out.println("���� ���� ����!");
		else {
			ac.deposit(1000);
			ac.withdraw(500);
			System.out.println(ac.getAccountInform());
		}

		ac = b.createAccount("���̳ʽ�����");
		if(ac == null) System.out.println("���� ���� ����!");
		else {
			ac.deposit(1000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}
		
		b = new BankB();
		ac = b.createAccount("���̳ʽ�����");
		if(ac == null) System.out.println("���� ���� ����!");
		else {
			ac.deposit(10000);
			ac.withdraw(50000);
			System.out.println(ac.getAccountInform());
		}

		ac = b.createAccount("���ǰ���");
		if(ac == null) System.out.println("���� ���� ����!");
		else {
			ac.deposit(1000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}

		b = new BankC();
		ac = b.createAccount("�������");
		if(ac == null) System.out.println("���� ���� ����!");
		else {
			ac.deposit(10000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}
		
		ac = b.createAccount("���ǰ���");
		if(ac == null) System.out.println("���� ���� ����!");
		else {
			ac.deposit(100000);
			ac.withdraw(5000);
			System.out.println(ac.getAccountInform());
		}
	}

}
