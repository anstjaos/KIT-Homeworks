package remote_undo;

public class RemoteControl {
	private Command[] commandList;
	private Command undoCommand;
	
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
		undoCommand = commandList[index];
	}
	
	public void undoButtonPushed() {
		if(undoCommand == null) {
			System.out.println("이전 명령이 존재하지 않습니다!");
			return;
		}
		undoCommand.undo();
	}
}