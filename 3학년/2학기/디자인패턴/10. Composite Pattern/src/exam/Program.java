package exam;

public class Program {
	public static void main(String[] args) {
		Leaf c1, c2, c3, c4;
		c1 = new Leaf(); c2 = new Leaf(); c3 = new Leaf(); c4 = new Leaf();
		
		Composite g, g1, g2;
		g = new Composite(); g1 = new Composite(); g2 = new Composite();
		
		g1.add(c1); g1.add(c2); g1.add(c3);
		g2.add(c4);
		g.add(g1); g.add(g2);
		
		g.print();
	}
}
