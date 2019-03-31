package remote_controller;

public class LightOnCmd implements Command {
	private Light light;

	public LightOnCmd(Light light) {
		this.light = light;
	}
	
	public void execute() {
		light.turnOn();
	}
}
