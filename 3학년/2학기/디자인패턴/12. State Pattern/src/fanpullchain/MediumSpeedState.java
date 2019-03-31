package fanpullchain;

public class MediumSpeedState implements SpeedState {
	private CeilingFanPullChain chain;

	public MediumSpeedState(CeilingFanPullChain chain) { this.chain = chain; }
	
	public void runLowSpeed() {
		System.out.println("Can't run!");
	}

	public void runMediumSpeed() {
		System.out.println("Medium Speed");
		chain.setState(chain.getHighSpeedState());
	}

	public void runHighSpeed() {
		System.out.println("Can't run!");
	}

	public void turnOff() {
		System.out.println("Can't run!");
	}
}
