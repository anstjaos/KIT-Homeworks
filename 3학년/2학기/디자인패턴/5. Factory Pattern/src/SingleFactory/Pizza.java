package SingleFactory;

public class Pizza {
	protected String name;
	
	public Pizza(String n) { name = n; }
	
	public void prepare() { System.out.println(name + " �غ�"); }
	public void bake() { System.out.println(name + " ����"); }
	public void cut() { System.out.println(name + " ����"); }
	public void box() { System.out.println(name + " ���� �Ϸ�"); }
}
