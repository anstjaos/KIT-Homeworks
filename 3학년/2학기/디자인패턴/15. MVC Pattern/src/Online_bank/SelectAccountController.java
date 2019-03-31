package Online_bank;

public class SelectAccountController implements ControllerInterface{
	private Account account;
	
	public SelectAccountController(Account a) {
		account = a;
	}
	
	public void execute() {
		User user = new User(account.getOwnerId(),"");
		user.findUser();
		
		if(user.getPassword().equals("")) {
			return;
		}
		
		ControllerInterface ci = new UserInitController(user);
	}
}
