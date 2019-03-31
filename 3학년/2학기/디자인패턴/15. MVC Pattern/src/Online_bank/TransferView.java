package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class TransferView extends JFrame {
	private ControllerInterface transferController;
	private Account account;
	
	private JPanel contentPane;
	public JTextField txtAccountNum;
	public JTextField txtDeposit;
	private JButton btnTransfer;
	private JButton btnCancel;
	/**
	 * Create the frame.
	 */
	public TransferView(ControllerInterface ci, Account a) {
		transferController = ci;
		account = a;
		
		setTitle("\uACC4\uC88C \uC774\uCCB4");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		btnTransfer = new JButton("\uACC4\uC88C\uC774\uCCB4");
		btnTransfer.setBounds(197, 214, 105, 27);
		contentPane.add(btnTransfer);
		btnTransfer.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				transferController.execute();
			}
		});
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(313, 214, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				transferController = new UserMainController(account);
			}
		});
		
		JLabel labelAccountNum = new JLabel("\uACC4\uC88C\uBC88\uD638\uB97C \uC785\uB825\uD558\uC138\uC694");
		labelAccountNum.setBounds(14, 101, 153, 18);
		contentPane.add(labelAccountNum);
		
		txtAccountNum = new JTextField();
		txtAccountNum.setBounds(197, 98, 116, 24);
		contentPane.add(txtAccountNum);
		txtAccountNum.setColumns(10);
		
		JLabel labelDeposit = new JLabel("\uC785\uAE08\uD558\uC2E4 \uAE08\uC561\uC744 \uC785\uB825\uD558\uC138\uC694");
		labelDeposit.setBounds(14, 152, 190, 18);
		contentPane.add(labelDeposit);
		
		txtDeposit = new JTextField();
		txtDeposit.setBounds(197, 149, 116, 24);
		contentPane.add(txtDeposit);
		txtDeposit.setColumns(10);
		
		JLabel labelBalance = new JLabel("현재 잔액은 " + account.getBalance() + "원 입니다.");
		labelBalance.setBounds(14, 41, 274, 18);
		contentPane.add(labelBalance);
		
		setVisible(true);
	}

}
