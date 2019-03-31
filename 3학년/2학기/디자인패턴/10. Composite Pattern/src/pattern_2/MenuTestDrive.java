package pattern_2;

public class MenuTestDrive {
	public static void main(String args[]) {
		MenuComponent pancakeHouse = new Menu("PANCAKE HOUSE MENU", "Breakfast");
		MenuComponent dinerMenu = new Menu("DINER MENU", "Lunch");
		MenuComponent cafeMenu = new Menu("CAFE MENU", "Dinner");
		MenuComponent kitMenu = new MenuItem("KIT MENU", "Lunch", 3.99);
		
		MenuComponent allMenus = new Menu("ALL MENUS", "All menus combined");
		allMenus.add(pancakeHouse); allMenus.add(dinerMenu); allMenus.add(cafeMenu);
		pancakeHouse.add(new MenuItem("Pancake", "Eggs and toast", 2.99));
		allMenus.add(kitMenu);
		
		Waitress waitress = new Waitress(allMenus);
		waitress.printMenu();
	}
}
