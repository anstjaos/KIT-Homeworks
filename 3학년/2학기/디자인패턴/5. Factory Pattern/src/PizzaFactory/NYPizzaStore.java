package PizzaFactory;

public class NYPizzaStore extends PizzaStore {
	public Pizza createPizza(String pizzaType) {
		if(pizzaType.equals("치즈피자")) return new NYCheesePizza();
		else if(pizzaType.equals("대합피자")) return new NYClamPizza();
		else if(pizzaType.equals("페퍼로니피자")) return new NYPepperoniPizza();
		else if(pizzaType.equals("야채피자")) return new NYVeggiePizza();
		
		return null;
	}
}