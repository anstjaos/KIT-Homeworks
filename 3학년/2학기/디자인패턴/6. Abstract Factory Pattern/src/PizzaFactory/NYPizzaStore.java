package PizzaFactory;

public class NYPizzaStore extends PizzaStore {
	protected Pizza createPizza(String item) {
		Pizza pizza = null;
		PizzaIngredientFactory ingf = new NYPizzaIngredientFactory();
		
		if(item.equals("cheese")) {
			pizza = new CheesePizza(ingf);
			pizza.setName("New York Style Cheese Pizza");
		}
		else if(item.equals("veggie")) {
			pizza = new VeggiePizza(ingf);
			pizza.setName("New York Style Veggie Pizza");
		}
		else if(item.equals("pepperoni")) {
			pizza = new PepperoniPizza(ingf);
			pizza.setName("New York Style Pepperoni Pizza");
		}
		
		return pizza;
	}
}
