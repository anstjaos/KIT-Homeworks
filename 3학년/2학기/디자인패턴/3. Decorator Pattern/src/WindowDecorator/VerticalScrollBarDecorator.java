package WindowDecorator;

public class VerticalScrollBarDecorator extends WindowDecorator{
	public VerticalScrollBarDecorator(Window w) { super(w); }
	
	public String getDescription() {
		return super.getDescription() + ", ���� ��ũ�ѹ�";
	}
	
	public void draw() {
		super.draw();
		System.out.print(" ���� ��ũ�ѹ� �߰�!");
	}
}
