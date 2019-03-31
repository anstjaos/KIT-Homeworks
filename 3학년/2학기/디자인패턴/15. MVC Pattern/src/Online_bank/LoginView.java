package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JPasswordField;

public class LoginView extends JFrame {
	private ControllerInterface loginController;
	private JPanel contentPane;
	public JTextField txtID;
	private JButton btnLogin;
	private JButton btnCancel;
	private JButton btnRegister;
	public JPasswordField txtPwd;
	/**
	 * Create the frame.
	 */
	public LoginView(ControllerInterface lc) {
		this.loginController = lc;
		setTitle("Login");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 473, 310);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelID = new JLabel("ID");
		labelID.setFont(new Font("±¼¸²", Font.PLAIN, 17));
		labelID.setBounds(27, 64, 62, 18);
		contentPane.add(labelID);
		
		JLabel labelPwd = new JLabel("Password");
		labelPwd.setFont(new Font("±¼¸²", Font.PLAIN, 17));
		labelPwd.setBounds(27, 134, 77, 18);
		contentPane.add(labelPwd);
		
		txtID = new JTextField();
		txtID.setBounds(130, 62, 290, 24);
		contentPane.add(txtID);
		txtID.setColumns(10);
		
		btnLogin = new JButton("\uB85C\uADF8\uC778");
		btnLogin.setBounds(170, 224, 105, 27);
		contentPane.add(btnLogin);
		btnLogin.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				loginController.execute();
			}
		});
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(315, 224, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
		
		btnRegister = new JButton("\uD68C\uC6D0\uB4F1\uB85D");
		btnRegister.setBounds(27, 224, 105, 27);
		contentPane.add(btnRegister);
		btnRegister.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				User u = new User("", "");
				ControllerInterface controller = new RegisterUserController(u);
			}
		});
		
		txtPwd = new JPasswordField();
		txtPwd.setBounds(130, 132, 290, 24);
		contentPane.add(txtPwd);
		
		
		setVisible(true);
	}
}
