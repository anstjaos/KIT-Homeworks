package WindowDecorator;

public class SimpleWindow implements Window{
	private String description;
	
	public SimpleWindow() { description = "�⺻ â"; }
	public String getDescription() {
		return description;
	}
	public void draw() { System.out.print("�⺻ â ���� �Ϸ�!"); }
}
