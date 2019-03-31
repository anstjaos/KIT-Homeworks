package remote_controller;

public class RemoteControl {
	private Command[] commandList;
	
	public RemoteControl() {
		commandList = new Command[4];
	}
	
	public void setCommand(int index, Command c) {
		if(index > commandList.length) {
			System.out.println("인덱스 초과!");
			return;
		}
		commandList[index] = c;
	}
	
	public void buttonPushed(int index) {
		if(index > commandList.length) {
			System.out.println("인덱스 초과!");
			return;
		}
		commandList[index].execute();
	}
}