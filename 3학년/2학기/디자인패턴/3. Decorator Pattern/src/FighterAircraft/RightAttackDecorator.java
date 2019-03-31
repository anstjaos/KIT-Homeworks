package FighterAircraft;

public class RightAttackDecorator extends FighterDecorator{
	public RightAttackDecorator(FighterAircraft f) { super(f); }
	public void attack() {
		super.attack();
		System.out.print(", ���� ����");
	}
}
