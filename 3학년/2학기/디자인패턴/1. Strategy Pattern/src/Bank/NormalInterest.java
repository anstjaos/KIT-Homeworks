
public class NormalInterest implements InterestCalculator {
	public int calculateInterest(int balance) {
		System.out.println("NormalInterest ȣ��!");
		return (int)(balance * 0.03);
	}
}
