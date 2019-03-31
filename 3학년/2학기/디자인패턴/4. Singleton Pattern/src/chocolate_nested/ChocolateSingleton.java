package chocolate_nested;

public class ChocolateSingleton {
	private static class ChocolateBoiler {
		private static ChocolateSingleton uniqueInstance = new ChocolateSingleton();
		
	}
	private boolean empty;
	private boolean boiled;

	private ChocolateSingleton() {
		empty = true;
		boiled = false;
	}
	
	public boolean isEmpty() { return empty; }
	
	public boolean isBoiled() { return boiled; }
	
	public void fill() {
		if(isEmpty()) {
			empty = false;
			boiled = false;
			System.out.println("채우기 완료!");
			return;
		}
		System.out.println("이미 채워져 있습니다.");
	}
	
	public void drain() {
		if(!isEmpty() && isBoiled()) {
			empty = true;
			System.out.println("마시기 완료!");
			return;
		}
		System.out.println("마실 수 없습니다");
	}
	
	public void boil() {
		if(!isEmpty() && !isBoiled()) {
			boiled = true;
			System.out.println("끓이기 완료!");
			return;
		}
		
		System.out.println("끓이기 실패");
	}
	public static ChocolateSingleton getInstance() {
		return ChocolateBoiler.uniqueInstance;
	}
	
}
