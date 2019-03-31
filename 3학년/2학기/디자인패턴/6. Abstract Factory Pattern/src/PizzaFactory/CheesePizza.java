package PizzaFactory;

public class CheesePizza extends Pizza {
	private PizzaIngredientFactory ingredientFactory;
	
	public CheesePizza(PizzaIngredientFactory ingf) {
		ingredientFactory = ingf;
	}
	
	public void prepare() {
		System.out.println("Preparing " + name);
		
		dough = ingredientFactory.createDough();
		sauce = ingredientFactory.createSauce();
		cheese = ingredientFactory.createCheese();
	}
}
