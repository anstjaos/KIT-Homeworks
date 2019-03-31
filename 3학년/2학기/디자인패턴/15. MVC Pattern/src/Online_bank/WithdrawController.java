package Online_bank;

import javax.swing.JOptionPane;

public class WithdrawController implements ControllerInterface {
	private Account account;
	private WithdrawView withdrawView;
	
	public WithdrawController(Account a) {
		account = a;
		withdrawView = new WithdrawView(this, a);
	}
	
	public void execute() {
		int money = Integer.valueOf(withdrawView.txtMoney.getText());
		if(account.withdraw(money) == false) {
			JOptionPane.showMessageDialog(null, "출금 실패! 잔액이 부족합니다.");
			ControllerInterface ci = new UserMainController(account);
			return;
		}
		
		account.updateAccount();
		
		Transaction t = new Transaction(account.getAccountNum(), 1, money);
		t.registerTransaction();
		JOptionPane.showMessageDialog(null, "출금이 완료되었습니다.");
		
		withdrawView.setVisible(false);
		ControllerInterface ci = new UserMainController(account);
	}
}
