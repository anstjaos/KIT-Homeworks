
public class MinusInterest implements InterestCalculator{
	public int calculateInterest(int balance) {
		System.out.println("MinusInterest È£Ãâ!");
		if(balance >= 0) return 0;
		
		return (int)(balance * 0.07);
	}
}
