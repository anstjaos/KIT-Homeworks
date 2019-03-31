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

public class RegisterProductView extends JFrame {
	private ControllerInterface registerProductController;
	private JPanel contentPane;
	public JTextField txtProductDescription;
	public JTextField txtProductName;
	private JButton btnRegister;
	private JButton btnCancel;
	/**
	 * Create the frame.
	 */
	public RegisterProductView(ControllerInterface ci) {
		registerProductController = ci;
		
		setTitle("\uC0C8 \uC0C1\uD488 \uB4F1\uB85D");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelProductName = new JLabel("\uC0C8 \uC0C1\uD488 \uC774\uB984");
		labelProductName.setBounds(58, 28, 116, 18);
		contentPane.add(labelProductName);
		
		btnRegister = new JButton("\uB4F1\uB85D");
		btnRegister.setBounds(187, 214, 105, 27);
		contentPane.add(btnRegister);
		btnRegister.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				registerProductController.execute();
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
				new ManagerController();
			}
		});
		
		txtProductName = new JTextField();
		txtProductName.setBounds(188, 25, 116, 24);
		contentPane.add(txtProductName);
		txtProductName.setColumns(10);
		
		JLabel labelProductDescription = new JLabel("\uC0C8 \uC0C1\uD488 \uB0B4\uC6A9");
		labelProductDescription.setBounds(58, 103, 93, 18);
		contentPane.add(labelProductDescription);
		
		txtProductDescription = new JTextField();
		txtProductDescription.setBounds(188, 74, 116, 77);
		contentPane.add(txtProductDescription);
		txtProductDescription.setColumns(10);
		
		setVisible(true);
	}

}
