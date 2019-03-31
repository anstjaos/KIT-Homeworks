package fanpullchain;

public class CeilingFanPullChain {
	private SpeedState lowSpeedState;
	private SpeedState mediumSpeedState;
	private SpeedState highSpeedState;
	private SpeedState turnOffState;
	
	private SpeedState curState;
	
	public CeilingFanPullChain() {
		lowSpeedState = new LowSpeedState(this);
		mediumSpeedState = new MediumSpeedState(this);
		highSpeedState = new HighSpeedState(this);
		turnOffState = new TurnOffState(this);
		
		curState = lowSpeedState;
	}
	
	public void runLowSpeed() { curState.runLowSpeed(); }
	public void runMediumSpeed() { curState.runMediumSpeed(); }
	public void runHighSpeed() { curState.runHighSpeed(); }
	public void turnOff() { curState.turnOff(); }
	
	public void setState(SpeedState state) { curState = state; }
	
	public SpeedState getLowSpeedState() { return lowSpeedState; }
	public SpeedState getMediumSpeedState() { return mediumSpeedState; }
	public SpeedState getHighSpeedState() { return highSpeedState; }
	public SpeedState getTurnOffState() { return turnOffState; }
}