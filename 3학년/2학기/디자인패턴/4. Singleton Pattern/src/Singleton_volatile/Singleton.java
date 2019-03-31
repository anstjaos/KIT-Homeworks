package Singleton_volatile;

public class Singleton {
	private volatile static Singleton uniqueInstance;
	
	private Singleton() {}
	
	public static Singleton getInstance() {
		if(uniqueInstance != null) {
			System.out.println("기존의 Singleton 객체 return");
			return uniqueInstance;
		}
		
		synchronized (Singleton.class) {
			if(uniqueInstance == null) {
				System.out.println("Singleton 객체 최초 생성!");
				uniqueInstance = new Singleton();
			}
		}
		
		return uniqueInstance;
	}
	
}
