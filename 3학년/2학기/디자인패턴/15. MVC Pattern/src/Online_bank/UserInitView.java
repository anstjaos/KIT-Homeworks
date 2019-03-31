package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.ListModel;
import javax.swing.border.EmptyBorder;
import javax.swing.JList;
import javax.swing.DefaultListModel;
import javax.swing.JButton;

public class UserInitView extends JFrame {
	private ControllerInterface userInitController;
	private User user;
	
	private JPanel contentPane;
	public JList listAccount;
	private JButton btnUserInfo;
	private JButton btnOK;
	private JButton btnCancel;
	public ArrayList<Account> al;
	/**
	 * Create the frame.
	 */
	public UserInitView(ControllerInterface ui, User u) {
		userInitController = ui;
		user = u;
		
		setTitle("\uACC4\uC88C\uB97C \uC120\uD0DD\uD558\uC138\uC694");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 495, 396);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		al = new FreeAccount("",0).selectAccounts(user.getUserId());
		Vector<String> list = new Vector<String>();
		for(int i = 0 ; i < al.size(); i++) {
			Account a = al.get(i);
			list.add(a.getAccountNum());
		}
		listAccount = new JList(list);
		listAccount.setBounds(14, 12, 237, 325);
		contentPane.add(listAccount);
		
		btnUserInfo = new JButton("\uD68C\uC6D0 \uC815\uBCF4 \uAD00\uB9AC");
		btnUserInfo.setBounds(288, 12, 175, 27);
		contentPane.add(btnUserInfo);
		btnUserInfo.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				ControllerInterface ci = new UserInfoController(user);
			}
		});
		
		btnOK = new JButton("\uD655\uC778");
		btnOK.setBounds(265, 310, 83, 27);
		contentPane.add(btnOK);
		btnOK.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				ui.execute();
			}
		});
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(380, 310, 83, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				ControllerInterface ci = new LoginController();
			}
		});
		
		setVisible(true);
	}
}
