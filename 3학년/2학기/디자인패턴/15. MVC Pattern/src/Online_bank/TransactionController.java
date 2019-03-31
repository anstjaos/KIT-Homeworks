package Online_bank;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Vector;

import javax.swing.JList;

public class TransactionController implements ControllerInterface {
	private TransactionView transactionView;
	private Account account;

	public TransactionController(Account a) {
		account = a;
		transactionView = new TransactionView(this, account);
	}
	
	public void execute() {
		transactionView.listTransaction.removeAll();
		transactionView.list.removeAllElements();
		int day = transactionView.day;
		
		Calendar calendar = Calendar.getInstance();
		calendar.add(Calendar.DAY_OF_MONTH, -day);
		//date가 일주일전 Date 객체 입니다.
		DateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
		String date = dateFormat.format(calendar.getTime());
		
		ArrayList<Transaction> tl = new Transaction().selectTransactionsByDate(account.getAccountNum(), date);

		for(int i = 0 ; i < tl.size(); i++) {
			Transaction t = tl.get(i);
			String txt = t.getAccountNum();
			switch(t.getType()) {
			case 0:
				txt += " 입금 ";
				break;
			case 1:
				txt += " 출금 ";
				break;
			case 2:
				txt += " 계좌이체 ";
				break;
			}
			txt += t.getMoney() + "원 ";
			
			if(t.getType() == 2) {
				txt += t.getTargetAccountNum();
			}
			transactionView.list.add(txt);
		}
		transactionView.listTransaction.updateUI();
	}
}
