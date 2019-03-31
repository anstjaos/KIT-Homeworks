package UniqueBank;

public class BankTest {

	public static void main(String[] args) {
		BankFactory bf = new BankFactory();
		SEBank sb; Account ac;
		
		sb = new SEBankKIT(bf);
		ac = sb.newAccount("�������");
		if(ac == null) System.out.println("���� ���� ����!");
		else System.out.println("���� ���� �Ϸ�!\n" + ac.getAccountInform());
		
		ac.deposit(10000);
		ac.withdraw(9000);
		
		ac = sb.newAccount("���̳ʽ�����");
		if(ac == null) System.out.println("���� ���� ����!");
		else System.out.println("���� ���� �Ϸ�!\n" + ac.getAccountInform());
		
		ac.deposit(10000);
		ac.withdraw(13000);
		
		sb = new SEBankOkgye(bf);
		ac = sb.newAccount("���ǰ���");
		if(ac == null) System.out.println("���� ���� ����!");
		else System.out.println("���� ���� �Ϸ�!\n" + ac.getAccountInform());
		
		ac.deposit(10000);
		ac.withdraw(13000);
		ac.withdraw(3000);
	}

}
