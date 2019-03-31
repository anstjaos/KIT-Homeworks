package Beverage_Window;

public class Mocha extends CondimentDecorator {
	public Mocha(Beverage b) {
		super(b);
	}
	
	public String getDescription() {
		return super.getDescription() + ", Mocha";
	}
	
	public double cost() {
		return super.cost() + 0.20;
	}
}
