package SingleTon_reg_private;

public class SingleTonTest {
	public static void main(String args[]) {
		SingleTon st = SingleTon.getInstance();
		System.out.println("Class : " + st + " " + st.getDescription());
		
		SingleTon sts = SingleTonSon.getInstance();
		System.out.println("Class : " + sts + " " + sts.getDescription());
		
		SingleTon std = SingleTonDaughter.getInstance();
		System.out.println("Class : " + std + " " + std.getDescription());
		
		SingleTon st1 = SingleTon.getInstance();
		System.out.println("Class : " + st1 + " " + st1.getDescription());
		
		SingleTon sts1 = SingleTonSon.getInstance();
		System.out.println("Class : " + sts1 + " " + sts1.getDescription());
	}
}
