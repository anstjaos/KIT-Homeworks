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
			JOptionPane.showMessageDialog(null, "미기입 정보가 있습니다!");
			return;
		}
		
		ProductInformation p = new ProductInformation(title, description);
		p.registerProductInformation();
		JOptionPane.showMessageDialog(null, "등록 완료!");
		registerProductView.setVisible(false);
		new ManagerController();
	}
}
