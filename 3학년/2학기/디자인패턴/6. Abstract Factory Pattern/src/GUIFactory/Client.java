package GUIFactory;

public class Client {
	public static void main(String[] args) {
		GUIFactory myfact = new WinFactory();
		Button btn = myfact.createButton();
		btn.paint();
		
		myfact = new OSXFactory();
		btn = myfact.createButton();
		btn.paint();
	}
}
