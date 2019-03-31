package remote_controller;

public class LightOffCmd implements Command {
	private Light light;

	public LightOffCmd(Light light) {
		this.light = light;
	}
	
	public void execute() {
		light.turnOff();
	}
}
