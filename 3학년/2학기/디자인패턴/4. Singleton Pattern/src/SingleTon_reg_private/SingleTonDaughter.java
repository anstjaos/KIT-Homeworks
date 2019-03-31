package SingleTon_reg_private;

public class SingleTonDaughter extends SingleTon{
	public SingleTonDaughter() {}
	
	public static SingleTon getInstance() {
		return (SingleTon)SingletonRegistry.registry.getInstance(SingleTonDaughter.class.getName());
	}
	
	public String getDescription() {
		return "I'm SingleTon Daughter!";
	}
}
