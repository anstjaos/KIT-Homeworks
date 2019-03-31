package FighterAircraft;

public abstract class FighterDecorator extends FighterAircraft {
	protected FighterAircraft fighter;
	
	public FighterDecorator(FighterAircraft f) { fighter = f; }
	public void attack() { fighter.attack(); }
}
