package SingleTon_reg_private;

public class SingleTonSon extends SingleTon{
	public SingleTonSon() {}
	
	public static SingleTon getInstance() {
		return (SingleTon)SingletonRegistry.registry.getInstance(SingleTonSon.class.getName());
	}
	
	public String getDescription() {
		return "I'm SingleTon Son!";
	}
}