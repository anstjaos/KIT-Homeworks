package Beverage_Window;

public class BerverageMain {

	public static void main(String[] args) {
		Beverage beverage = new Espresso();
		System.out.println(beverage.getDescription() + " s" + beverage.cost());
		
		beverage = new Mocha(beverage);
		beverage = new Whip(beverage);
		beverage = new Milk(beverage);
		
		System.out.println(beverage.getDescription() + " s" + beverage.cost());
	}

}
