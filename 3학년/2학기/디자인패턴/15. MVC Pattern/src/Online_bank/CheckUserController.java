package Online_bank;

import javax.swing.JOptionPane;

public class CheckUserController implements ControllerInterface{
	private User user;
	
	public CheckUserController(User u) {
		user = u;
	}
	
	public void execute() {
		if(user.existId() == false) {
			JOptionPane.showMessageDialog(null, "��� ������ ���̵��Դϴ�!");
		}
		else {
			JOptionPane.showMessageDialog(null, "�̹� ��ϵ� ���̵��Դϴ�!");
		}
	}
}