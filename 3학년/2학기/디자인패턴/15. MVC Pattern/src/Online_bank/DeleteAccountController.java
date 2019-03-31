package Online_bank;

import javax.swing.JOptionPane;

public class DeleteAccountController implements ControllerInterface {
	private DeleteAccountView deleteAccountView;

	public DeleteAccountController() {
		deleteAccountView = new DeleteAccountView(this);
	}
	
	public void execute() {
		String accountNum = deleteAccountView.txtAccountNum.getText();
		if(accountNum.equals("")) {
			JOptionPane.showMessageDialog(null, "���� ��ȣ�� �Է��ϼ���!");
			return;
		}
		Account a = new FreeAccount();
		a = a.findAccount(accountNum);
		if(a.removeAccount() == false) {
			JOptionPane.showMessageDialog(null, "���� ����!");
			return;
		}
		
		JOptionPane.showMessageDialog(null, "���� ����!");
		deleteAccountView.setVisible(false);
		new ManagerController();
	}
}
