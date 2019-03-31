package pattern_1;

public class MenuTestDrive {
	public static void main(String[] args) {
		MenuComponent pancakeHouse = new Menu("PANCAKE HOUSE MENU", "Breakfast");
		MenuComponent dinerMenu = new Menu("DINER MENU", "Lunch");
		MenuComponent cafeMenu = new Menu("CAFE MENU", "Dinner");
		MenuComponent kitMenu = new MenuItem("KIT MENU", "Lunch", 3.99);
		
		Menu allMenus = new Menu("ALL MENUS", "All menus combined");
		allMenus.add(pancakeHouse); allMenus.add(dinerMenu); allMenus.add(cafeMenu);
		
		Waitress waitress = new Waitress();
		waitress.printMenu(kitMenu);
		waitress.printMenu((MenuComponent)allMenus);
	}
}
