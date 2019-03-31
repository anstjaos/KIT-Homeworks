package PizzaFactory;

public class ChicagoPizzaStore extends PizzaStore {
	protected Pizza createPizza(String item) {
		Pizza pizza = null;
		PizzaIngredientFactory ingf = new ChicagoIngredientFactory();
		
		if(item.equals("cheese")) {
			pizza = new CheesePizza(ingf);
			pizza.setName("Chicago Style Cheese Pizza");
		}
		else if(item.equals("veggie")) {
			pizza = new VeggiePizza(ingf);
			pizza.setName("Chicago Style Veggie Pizza");
		}
		else if(item.equals("pepperoni")) {
			pizza = new PepperoniPizza(ingf);
			pizza.setName("Chicago Style Pepperoni Pizza");
		}
		
		return pizza;
	}
	
}
