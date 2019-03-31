package SingleFactory;

public class SimplePizzaFactory {
	public Pizza createPizza(String pizzaType) {
		Pizza pz = null;
		
		if(pizzaType.equals("ġ������")) pz = new CheesePizza();
		else if(pizzaType.equals("��ä����")) pz = new VeggiePizza();
		else if(pizzaType.equals("��������")) pz = new ClamPizza();
		else if(pizzaType.equals("����δ�����")) pz = new PepperoniPizza();
		
		return pz;
	}
}
