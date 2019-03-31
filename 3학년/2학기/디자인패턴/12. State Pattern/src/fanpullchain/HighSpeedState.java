package fanpullchain;

public class HighSpeedState implements SpeedState {
	private CeilingFanPullChain chain;
	
	public HighSpeedState(CeilingFanPullChain chain) { this.chain = chain; }
	
	public void runLowSpeed() {
		System.out.println("Can't run!");
	}
	
	public void runMediumSpeed() {
		System.out.println("Can't run!");
	}
	
	public void runHighSpeed() {
		System.out.println("High Speed");
		chain.setState(chain.getTurnOffState());
	}
	
	public void turnOff() {
		System.out.println("Can't run!");
	}
}
