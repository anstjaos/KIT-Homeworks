package Online_bank;

import javax.swing.JOptionPane;

public class RegisterUserController implements ControllerInterface {
	private RegisterView registerView;
	private User user;
	
	public RegisterUserController(User u) {
		user = u;
		registerView = new RegisterView(this, u);
	}
	
	public void execute() {
		if(user.getPassword().equals(String.valueOf(registerView.txtCheckPwd.getPassword())) == false) {
			JOptionPane.showMessageDialog(null, "��й�ȣ�� ��ġ���� �ʽ��ϴ�!");
			return;
		}
		if(user.existId() == true) {
			JOptionPane.showMessageDialog(null, "�̹� �����ϴ� ID�Դϴ�!");
			return;
		}
		
		user.registerUser();
		JOptionPane.showMessageDialog(null, "ȸ�� ��� �Ϸ�!");
		registerView.setVisible(false);
		ControllerInterface ci = new LoginController();
	}
}
