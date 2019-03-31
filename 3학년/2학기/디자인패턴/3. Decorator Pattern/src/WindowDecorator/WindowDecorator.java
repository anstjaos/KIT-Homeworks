package WindowDecorator;

public abstract class WindowDecorator implements Window{
	protected Window wrappedWindow;
	
	public WindowDecorator(Window w) { wrappedWindow = w; }
	
	public String getDescription() { return wrappedWindow.getDescription(); }
	public void draw() { wrappedWindow.draw(); }
}
