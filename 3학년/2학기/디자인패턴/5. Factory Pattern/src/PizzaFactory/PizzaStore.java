package PizzaFactory;

public abstract class PizzaStore {
	abstract public Pizza createPizza(String pizzaType);
	
	public Pizza order(String pizzaType) {
		Pizza pz = createPizza(pizzaType);
		if(pz == null) return null;
		
		pz.prepare();
		pz.bake();
		pz.cut();
		pz.box();
		
		return pz;
	}
}
