package remote_undo;

public class LightOnCmd implements Command {
	private Light light;

	public LightOnCmd(Light light) {
		this.light = light;
	}
	
	public void execute() {
		light.turnOn();
	}
	
	public void undo() {
		light.turnOff();
	}
}
