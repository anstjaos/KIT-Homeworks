package pattern_2;

public class Waitress {
	public MenuComponent allMenus;
	
	public Waitress(MenuComponent allMenus) { this.allMenus = allMenus; }
	
	public void printMenu() {
		allMenus.print();
	}
}
