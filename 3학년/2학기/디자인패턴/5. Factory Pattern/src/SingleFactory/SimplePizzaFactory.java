package SingleFactory;

public class SimplePizzaFactory {
	public Pizza createPizza(String pizzaType) {
		Pizza pz = null;
		
		if(pizzaType.equals("치즈피자")) pz = new CheesePizza();
		else if(pizzaType.equals("야채피자")) pz = new VeggiePizza();
		else if(pizzaType.equals("대합피자")) pz = new ClamPizza();
		else if(pizzaType.equals("페페로니피자")) pz = new PepperoniPizza();
		
		return pz;
	}
}
