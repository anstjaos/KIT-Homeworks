package Online_bank;

import javax.swing.JOptionPane;

public class CheckUserController implements ControllerInterface{
	private User user;
	
	public CheckUserController(User u) {
		user = u;
	}
	
	public void execute() {
		if(user.existId() == false) {
			JOptionPane.showMessageDialog(null, "사용 가능한 아이디입니다!");
		}
		else {
			JOptionPane.showMessageDialog(null, "이미 등록된 아이디입니다!");
		}
	}
}