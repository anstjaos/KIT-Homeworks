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

public class DeleteAccountView extends JFrame {
	private ControllerInterface deleteAccountController; 
	private JPanel contentPane;
	public JTextField txtAccountNum;
	private JButton btnDelete;
	private JButton btnCancel;
	/**
	 * Create the frame.
	 */
	public DeleteAccountView(ControllerInterface ci) {
		deleteAccountController = ci;
		
		setTitle("\uACC4\uC88C \uD574\uC9C0");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelAccountNum = new JLabel("\uACC4\uC88C\uBC88\uD638\uB97C \uC785\uB825\uD558\uC138\uC694");
		labelAccountNum.setBounds(15, 91, 160, 18);
		contentPane.add(labelAccountNum);
		
		btnDelete = new JButton("\uC0AD\uC81C");
		btnDelete.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				deleteAccountController.execute();
			}
		});
		btnDelete.setBounds(66, 214, 105, 27);
		contentPane.add(btnDelete);
		
		btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(268, 214, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				deleteAccountController = new ManagerController();
			}
		});
		
		txtAccountNum = new JTextField();
		txtAccountNum.setBounds(189, 88, 229, 24);
		contentPane.add(txtAccountNum);
		txtAccountNum.setColumns(10);
		
		setVisible(true);
	}

}
