package remote_undo;

public class DoorUpCmd implements Command {
	private GarageDoor garageDoor;

	public DoorUpCmd(GarageDoor gd) {
		garageDoor = gd;
	}
	
	public void execute() {
		garageDoor.doorOpen();
	}
	
	public void undo() {
		garageDoor.doorClose();
	}
}
