package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;

public class DepositView extends JFrame {
	private ControllerInterface depositController;
	private Account account;
	
	private JPanel contentPane;
	public JTextField txtMoney;
	private JButton btnDeposit;
	private JButton btnCancle;
	/**
	 * Create the frame.
	 */
	public DepositView(ControllerInterface ci, Account a) {
		depositController = ci;
		account = a;
		
		setTitle("\uC785\uAE08/\uCD9C\uAE08");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		btnDeposit = new JButton("\uC785\uAE08");
		btnDeposit.setBounds(160, 214, 105, 27);
		contentPane.add(btnDeposit);
		btnDeposit.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				depositController.execute();
			}
		});
		
		txtMoney = new JTextField();
		txtMoney.setBounds(247, 114, 116, 24);
		contentPane.add(txtMoney);
		txtMoney.setColumns(10);
		
		JLabel labelMoney = new JLabel("\uC785\uAE08\uD558\uC2E4 \uAE08\uC561\uC744 \uC785\uB825\uD558\uC138\uC694.");
		labelMoney.setBounds(14, 117, 197, 18);
		contentPane.add(labelMoney);
		
		btnCancle = new JButton("\uCDE8\uC18C");
		btnCancle.setBounds(306, 214, 105, 27);
		contentPane.add(btnCancle);
		btnCancle.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				depositController = new UserMainController(account);
			}
		});
		
		JLabel labelBalance = new JLabel("현재 잔액은 " + account.getBalance() + "원 입니다.");
		labelBalance.setBounds(108, 56, 215, 18);
		contentPane.add(labelBalance);
		
		setVisible(true);
	}
}
