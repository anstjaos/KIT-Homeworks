package PizzaFactory;

public class NYPizzaStore extends PizzaStore {
	public Pizza createPizza(String pizzaType) {
		if(pizzaType.equals("ġ������")) return new NYCheesePizza();
		else if(pizzaType.equals("��������")) return new NYClamPizza();
		else if(pizzaType.equals("���۷δ�����")) return new NYPepperoniPizza();
		else if(pizzaType.equals("��ä����")) return new NYVeggiePizza();
		
		return null;
	}
}