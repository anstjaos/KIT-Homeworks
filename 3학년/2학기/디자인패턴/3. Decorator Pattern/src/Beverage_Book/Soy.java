package Beverage_Book;

public class Soy extends CondimentDecorator{
	Beverage beverage;
	
	public Soy(Beverage b) {
		beverage = b;
	}
	
	public String getDescription() {
		return beverage.getDescription() + ", ¸ğÄ«";
	}
	
	public double cost() {
		return beverage.cost() + 1.20;
	}
}
