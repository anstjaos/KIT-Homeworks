package PizzaFactory;

public class ChicagoIngredientFactory implements PizzaIngredientFactory {
	public Dough createDough() {
		return new ThickCrustDough();
	}
	
	public Sauce createSauce() {
		return new PlumTomatoSauce();
	}
	
	public Cheese createCheese() {
		return new MozzarellaCheese();
	}
	
	public Veggies[] createVeggies() {
		Veggies[] vArr = {new Mushroom(), new RedPepper()};
		return vArr;
	}
	
	public Pepperoni createPepperoni() {
		return new ThickPepperoni();
	}
}
