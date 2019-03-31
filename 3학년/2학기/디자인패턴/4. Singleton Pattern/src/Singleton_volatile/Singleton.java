package Singleton_volatile;

public class Singleton {
	private volatile static Singleton uniqueInstance;
	
	private Singleton() {}
	
	public static Singleton getInstance() {
		if(uniqueInstance != null) {
			System.out.println("������ Singleton ��ü return");
			return uniqueInstance;
		}
		
		synchronized (Singleton.class) {
			if(uniqueInstance == null) {
				System.out.println("Singleton ��ü ���� ����!");
				uniqueInstance = new Singleton();
			}
		}
		
		return uniqueInstance;
	}
	
}
