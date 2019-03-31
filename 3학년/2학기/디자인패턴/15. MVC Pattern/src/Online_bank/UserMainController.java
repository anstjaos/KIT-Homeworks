package Online_bank;

public class UserMainController implements ControllerInterface {
	private UserMainView userMainView;
	private Account account;

	public UserMainController(Account a) {
		account = a;
		userMainView = new UserMainView(this, a);
	}
	
	public void execute() {
	
	}
}
