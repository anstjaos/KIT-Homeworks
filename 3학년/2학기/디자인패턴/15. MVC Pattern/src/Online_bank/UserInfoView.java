package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JPasswordField;

public class UserInfoView extends JFrame {
	private ControllerInterface userInfoController;
	private User user;
	
	private JPanel contentPane;
	public JTextField txtAddress;
	public JTextField txtPhoneNum;
	private JButton btnUpdate;
	private JButton btnCancel;
	public JPasswordField txtPwd;

	/**
	 * Create the frame.
	 */
	public UserInfoView(ControllerInterface ci, User u) {
		userInfoController = ci;
		user = u;
		
		setTitle("\uD68C\uC6D0 \uC815\uBCF4 \uAD00\uB9AC");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 478, 451);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelID = new JLabel("ID");
		labelID.setBounds(14, 38, 62, 18);
		contentPane.add(labelID);
		
		JLabel labelPwd = new JLabel("\uBE44\uBC00\uBC88\uD638");
		labelPwd.setBounds(14, 122, 62, 18);
		contentPane.add(labelPwd);
		
		JLabel labelAddress = new JLabel("\uC8FC\uC18C");
		labelAddress.setBounds(14, 206, 62, 18);
		contentPane.add(labelAddress);
		
		JLabel labelPhoneNum = new JLabel("\uD734\uB300\uC804\uD654 \uBC88\uD638");
		labelPhoneNum.setBounds(14, 290, 89, 18);
		contentPane.add(labelPhoneNum);
		
		JLabel labelUserID = new JLabel(user.getUserId());
		labelUserID.setBounds(129, 38, 62, 18);
		contentPane.add(labelUserID);
		
		txtAddress = new JTextField();
		txtAddress.setBounds(129, 203, 166, 24);
		txtAddress.setText(user.getAddress());
		contentPane.add(txtAddress);
		txtAddress.setColumns(10);
		
		txtPhoneNum = new JTextField();
		txtPhoneNum.setBounds(129, 287, 166, 24);
		txtPhoneNum.setText(user.getPhoneNum());
		contentPane.add(txtPhoneNum);
		txtPhoneNum.setColumns(10);
		
		txtPwd = new JPasswordField();
		txtPwd.setBounds(129, 119, 166, 24);
		txtPwd.setText(user.getPassword());
		contentPane.add(txtPwd);
		
		btnUpdate = new JButton("\uD68C\uC6D0\uC815\uBCF4 \uC218\uC815");
		btnUpdate.setBounds(194, 365, 130, 27);
		contentPane.add(btnUpdate);
		btnUpdate.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				ci.execute();
			}
		});
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(338, 365, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				ControllerInterface ci = new UserInitController(user);
			}
		});
		
	
		setVisible(true);
	}
}
