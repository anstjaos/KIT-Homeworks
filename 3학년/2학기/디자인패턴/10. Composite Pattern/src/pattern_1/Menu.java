package pattern_1;

import java.util.ArrayList;
import java.util.Iterator;

public class Menu implements MenuComponent {
	private ArrayList<MenuComponent> menuComponents = new ArrayList<MenuComponent>();
	private String name;
	private String description;
	
	public Menu(String i_name, String i_description) {
		name = i_name;
		description = i_description;
	}
	
	public void add(MenuComponent m) {
		menuComponents.add(m);
	}
	
	public void remove(MenuComponent m) {
		menuComponents.remove(m);
	}
	
	public MenuComponent getChild(int i) {
		return menuComponents.get(i);
	}
	
	public String getName() {
		return name;
	}
	

	public String getDescription() {
		return description;
	}
	
	public void print() {
		System.out.println(getName() + ": " + getDescription());
		
		Iterator<MenuComponent> iterator = menuComponents.iterator();
		while(iterator.hasNext()) {
			MenuComponent m = iterator.next();
			m.print();
		}
	}
}
