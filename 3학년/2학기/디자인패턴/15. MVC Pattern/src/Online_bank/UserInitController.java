package Online_bank;

import javax.swing.JOptionPane;

public class UserInitController implements ControllerInterface {
	private User user;
	private UserInitView userInitView;

	public UserInitController(User u) {
		user = u;
		userInitView = new UserInitView(this, user);
	}
	
	public void execute() {
		int index = userInitView.listAccount.getSelectedIndex();
		if(index < 0) {
			JOptionPane.showMessageDialog(null, "계좌를 선택해주십시오.");
			return;
		}
		
		Account a = userInitView.al.get(index);
		userInitView.setVisible(false);
		ControllerInterface ci = new UserMainController(a);
	}
}
