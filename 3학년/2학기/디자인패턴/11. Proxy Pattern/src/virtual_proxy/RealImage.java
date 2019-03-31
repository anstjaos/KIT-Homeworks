package virtual_proxy;

import java.awt.Graphics;
import javax.swing.Icon;
import javax.swing.JComponent;

public class RealImage extends JComponent {
	
	private static final long serialVersionUID = 1L;
	private Icon icon;
	
	public RealImage(Icon icon) {
		this.icon = icon;
	}

	void setIcon(Icon i) { icon = i; }
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		int w = icon.getIconWidth();
		int h = icon.getIconHeight();
		int x = (800 - w) / 2;
		int y = (600 - h) / 2;
		icon.paintIcon(this, g, x, y);
	}
}