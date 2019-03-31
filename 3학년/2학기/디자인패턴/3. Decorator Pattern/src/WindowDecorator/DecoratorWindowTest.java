package WindowDecorator;

public class DecoratorWindowTest {

	public static void main(String[] args) {
		Window w1 = new SimpleWindow();
		w1.draw(); System.out.println();
		w1.getDescription(); System.out.println();
		
		w1 = new HorizontalScrollBarDecorator(w1);
		w1 = new SingleBoundaryDecorator(w1);
		w1.draw(); System.out.println();
		w1.getDescription(); System.out.println();
		
		Window w2 = new SimpleWindow();
		w2.draw(); System.out.println();
		w2.getDescription(); System.out.println();
		
		w2 = new DoubleBoundaryDecorator(w2);
		w2 = new VerticalScrollBarDecorator(w2);
		w2.draw(); System.out.println();
		w2.getDescription(); System.out.println();
	}

}
