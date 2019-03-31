package chocolate_nested;

public class ChocolateController {
	public static void main(String[] args) {
		ChocolateSingleton boiler = ChocolateSingleton.getInstance();
		boiler.fill();
		boiler.boil();
		boiler.drain();
		
		ChocolateSingleton boiler2 = ChocolateSingleton.getInstance();
		boiler.fill();
		boiler2.boil();
		boiler2.drain();
	}
}
