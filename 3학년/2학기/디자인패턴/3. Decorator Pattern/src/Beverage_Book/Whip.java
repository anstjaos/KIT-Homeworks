package Beverage_Book;

public class Whip extends CondimentDecorator {
	Beverage beverage;
	
	public Whip(Beverage b) {
		beverage = b;
	}
	
	public String getDescription() {
		return beverage.getDescription() + ", ¸ğÄ«";
	}
	
	public double cost() {
		return beverage.cost() + .20;
	}
}
