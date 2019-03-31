package PizzaFactory;

public class PepperoniPizza extends Pizza {
	private PizzaIngredientFactory ingredientFactory;
	public PepperoniPizza(PizzaIngredientFactory ingf) {
		ingredientFactory = ingf;
	}
	
	public void prepare() {
		System.out.println("Preparing " + name);
		
		dough = ingredientFactory.createDough();
		sauce = ingredientFactory.createSauce();
		cheese = ingredientFactory.createCheese();
		veggies = ingredientFactory.createVeggies();
		pepperoni = ingredientFactory.createPepperoni();
	}
}
