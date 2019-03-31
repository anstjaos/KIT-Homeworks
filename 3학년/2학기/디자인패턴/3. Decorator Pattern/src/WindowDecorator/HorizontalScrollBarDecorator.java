package WindowDecorator;

public class HorizontalScrollBarDecorator extends WindowDecorator{
	public HorizontalScrollBarDecorator(Window w) { super(w); }
	
	public String getDescription() {
		return super.getDescription() + ", ���� ��ũ�ѹ�";
	}
	
	public void draw() {
		super.draw();
		System.out.print(" ���� ��ũ�ѹ�!");
	}
}
