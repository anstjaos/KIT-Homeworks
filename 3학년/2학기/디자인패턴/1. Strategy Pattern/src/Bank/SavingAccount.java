
import java.util.Date;

public class SavingAccount extends Account {
	Date ContractExpirationDate;
	
	public SavingAccount() {
		accountNum = String.format("%08d", lastAccountNum);
		lastAccountNum++;
		ContractExpirationDate = new Date(2018, 11, 30,0,0,0);
		
		ic = new SavingInterest();
	}
	
	public void withdraw(int money) {
		Date curDate = new Date();
		if(curDate.getTime() != ContractExpirationDate.getTime()) {
			System.out.println("��� �������� �ƴմϴ�! ��� ����!");
			return;
		}
		
		balance -= money;
		System.out.println("Saving Account ��� �Ϸ�!");
	}
}
