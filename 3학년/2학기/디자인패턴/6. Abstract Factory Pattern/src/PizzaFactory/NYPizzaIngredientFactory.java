package PizzaFactory;

public class NYPizzaIngredientFactory implements PizzaIngredientFactory {
	public Dough createDough() {
		return new ThinCrustDough();
	}
	
	public Sauce createSauce() {
		return new MarinaraSauce();
	}
	
	public Cheese createCheese() {
		return new ParmesanCheese();
	}
	
	public Veggies[] createVeggies() {
		Veggies[] vArr =  {new Onion(), new Garlic()};
		return vArr;
	}
	
	public Pepperoni createPepperoni() {
		return new SlicePepperoni();
	}
}
