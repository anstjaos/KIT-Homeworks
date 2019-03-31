package WindowDecorator;

public class HorizontalScrollBarDecorator extends WindowDecorator{
	public HorizontalScrollBarDecorator(Window w) { super(w); }
	
	public String getDescription() {
		return super.getDescription() + ", 수평 스크롤바";
	}
	
	public void draw() {
		super.draw();
		System.out.print(" 수평 스크롤바!");
	}
}
