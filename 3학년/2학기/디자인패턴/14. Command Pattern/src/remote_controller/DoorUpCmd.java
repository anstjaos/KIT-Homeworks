package remote_controller;

public class DoorUpCmd implements Command {
	private GarageDoor garageDoor;

	public DoorUpCmd(GarageDoor gd) {
		garageDoor = gd;
	}
	
	public void execute() {
		garageDoor.doorOpen();
	}
}
