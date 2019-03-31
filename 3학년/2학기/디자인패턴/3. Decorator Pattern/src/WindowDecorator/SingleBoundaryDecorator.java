package WindowDecorator;

public class SingleBoundaryDecorator extends WindowDecorator{
	public SingleBoundaryDecorator(Window w) { super(w); }
	
	public String getDescription() {
		return super.getDescription() + ", ���� ��輱";
	}
	
	public void draw() {
		super.draw();
		System.out.print(" ���� ��輱 �߰�!");
	}
}
