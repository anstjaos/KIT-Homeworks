package SingleTon_reg_private;

public class SingleTon {
	protected SingleTon() {}
	
	public static SingleTon getInstance() {
		return (SingleTon)SingletonRegistry.registry.getInstance(SingleTon.class.getName());
	}
	
	public String getDescription() {
		return "I'm SingleTon!";
	}
}
