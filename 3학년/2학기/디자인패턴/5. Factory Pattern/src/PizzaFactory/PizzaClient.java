package PizzaFactory;

public class PizzaClient {

	public static void main(String[] args) {
		Pizza pizza; PizzaStore store;
		
		store = new NYPizzaStore();
		pizza = store.order("ġ������");
		if(pizza == null) System.out.println("�ش� ���ڴ� �������� �ʽ��ϴ�!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		pizza = store.order("��������");
		if(pizza == null) System.out.println("�ش� ���ڴ� �������� �ʽ��ϴ�!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		store = new ChicagoPizzaStore();
		pizza = store.order("��ä����");
		if(pizza == null) System.out.println("�ش� ���ڴ� �������� �ʽ��ϴ�!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		pizza = store.order("���۷δ�����");
		if(pizza == null) System.out.println("�ش� ���ڴ� �������� �ʽ��ϴ�!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
		
		pizza = store.order("ġ��ũ����Ʈ����");
		if(pizza == null) System.out.println("�ش� ���ڴ� �������� �ʽ��ϴ�!");
		else System.out.println("ordered a " + pizza.getName() + "\n");
	}

}
