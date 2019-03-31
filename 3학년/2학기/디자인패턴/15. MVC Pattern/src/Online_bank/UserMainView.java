package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class UserMainView extends JFrame {
	private ControllerInterface userMainController;
	private Account account;
	
	private JPanel contentPane;
	private JButton btnDeposit;
	private JButton btnTransfer;
	private JButton btnShowProduct;
	private JButton btnSelectAccount;
	private JButton btnTransaction;
	private JButton btnWithdraw;
	
	/**
	 * Create the frame.
	 */
	public UserMainView(ControllerInterface ci, Account a) {
		userMainController = ci;
		account = a;
		
		setTitle("\uC0AC\uC6A9\uC790 \uBA54\uC778 \uD654\uBA74");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		btnDeposit = new JButton("\uC785\uAE08");
		btnDeposit.setBounds(42, 70, 105, 27);
		contentPane.add(btnDeposit);
		btnDeposit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
				userMainController = new DepositController(a);
			}
		});
		
		btnTransfer = new JButton("\uACC4\uC88C\uC774\uCCB4");
		btnTransfer.setBounds(272, 70, 105, 27);
		contentPane.add(btnTransfer);
		btnTransfer.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				userMainController = new TransferController(account);
			}
		});
		
		btnShowProduct = new JButton("\uC0C8 \uC0C1\uD488 \uC870\uD68C");
		btnShowProduct.setBounds(262, 140, 124, 27);
		contentPane.add(btnShowProduct);
		btnShowProduct.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				userMainController = new ProductInfoController(account);
			}
		});
		
		btnSelectAccount = new JButton("\uB2E4\uB978 \uACC4\uC88C \uC120\uD0DD");
		btnSelectAccount.setBounds(257, 210, 134, 27);
		contentPane.add(btnSelectAccount);
		btnSelectAccount.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				userMainController = new SelectAccountController(account);
				userMainController.execute();
			}
		});
		
		btnTransaction = new JButton("\uAC70\uB798 \uB0B4\uC5ED \uC870\uD68C");
		btnTransaction.setBounds(27, 210, 134, 27);
		contentPane.add(btnTransaction);
		btnTransaction.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				userMainController = new TransactionController(account);
			}
		});
		
		JLabel labelBalance = new JLabel("\uD604\uC7AC \uC794\uC561\uC740 30000\uC6D0 \uC785\uB2C8\uB2E4.");
		labelBalance.setBounds(104, 32, 273, 18);
		contentPane.add(labelBalance);
		labelBalance.setText("현재 잔액은 " + account.getBalance() + "원 입니다.");
		
		btnWithdraw = new JButton("\uCD9C\uAE08");
		btnWithdraw.setBounds(42, 140, 105, 27);
		contentPane.add(btnWithdraw);
		btnWithdraw.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				userMainController = new WithdrawController(account);
			}
		});
		
		setVisible(true);
	}
}
