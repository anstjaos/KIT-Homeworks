package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;

public class ManagerView extends JFrame {
	private ControllerInterface managerController;
	private JPanel contentPane;
	private JButton btnRegAccount;
	private JButton btnDelAccount;
	private JButton btnRegProduct;
	/**
	 * Create the frame.
	 */
	public ManagerView() {
		setTitle("\uAD00\uB9AC\uC790 \uBA54\uB274");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		btnRegAccount = new JButton("\uACC4\uC88C \uB4F1\uB85D");
		btnRegAccount.setBounds(14, 108, 105, 27);
		contentPane.add(btnRegAccount);
		btnRegAccount.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				managerController = new RegisterAccountController();
			}
		});
		
		btnDelAccount = new JButton("\uACC4\uC88C \uD574\uC9C0");
		btnDelAccount.setBounds(156, 108, 105, 27);
		contentPane.add(btnDelAccount);
		btnDelAccount.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				managerController = new DeleteAccountController();
			}
		});
		
		btnRegProduct = new JButton("\uC0C8 \uC0C1\uD488 \uB4F1\uB85D");
		btnRegProduct.setBounds(292, 108, 113, 27);
		contentPane.add(btnRegProduct);
		btnRegProduct.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				managerController = new RegisterProductController();
			}
		});
		
		setVisible(true);
	}

}
