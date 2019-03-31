package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.management.relation.RelationServiceNotRegisteredException;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;

public class RegisterAccountView extends JFrame {
	private ControllerInterface registerAccountController;
	
	private JPanel contentPane;
	public JTextField txtOwner;
	public JTextField txtFirstMoney;
	private JButton btnRegister;
	private JButton btnCancel;
	public JComboBox comboBox;
	private JLabel labelCreditLimit;
	public JTextField txtCreditLimit;
	/**
	 * Create the frame.
	 */
	public RegisterAccountView(ControllerInterface ci) {
		registerAccountController = ci;
		
		setTitle("\uACC4\uC88C \uB4F1\uB85D");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelOwner = new JLabel("\uC18C\uC720\uC8FC");
		labelOwner.setBounds(58, 28, 62, 18);
		contentPane.add(labelOwner);
		
		btnRegister = new JButton("\uB4F1\uB85D");
		btnRegister.setBounds(187, 214, 105, 27);
		contentPane.add(btnRegister);
		btnRegister.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				registerAccountController.execute();
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
				registerAccountController = new ManagerController();
			}
		});
		
		txtOwner = new JTextField();
		txtOwner.setBounds(188, 25, 116, 24);
		contentPane.add(txtOwner);
		txtOwner.setColumns(10);
		
		JLabel labelFirstMoney = new JLabel("\uCD08\uAE30 \uAE08\uC561");
		labelFirstMoney.setBounds(58, 77, 62, 18);
		contentPane.add(labelFirstMoney);
		
		txtFirstMoney = new JTextField();
		txtFirstMoney.setBounds(188, 74, 116, 24);
		contentPane.add(txtFirstMoney);
		txtFirstMoney.setColumns(10);
		
		comboBox = new JComboBox();
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"\uC790\uC720\uC785\uCD9C\uAE08", "\uB9C8\uC774\uB108\uC2A4"}));
		comboBox.setBounds(187, 126, 117, 24);
		contentPane.add(comboBox);
		
		JLabel labelAccount = new JLabel("\uACC4\uC88C \uC885\uB958");
		labelAccount.setBounds(58, 129, 62, 18);
		contentPane.add(labelAccount);
		
		labelCreditLimit = new JLabel("\uC774\uCCB4 \uD55C\uB3C4");
		labelCreditLimit.setBounds(58, 173, 62, 18);
		contentPane.add(labelCreditLimit);
		
		txtCreditLimit = new JTextField();
		txtCreditLimit.setBounds(187, 170, 116, 24);
		contentPane.add(txtCreditLimit);
		txtCreditLimit.setColumns(10);
	
		setVisible(true);
	}
}
