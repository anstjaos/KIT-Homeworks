package report1;

import java.util.ArrayList;

public class ExpectedGraduate implements Observer, DisplayInform {
	private ArrayList<String> inform;
	private Subject s;
	
	public ExpectedGraduate(Subject s) {
		this.s = s;
		s.registerObserver(this);
		inform = s.getInform();
	}
	
	public void update()
	{
		inform = s.getInform();
		display();
	}
	
	public void display()
	{
		System.out.print("졸업 예정자의 구인 정보 : ");
		for(String s: inform) System.out.print(s + " ");
		System.out.println();
	}
	
	public void setSubject(Subject s)
	{
		this.s.removeObserver(this);
		this.s = s;
		inform.clear();
		update();
	}
}
