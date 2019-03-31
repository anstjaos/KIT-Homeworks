package remote_controller;

public class DoorDownCmd implements Command {
	private GarageDoor garageDoor;
	
	public DoorDownCmd(GarageDoor gd) {
		garageDoor = gd;
	}
	
	public void execute() {
		garageDoor.doorClose();
	}
}
