package online_stock;

import java.util.LinkedList;
import java.util.Queue;

public class Agent {
	private Queue<Order> orderQueue = new LinkedList<Order>();

	public void placeOrder(Order o) {
		orderQueue.add(o);
		System.out.println("주문서 저장 완료!");
	}
	
	public void sell() {
		int size = orderQueue.size();
		
		for(int i = 0; i < size; i++) {
			Order o = orderQueue.poll();
			o.execute();
		}
	}
}
