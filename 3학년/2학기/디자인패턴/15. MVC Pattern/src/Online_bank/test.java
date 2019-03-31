package Online_bank;

import java.util.ArrayList;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new FreeAccount().initLastAccountNum();
		new Transaction().initLastTransactionNum();
		new ProductInformation().initLastPiNum();
		
		ControllerInterface ci = new LoginController();
	}
}
