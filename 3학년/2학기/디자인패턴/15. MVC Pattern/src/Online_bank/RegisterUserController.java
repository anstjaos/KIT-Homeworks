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
			JOptionPane.showMessageDialog(null, "비밀번호가 일치하지 않습니다!");
			return;
		}
		if(user.existId() == true) {
			JOptionPane.showMessageDialog(null, "이미 존재하는 ID입니다!");
			return;
		}
		
		user.registerUser();
		JOptionPane.showMessageDialog(null, "회원 등록 완료!");
		registerView.setVisible(false);
		ControllerInterface ci = new LoginController();
	}
}
