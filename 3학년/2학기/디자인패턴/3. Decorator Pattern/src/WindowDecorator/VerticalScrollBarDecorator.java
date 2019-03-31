package WindowDecorator;

public class VerticalScrollBarDecorator extends WindowDecorator{
	public VerticalScrollBarDecorator(Window w) { super(w); }
	
	public String getDescription() {
		return super.getDescription() + ", 수직 스크롤바";
	}
	
	public void draw() {
		super.draw();
		System.out.print(" 수직 스크롤바 추가!");
	}
}
