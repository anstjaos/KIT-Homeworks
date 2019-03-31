package PizzaFactory;

public class ChicagoPizzaStore extends PizzaStore {
	public Pizza createPizza(String pizzaType) {
		if(pizzaType.equals("ġ������")) return new ChicagoCheesePizza();
		else if(pizzaType.equals("��������")) return new ChicagoClamPizza();
		else if(pizzaType.equals("���۷δ�����")) return new ChicagoPepperoniPizza();
		else if(pizzaType.equals("��ä����")) return new ChicagoVeggiePizza();
		
		return null;
	}
}
