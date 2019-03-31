package Online_bank;

import javax.swing.JOptionPane;

public class UserInfoController implements ControllerInterface {
	private UserInfoView userInfoView;
	private User user;

	public UserInfoController(User u) {
		user = u;
		userInfoView = new UserInfoView(this, u);
	}
	
	public void execute() {
		String pwd = String.valueOf(userInfoView.txtPwd.getPassword());
		String address = userInfoView.txtAddress.getText();
		String phoneNum = userInfoView.txtPhoneNum.getText();
		
		if(pwd.equals("") || address.equals("") || phoneNum.equals("")) {
			JOptionPane.showMessageDialog(null, "�̱��� ������ �ֽ��ϴ�!");
			return;
		}
		
		user.setPassword(pwd);
		user.setAddress(address);
		user.setPhoneNum(phoneNum);
		
		user.updateUser();
		JOptionPane.showMessageDialog(null, "ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�.");
		userInfoView.setVisible(false);
		
		ControllerInterface ci = new UserInitController(user);
	}
}
