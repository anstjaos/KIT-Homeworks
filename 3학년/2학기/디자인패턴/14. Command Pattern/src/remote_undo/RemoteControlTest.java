package remote_undo;

public class RemoteControlTest {
	public static void main(String[] args) {
		Light light = new Light();
		GarageDoor garageDoor = new GarageDoor();
		
		LightOnCmd lightOn = new LightOnCmd(light);
		LightOffCmd lightOff = new LightOffCmd(light);
		
		DoorUpCmd doorUp = new DoorUpCmd(garageDoor);
		DoorDownCmd doorDown = new DoorDownCmd(garageDoor);
		
		RemoteControl remote = new RemoteControl();
		
		remote.setCommand(0, lightOn); remote.setCommand(1, lightOff);
		remote.setCommand(2, doorUp); remote.setCommand(3, doorDown);
		
		remote.buttonPushed(0); remote.undoButtonPushed();
		remote.buttonPushed(1); remote.undoButtonPushed();
		remote.buttonPushed(2); remote.undoButtonPushed();
		remote.buttonPushed(3); remote.undoButtonPushed();
	}
}
