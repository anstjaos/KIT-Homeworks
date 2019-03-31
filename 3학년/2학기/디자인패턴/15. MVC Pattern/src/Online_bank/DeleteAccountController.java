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
			JOptionPane.showMessageDialog(null, "계좌 번호를 입력하세요!");
			return;
		}
		Account a = new FreeAccount();
		a = a.findAccount(accountNum);
		if(a.removeAccount() == false) {
			JOptionPane.showMessageDialog(null, "삭제 실패!");
			return;
		}
		
		JOptionPane.showMessageDialog(null, "삭제 성공!");
		deleteAccountView.setVisible(false);
		new ManagerController();
	}
}
