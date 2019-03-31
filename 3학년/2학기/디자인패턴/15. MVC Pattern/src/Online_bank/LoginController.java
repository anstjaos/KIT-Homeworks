package Online_bank;

import javax.swing.JOptionPane;

public class LoginController implements ControllerInterface{
	private LoginView loginView;
	private User user;
	
	public LoginController() {
		loginView = new LoginView(this);
	}
	
	public void execute() {
		String userId = loginView.txtID.getText();
		String password = String.valueOf(loginView.txtPwd.getPassword());
		
		user = new User(userId, password);
		if(user.loginUser() == false) {
			JOptionPane.showMessageDialog(null, "로그인에 실패하였습니다!");
			return;
		}
		
		loginView.setVisible(false);
		ControllerInterface ui = null;
		
		if(user.getType() == 0) ui = new UserInitController(user);
		else if(user.getType() == 1) ui = new ManagerController();
	}
}
