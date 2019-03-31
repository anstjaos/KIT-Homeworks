package FighterAircraft;

public class RearAttackDecorator extends FighterDecorator {
	public RearAttackDecorator(FighterAircraft f) { super(f); }
	public void attack() {
		super.attack();
		System.out.print(", 후방 공격");
	}
}
