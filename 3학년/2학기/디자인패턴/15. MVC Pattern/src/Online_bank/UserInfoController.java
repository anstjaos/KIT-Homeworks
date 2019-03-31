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
			JOptionPane.showMessageDialog(null, "미기입 정보가 있습니다!");
			return;
		}
		
		user.setPassword(pwd);
		user.setAddress(address);
		user.setPhoneNum(phoneNum);
		
		user.updateUser();
		JOptionPane.showMessageDialog(null, "회원 정보 수정이 완료되었습니다.");
		userInfoView.setVisible(false);
		
		ControllerInterface ci = new UserInitController(user);
	}
}
