package SingleFactory;

public class PizzaClient {
	public static void main(String[] args) {
		SimplePizzaFactory spf = new SimplePizzaFactory();
		PizzaStore ps = new PizzaStore(spf);
		
		Pizza pz = ps.orderPizza("ġ������");
		pz = ps.orderPizza("��������");
		pz = ps.orderPizza("��ä����");
		pz = ps.orderPizza("����δ�����");
		
		pz = ps.orderPizza("�Ұ�� ����");
		if(pz == null) System.out.println("�ش� ���ڴ� �������� �ʽ��ϴ�!");
	}
}
