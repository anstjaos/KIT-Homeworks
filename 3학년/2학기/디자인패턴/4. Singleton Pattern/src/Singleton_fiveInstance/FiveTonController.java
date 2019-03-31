package Singleton_fiveInstance;

public class FiveTonController {
	public static void main(String[] args) {
		for(int i = 0 ; i < 11; i++)
		{
			FiveTon ft = FiveTon.getInstance();
			System.out.println(i+1 + " Fiveton : " + ft+ " Size is " + ft.getSize());
		}
	}
}
