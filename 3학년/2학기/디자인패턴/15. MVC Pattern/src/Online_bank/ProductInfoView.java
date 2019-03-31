package Online_bank;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JList;

public class ProductInfoView extends JFrame {
	private ControllerInterface productInfoController;
	private Account account;
	
	private JPanel contentPane;
	private JButton btnShowProduct;
	public JList listProduct;
	public ArrayList<ProductInformation> pil;
	/**
	 * Create the frame.
	 */
	public ProductInfoView(ControllerInterface ci, Account a) {
		productInfoController = ci;
		account = a;
		
		setTitle("\uC0C8 \uC0C1\uD488 \uC870\uD68C");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		btnShowProduct = new JButton("\uC0C8 \uC0C1\uD488 \uC870\uD68C");
		btnShowProduct.setBounds(74, 214, 124, 27);
		contentPane.add(btnShowProduct);
		btnShowProduct.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				productInfoController.execute();
			}
		});
		
		pil = new ProductInformation().selectProductInforamtions();
		Vector<String> list = new Vector<String>();
		for(int i = 0 ; i < pil.size(); i++) {
			ProductInformation p = pil.get(i);
			list.add(p.getTitle());
		}
		listProduct = new JList(list);
		listProduct.setBounds(33, 12, 364, 191);
		contentPane.add(listProduct);
		
		JButton btnCancel = new JButton("\uCDE8\uC18C");
		btnCancel.setBounds(246, 214, 105, 27);
		contentPane.add(btnCancel);
		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				setVisible(false);
				productInfoController = new UserMainController(account);
			}
		});
		
		setVisible(true);
	}
}
