package PizzaFactory;

public class VeggiePizza extends Pizza {
	private PizzaIngredientFactory ingredientFactory;
	public VeggiePizza(PizzaIngredientFactory ingf) {
		ingredientFactory = ingf;
	}
	
	public void prepare() {
		System.out.println("Preparing " + name);
		
		dough = ingredientFactory.createDough();
		sauce = ingredientFactory.createSauce();
		cheese = ingredientFactory.createCheese();
		veggies = ingredientFactory.createVeggies();
	}
}
