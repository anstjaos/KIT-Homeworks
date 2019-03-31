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
}
