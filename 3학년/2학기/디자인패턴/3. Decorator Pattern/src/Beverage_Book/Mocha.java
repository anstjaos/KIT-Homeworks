package Beverage_Book;

public class Mocha extends CondimentDecorator {
	Beverage beverage;
	
	public Mocha(Beverage b) {
		beverage = b;
	}
	
	public String getDescription() {
		return beverage.getDescription() + ", ¸ğÄ«";
	}
	
	public double cost() {
		return beverage.cost() + .20;
	}
}
