package Online_bank;

import javax.swing.JOptionPane;

public class ProductInfoController implements ControllerInterface{
	private ProductInfoView productInfoView;
	private Account account;
	
	public ProductInfoController(Account a) {
		account = a;
		productInfoView = new ProductInfoView(this, a);
	}
	
	public void execute() {
		int index = productInfoView.listProduct.getSelectedIndex();
		if(index < 0) {
			JOptionPane.showMessageDialog(null, "���¸� �������ֽʽÿ�.");
			return;
		}
		
		ProductInformation p = productInfoView.pil.get(index);
		new ProductInfoDetailView(p);
	}
}
