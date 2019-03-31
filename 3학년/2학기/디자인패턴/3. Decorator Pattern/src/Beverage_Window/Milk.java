package Beverage_Window;

public class Milk extends CondimentDecorator{
	public Milk(Beverage b) {
		super(b);
	}
	
	public String getDescription() {
		return super.getDescription() + ", Milk";
	}
	
	public double cost() {
		return super.cost() + 0.10;
	}
}
