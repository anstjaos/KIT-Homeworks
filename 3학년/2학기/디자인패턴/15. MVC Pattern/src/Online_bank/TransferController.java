package Online_bank;

import javax.swing.JOptionPane;

public class TransferController implements ControllerInterface {
	private TransferView transferView;
	private Account account;

	public TransferController(Account a) {
		account = a;
		transferView = new TransferView(this, a);
	}
	
	public void execute() {
		String targetAccountNum = transferView.txtAccountNum.getText();
		Account targetAccount = account.findAccount(targetAccountNum);
		if(targetAccount == null) {
			JOptionPane.showMessageDialog(null, "�������� �ʴ� ���� ��ȣ�Դϴ�.");
			return;
		}
		
		int money = Integer.valueOf(transferView.txtDeposit.getText());
		if(account.withdraw(money) == false) {
			JOptionPane.showMessageDialog(null, "���� ��ü ����! �ܾ� ����");
			return;
		}
		account.updateAccount();
		targetAccount.deposit(money);
		targetAccount.updateAccount();
		
		Transaction t = new Transaction(account.getAccountNum(), 2, money, targetAccount.getAccountNum());
		t.registerTransaction();
		
		JOptionPane.showMessageDialog(null, "���� ��ü ����!");
		
		transferView.setVisible(false);
		ControllerInterface ci = new UserMainController(account);
	}
}
