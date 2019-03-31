package Online_bank;

import javax.swing.JOptionPane;

public class RegisterAccountController implements ControllerInterface {
	private RegisterAccountView registerView;

	public RegisterAccountController() {
		registerView = new RegisterAccountView(this);
	}
	
	public void execute() {
		String ownerId = registerView.txtOwner.getText();
		if(ownerId.equals("") || registerView.txtFirstMoney.getText().equals("")) {
			JOptionPane.showMessageDialog(null, "미기입 정보가 있습니다!");
			return;
		}
		int money = Integer.parseInt(registerView.txtFirstMoney.getText());
		int type = registerView.comboBox.getSelectedIndex();
		if(type < 0) {
			JOptionPane.showMessageDialog(null, "미기입 정보가 있습니다!");
			return;
		}
		else if(type == 1 && registerView.txtCreditLimit.getText().equals("")) {
			JOptionPane.showMessageDialog(null, "미기입 정보가 있습니다!");
			return;
		}
		 int creditLimit = 0;
		if(type == 1) creditLimit = Integer.valueOf(registerView.txtCreditLimit.getText());
		
		Account a = null;
		if(type == 0) a = new FreeAccount(ownerId, money);
		else if(type == 1) a = new MinusAccount(ownerId, money, creditLimit);
		
		a.registerAccount();
		
		JOptionPane.showMessageDialog(null, "계좌 등록 완료!");
		registerView.setVisible(false);
		ControllerInterface ci = new ManagerController();
	}
}
