package pattern_1;

public class MenuItem implements MenuComponent {
	private String name;
	private String description;
	private double price;
	
	public MenuItem(String i_name, String i_description, double i_price) {
		name = i_name;
		description = i_description;
		price = i_price;
	}
		
	public String getName() {
		return name;
	}
	
	public String getDescription() {
		return description;
	}
	
	public double getPrice() {
		return price;
	}
	
	public void print() {
		System.out.println(getName() + ": " + getDescription() + ": " + getPrice());
	}
	
}
