
public class MallardDuck extends Duck {
	public MallardDuck() {
		flyBehavior = new FlyWithWings();
		quackBehavior = new QuackLouder();
	}
	
	public void display() { System.out.println("I'm a real Mallard Duck!"); }
}
