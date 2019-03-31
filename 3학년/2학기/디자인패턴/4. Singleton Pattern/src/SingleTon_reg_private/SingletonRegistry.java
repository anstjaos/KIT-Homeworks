package SingleTon_reg_private;

import java.util.HashMap;

public class SingletonRegistry {
	public static SingletonRegistry registry = new SingletonRegistry();
	private static HashMap<String, SingleTon> map = new HashMap<String, SingleTon>();
	
	private SingletonRegistry() {}
	
	public static synchronized Object getInstance(String className) {
		Object singleTon = map.get(className);
		if(singleTon != null) { return singleTon; }
		
		try {
			singleTon = Class.forName(className).newInstance();
			System.out.println("singleTon °´Ã¼ »ý¼º  : " + singleTon);
		} catch(ClassNotFoundException cnf) {
			System.out.println("Class Not Found!");
		} catch(InstantiationException ie ) {
			System.out.println("Instantiation Failed!");
		} catch(IllegalAccessException ia) {
			System.out.println("Access Failed!");
		}
		
		map.put(className, (SingleTon)singleTon);
		return singleTon;
	}
	
}
