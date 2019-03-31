package PizzaFactory;

public class PizzaClient {

	public static void main(String[] args) {
		Pizza pizza; PizzaStore store;
		
		store = new NYPizzaStore();
		pizza = store.order("치즈피자");
		if(pizza == null) System.out.println("해당 피자는 존재하지 않습니다!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		pizza = store.order("대합피자");
		if(pizza == null) System.out.println("해당 피자는 존재하지 않습니다!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		store = new ChicagoPizzaStore();
		pizza = store.order("야채피자");
		if(pizza == null) System.out.println("해당 피자는 존재하지 않습니다!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		pizza = store.order("페퍼로니피자");
		if(pizza == null) System.out.println("해당 피자는 존재하지 않습니다!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		pizza = store.order("치즈크러스트피자");
		if(pizza == null) System.out.println("해당 피자는 존재하지 않습니다!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
	}

}
