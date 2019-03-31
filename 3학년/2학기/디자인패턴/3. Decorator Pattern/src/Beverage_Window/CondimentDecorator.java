package Beverage_Window;

public abstract class CondimentDecorator extends Beverage{
	protected Beverage beverage;
	
	public CondimentDecorator(Beverage b) {
		beverage = b;
	}
	
	public String getDescription() { return beverage.getDescription(); }
	
	public double cost() {
		return beverage.cost();
	}
}
