package pattern_2;

public class MenuItem extends MenuComponent {
	private String name;
	private String description;
	private double price;
	
	public MenuItem(String name, String description, double price) {
		this.name = name;
		this.description = description;
		this.price = price;
	}
	
	public String getName() { return name; }
	public String getDescription() { return description; }
	public void print() { System.out.println(getName() + ": " + getDescription() + ": " + getPrice());}
	
	public double getPrice() { return price; }
}
