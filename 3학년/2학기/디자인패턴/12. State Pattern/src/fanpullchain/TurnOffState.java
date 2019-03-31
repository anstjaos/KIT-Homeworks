package fanpullchain;

public class TurnOffState implements SpeedState {
	private CeilingFanPullChain chain;

	public TurnOffState(CeilingFanPullChain chain) { this.chain = chain; }

	public void runLowSpeed() {
		System.out.println("Can't run!");
	}

	public void runMediumSpeed() {
		System.out.println("Can't run!");
	}

	public void runHighSpeed() {
		System.out.println("Can't run!");
	}

	public void turnOff() {
		System.out.println("Turn Off");
	}
}
