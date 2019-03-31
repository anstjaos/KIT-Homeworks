package Beverage_Window;

public class Whip extends CondimentDecorator{
	public Whip(Beverage b) {
		super(b);
	}
	
	public String getDescription() {
		return super.getDescription() + ", Whip";
	}
	
	public double cost() {
		return super.cost() + 0.30;
	}
}
