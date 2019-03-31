package exam;

import java.util.*;

public class Composite implements Component {
	private ArrayList<Component> components = new ArrayList<Component>();
	public void add(Component c) { components.add(c); }
	public void print() {
		System.out.println("I'm a COMPOSITE");
		Iterator<Component> iter = components.iterator();
		while(iter.hasNext()) {
			Component c = iter.next();
			c.print();
		}
	}
}
