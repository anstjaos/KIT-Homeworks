package online_stock;

import java.util.LinkedList;
import java.util.Queue;

public class Agent {
	private Queue<Order> orderQueue = new LinkedList<Order>();

	public void placeOrder(Order o) {
		orderQueue.add(o);
		System.out.println("�ֹ��� ���� �Ϸ�!");
	}
	
	public void sell() {
		int size = orderQueue.size();
		
		for(int i = 0; i < size; i++) {
			Order o = orderQueue.poll();
			o.execute();
		}
	}
}
