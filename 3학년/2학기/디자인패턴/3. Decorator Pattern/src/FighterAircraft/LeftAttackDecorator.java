package FighterAircraft;

public class LeftAttackDecorator extends FighterDecorator{
	public LeftAttackDecorator(FighterAircraft f) { super(f); }
	public void attack() {
		super.attack();
		System.out.print(", ÁÂÃø °ø°İ");
	}
}
