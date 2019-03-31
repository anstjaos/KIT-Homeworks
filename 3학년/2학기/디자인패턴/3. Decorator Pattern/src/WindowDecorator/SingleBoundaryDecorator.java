package WindowDecorator;

public class SingleBoundaryDecorator extends WindowDecorator{
	public SingleBoundaryDecorator(Window w) { super(w); }
	
	public String getDescription() {
		return super.getDescription() + ", 단일 경계선";
	}
	
	public void draw() {
		super.draw();
		System.out.print(" 단일 경계선 추가!");
	}
}
