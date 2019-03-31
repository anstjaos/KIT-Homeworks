package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JTextPane;
import javax.swing.SwingConstants;
import javax.swing.JButton;

public class ProductInfoDetailView extends JFrame {
	private ProductInformation pi;
	
	private JPanel contentPane;

	/**
	 * Create the frame.
	 */
	public ProductInfoDetailView(ProductInformation p) {
		setTitle("\uC0C1\uD488 \uC0C1\uC138 \uC870\uD68C");
		pi = p;
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 498, 408);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel labelTitle = new JLabel("\uC81C\uBAA9");
		labelTitle.setBounds(27, 39, 62, 18);
		contentPane.add(labelTitle);
		
		JTextPane txtTitle = new JTextPane();
		txtTitle.setBounds(95, 39, 344, 18);
		contentPane.add(txtTitle);
		txtTitle.setText(pi.getTitle());
		
		JLabel labelDate = new JLabel("\uB4F1\uB85D \uB0A0\uC9DC");
		labelDate.setBounds(27, 93, 62, 18);
		contentPane.add(labelDate);
		
		JTextPane txtDate = new JTextPane();
		txtDate.setBounds(95, 87, 344, 24);
		contentPane.add(txtDate);
		txtDate.setText(pi.getDate());
		
		JLabel labelDes = new JLabel("\uB0B4\uC6A9");
		labelDes.setBounds(27, 137, 62, 18);
		contentPane.add(labelDes);
		
		JTextPane txtDes = new JTextPane();
		txtDes.setBounds(95, 137, 344, 157);
		contentPane.add(txtDes);
		txtDes.setText(pi.getDescription());
		
		JButton btnCheck = new JButton("\uD655\uC778");
		btnCheck.setBounds(334, 322, 105, 27);
		contentPane.add(btnCheck);
		btnCheck.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
			}
		});
		
		setVisible(true);
	}
}
