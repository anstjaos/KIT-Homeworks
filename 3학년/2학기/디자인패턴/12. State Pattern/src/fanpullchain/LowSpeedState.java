package fanpullchain;

public class LowSpeedState implements SpeedState {
	private CeilingFanPullChain chain;
	
	public LowSpeedState(CeilingFanPullChain chain) { this.chain = chain; }
	
	public void runLowSpeed() {
		System.out.println("Low Speed");
		chain.setState(chain.getMediumSpeedState());
	}

	public void runMediumSpeed() {
		System.out.println("Can't run!");
	}
	
	public void runHighSpeed() {
		System.out.println("Can't run!");
	}

	public void turnOff() {
		System.out.println("Can't run!");
	}
}