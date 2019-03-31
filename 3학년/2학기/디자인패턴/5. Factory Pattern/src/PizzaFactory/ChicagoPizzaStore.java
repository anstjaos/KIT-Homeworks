package PizzaFactory;

public class ChicagoPizzaStore extends PizzaStore {
	public Pizza createPizza(String pizzaType) {
		if(pizzaType.equals("치즈피자")) return new ChicagoCheesePizza();
		else if(pizzaType.equals("대합피자")) return new ChicagoClamPizza();
		else if(pizzaType.equals("페퍼로니피자")) return new ChicagoPepperoniPizza();
		else if(pizzaType.equals("야채피자")) return new ChicagoVeggiePizza();
		
		return null;
	}
}
