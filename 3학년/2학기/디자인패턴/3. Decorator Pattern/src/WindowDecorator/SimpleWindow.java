package WindowDecorator;

public class SimpleWindow implements Window{
	private String description;
	
	public SimpleWindow() { description = "기본 창"; }
	public String getDescription() {
		return description;
	}
	public void draw() { System.out.print("기본 창 생성 완료!"); }
}
