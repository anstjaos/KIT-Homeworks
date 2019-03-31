package remote_undo;

public class DoorDownCmd implements Command {
	private GarageDoor garageDoor;
	
	public DoorDownCmd(GarageDoor gd) {
		garageDoor = gd;
	}
	
	public void execute() {
		garageDoor.doorClose();
	}
	
	public void undo() {
		garageDoor.doorOpen();
	}
}
