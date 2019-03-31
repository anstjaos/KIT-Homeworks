package FighterAircraft;

public class FighterMain {

	public static void main(String[] args) {
		FighterAircraft f = new Fighter();
		f.attack();
		System.out.println();
		
		f = new RearAttackDecorator(f);
		f.attack();
		System.out.println();
		
		f = new LeftAttackDecorator(f);
		f.attack();
		System.out.println();
		
		f = new RightAttackDecorator(f);
		f.attack();
		System.out.println();
	}

}
