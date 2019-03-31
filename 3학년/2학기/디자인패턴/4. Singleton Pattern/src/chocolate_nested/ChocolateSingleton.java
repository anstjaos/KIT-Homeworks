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
			System.out.println("ä��� �Ϸ�!");
			return;
		}
		System.out.println("�̹� ä���� �ֽ��ϴ�.");
	}
	
	public void drain() {
		if(!isEmpty() && isBoiled()) {
			empty = true;
			System.out.println("���ñ� �Ϸ�!");
			return;
		}
		System.out.println("���� �� �����ϴ�");
	}
	
	public void boil() {
		if(!isEmpty() && !isBoiled()) {
			boiled = true;
			System.out.println("���̱� �Ϸ�!");
			return;
		}
		
		System.out.println("���̱� ����");
	}
	public static ChocolateSingleton getInstance() {
		return ChocolateBoiler.uniqueInstance;
	}
	
}
