package chocolate_static;

public class ChocolateBoiler {
	private boolean empty;
	private boolean boiled;
	private static ChocolateBoiler uniqueInstance;
	
	static {
		uniqueInstance = new ChocolateBoiler();
	}
	private ChocolateBoiler() {
		empty = true;
		boiled = false;
	}
	
	public static ChocolateBoiler getInstance() {
		return uniqueInstance;
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
}
