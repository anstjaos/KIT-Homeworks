package SingleFactory;

public class PizzaStore {
	private SimplePizzaFactory spf;
	
	public PizzaStore(SimplePizzaFactory s) { this.spf = s; }
	
	public Pizza orderPizza(String pizzaType) {
		Pizza pz = spf.createPizza(pizzaType);
		if(pz == null) return null; 

		pz.prepare();
		pz.bake();
		pz.cut();
		pz.box();
		
		return pz;
	}
}
