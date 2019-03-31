package SingleFactory;

public class Pizza {
	protected String name;
	
	public Pizza(String n) { name = n; }
	
	public void prepare() { System.out.println(name + " 준비"); }
	public void bake() { System.out.println(name + " 굽기"); }
	public void cut() { System.out.println(name + " 컷팅"); }
	public void box() { System.out.println(name + " 포장 완료"); }
}
