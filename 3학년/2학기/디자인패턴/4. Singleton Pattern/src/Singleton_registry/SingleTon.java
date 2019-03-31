package Singleton_registry;

public class SingleTon {
	public SingleTon() {}
	
	public static SingleTon getInstance() {
		return (SingleTon)SingletonRegistry.registry.getInstance(SingleTon.class.getName());
	}
	
	public String getDescription() {
		return "I'm SingleTon!";
	}
}
