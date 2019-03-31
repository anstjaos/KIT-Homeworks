package Online_bank;

import javax.swing.JOptionPane;

public class RegisterProductController implements ControllerInterface {
	private RegisterProductView registerProductView;

	public RegisterProductController() {
		registerProductView = new RegisterProductView(this);
	}
	
	public void execute() {
		String title = registerProductView.txtProductName.getText();
		String description = registerProductView.txtProductDescription.getText();
		if(title.equals("") || description.equals("")) {
			JOptionPane.showMessageDialog(null, "�̱��� ������ �ֽ��ϴ�!");
			return;
		}
		
		ProductInformation p = new ProductInformation(title, description);
		p.registerProductInformation();
		JOptionPane.showMessageDialog(null, "��� �Ϸ�!");
		registerProductView.setVisible(false);
		new ManagerController();
	}
}
