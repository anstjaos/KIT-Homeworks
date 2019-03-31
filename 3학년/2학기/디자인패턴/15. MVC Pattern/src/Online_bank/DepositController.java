package Online_bank;

import javax.swing.JOptionPane;

public class DepositController implements ControllerInterface{
	private Account account;
	private DepositView depositView;
	
	public DepositController(Account a) {
		account = a;
		depositView = new DepositView(this, a);
	}
	
	public void execute() {
		int money = Integer.parseInt(depositView.txtMoney.getText());
		account.deposit(money);
		account.updateAccount();
		
		Transaction t = new Transaction(account.getAccountNum(), 0, money);
		t.registerTransaction();
		
		JOptionPane.showMessageDialog(null, "입금이 완료되었습니다.");
		depositView.setVisible(false);
		ControllerInterface ci = new UserMainController(account);
	}
}
