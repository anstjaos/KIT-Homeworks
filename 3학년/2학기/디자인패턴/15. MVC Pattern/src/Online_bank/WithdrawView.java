package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

public class WithdrawView extends JFrame {
	private ControllerInterface withdrawController;
	private Account account;
	
	private JPanel contentPane;
	public JTextField txtMoney;
	private JLabel labelBalance;
	private JLabel labelMoney;
	private JButton btnWithdraw;
	private JButton btnCancel;
	/**
	 * Create the frame.
	 */
	public WithdrawView(ControllerInterface ci, Account a) {
		withdrawController = ci;
		account = a;
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		labelBalance = new JLabel("현재 잔액은 " + account.getBalance() + "원 입니다.");
		labelBalance.setBounds(116, 41, 195, 18);
		contentPane.add(labelBalance);
		
		labelMoney = new JLabel("\uAE08\uC561\uC744 \uC785\uB825\uD558\uC138\uC694");
		labelMoney.setBounds(25, 110, 117, 18);
		contentPane.add(labelMoney);
		
		txtMoney = new JTextField();
		txtMoney.setBounds(167, 107, 188, 24);
		contentPane.add(txtMoney);
		txtMoney.setColumns(10);
		
		btnWithdraw = new JButton("\uCD9C\uAE08");
		btnWithdraw.setBounds(186, 214, 105, 27);
		contentPane.add(btnWithdraw);
		btnWithdraw.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				withdrawController.execute();
			}
		});
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(305, 214, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				withdrawController = new UserMainController(account);
			}
		});
		
		setVisible(true);
	}
}
