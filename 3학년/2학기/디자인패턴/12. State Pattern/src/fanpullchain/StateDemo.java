package fanpullchain;

public class StateDemo {
	public static void main(String[] args) {
		CeilingFanPullChain chain = new CeilingFanPullChain();
		
		chain.runLowSpeed();
		chain.runHighSpeed();
		chain.runMediumSpeed();
		chain.runHighSpeed();
		chain.turnOff();
	}
}
