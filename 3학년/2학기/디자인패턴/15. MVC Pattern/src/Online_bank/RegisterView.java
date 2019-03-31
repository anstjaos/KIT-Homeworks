package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JPasswordField;

public class RegisterView extends JFrame {
	private ControllerInterface registerController;
	private User user;
	
	private JPanel contentPane;
	private JTextField txtId;
	private JTextField txtAddress;
	private JTextField txtPhoneNum;
	private JButton btnRegister;
	private JButton btnCancel;
	private JButton btnExistId;
	private JPasswordField txtPwd;
	public JPasswordField txtCheckPwd;
	/**
	 * Create the frame.
	 */
	public RegisterView(ControllerInterface rc, User u) {
		user = u;
		registerController = rc;
		setTitle("Register");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 515, 407);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelId = new JLabel("ID");
		labelId.setBounds(14, 43, 62, 18);
		contentPane.add(labelId);
		
		JLabel labelPwd = new JLabel("\uBE44\uBC00\uBC88\uD638");
		labelPwd.setBounds(14, 91, 73, 18);
		contentPane.add(labelPwd);
		
		JLabel labelAddress = new JLabel("\uC8FC\uC18C");
		labelAddress.setBounds(14, 199, 62, 18);
		contentPane.add(labelAddress);
		
		JLabel labelPhoneNum = new JLabel("\uD734\uB300\uC804\uD654 \uBC88\uD638");
		labelPhoneNum.setBounds(14, 252, 89, 18);
		contentPane.add(labelPhoneNum);
		
		txtId = new JTextField();
		txtId.setBounds(137, 40, 188, 24);
		contentPane.add(txtId);
		txtId.setColumns(10);
		
		txtAddress = new JTextField();
		txtAddress.setBounds(137, 196, 188, 24);
		contentPane.add(txtAddress);
		txtAddress.setColumns(10);
		
		txtPhoneNum = new JTextField();
		txtPhoneNum.setBounds(137, 249, 188, 24);
		contentPane.add(txtPhoneNum);
		txtPhoneNum.setColumns(10);
		
		btnExistId = new JButton("\uC911\uBCF5 \uAC80\uC0AC");
		btnExistId.setBounds(339, 39, 105, 27);
		contentPane.add(btnExistId);
		btnExistId.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				User u = new User(txtId.getText(), "");
				ControllerInterface ci = new CheckUserController(u);
				ci.execute();
			}
		});
		
		JLabel labelCheckPwd = new JLabel("\uBE44\uBC00\uBC88\uD638 \uD655\uC778");
		labelCheckPwd.setBounds(14, 143, 89, 18);
		contentPane.add(labelCheckPwd);
		
		btnRegister = new JButton("\uD68C\uC6D0 \uB4F1\uB85D");
		btnRegister.setBounds(250, 321, 105, 27);
		contentPane.add(btnRegister);
		btnRegister.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				user.setId(txtId.getText());
				user.setPassword(String.valueOf(txtPwd.getPassword()));
				user.setAddress(txtAddress.getText());
				user.setPhoneNum(txtPhoneNum.getText());
				user.setType(0);
				
				registerController.execute();
			}
		});
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(378, 321, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				ControllerInterface ci= new LoginController();
			}
		});
		
		txtPwd = new JPasswordField();
		txtPwd.setBounds(137, 88, 188, 24);
		contentPane.add(txtPwd);
		
		txtCheckPwd = new JPasswordField();
		txtCheckPwd.setBounds(137, 140, 188, 24);
		contentPane.add(txtCheckPwd);
		
		setVisible(true);
	}

}
