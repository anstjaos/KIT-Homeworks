package SingleFactory;

public class PizzaClient {
	public static void main(String[] args) {
		SimplePizzaFactory spf = new SimplePizzaFactory();
		PizzaStore ps = new PizzaStore(spf);
		
		Pizza pz = ps.orderPizza("치즈피자");
		pz = ps.orderPizza("대합피자");
		pz = ps.orderPizza("야채피자");
		pz = ps.orderPizza("페페로니피자");
		
		pz = ps.orderPizza("불고기 피자");
		if(pz == null) System.out.println("해당 피자는 존재하지 않습니다!");
	}
}
