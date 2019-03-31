
public class MiniDuckSimulator1 {
	public static void main(String[] args) {
		Duck mallard = new MallardDuck();
		mallard.fly();
		
		Duck rubber = new RubberDuck();
		rubber.fly();
		
		rubber.setFlyBehavior(new FlyRocketPowered());
		rubber.fly();
		
		mallard.quack();
		
		rubber.quack();
		
		rubber.setQuackBehavior(new QuackLouder());
		rubber.quack();
	}
}
