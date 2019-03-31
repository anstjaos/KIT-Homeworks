package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JList;

public class TransactionView extends JFrame {
	private ControllerInterface transactionController;
	private Account account;
	public int day;
	
	private JPanel contentPane;
	private JTextField txtMonth;
	private JButton btnToday;
	private JButton btnWeek;
	private JButton btnMonth;
	public JList listTransaction;
	public Vector<String> list;
	/**
	 * Create the frame.
	 */
	public TransactionView(ControllerInterface ci, Account a) {
		transactionController = ci;
		account = a;
		
		setTitle("\uAC70\uB798 \uB0B4\uC5ED \uC870\uD68C");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 357);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		list = new Vector<String>();
		listTransaction = new JList(list);
		listTransaction.setBounds(14, 69, 404, 172);
		contentPane.add(listTransaction);
		
		btnToday = new JButton("\uB2F9\uC77C");
		btnToday.setBounds(14, 30, 61, 27);
		contentPane.add(btnToday);
		btnToday.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				day = 0;
				transactionController.execute();
			}
		});
		
		btnWeek = new JButton("\uC77C\uC8FC\uC77C");
		btnWeek.setBounds(101, 30, 88, 27);
		contentPane.add(btnWeek);
		btnWeek.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				day = 7;
				transactionController.execute();
			}
		} );
		
		btnMonth = new JButton("\uAC1C\uC6D4");
		btnMonth.setBounds(337, 30, 81, 27);
		contentPane.add(btnMonth);
		btnMonth.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String month = txtMonth.getText();
				if(month.equals("")) return;
				day = 30 * Integer.parseInt(month);
				transactionController.execute();
			}
		});
		
		txtMonth = new JTextField();
		txtMonth.setBounds(207, 31, 116, 24);
		contentPane.add(txtMonth);
		txtMonth.setColumns(10);
		
		JButton btnOK = new JButton("\uD655\uC778");
		btnOK.setBounds(313, 271, 105, 27);
		contentPane.add(btnOK);
		btnOK.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				transactionController = new UserMainController(account);
			}
		});
		
		setVisible(true);
	}
}
