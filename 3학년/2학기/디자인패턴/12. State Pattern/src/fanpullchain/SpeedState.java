package fanpullchain;

public interface SpeedState {
	public void runLowSpeed();
	public void runMediumSpeed();
	public void runHighSpeed();
	public void turnOff();
}