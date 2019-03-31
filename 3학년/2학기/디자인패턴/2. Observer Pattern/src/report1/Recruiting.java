package report1;

public class Recruiting {

	public static void main(String[] args) {
		Requirement s = new Requirement();
		Requirement s1 = new Requirement();
		
		s.addInform("Samsung");
		s.addInform("Kakao");
		s.addInform("Naver");
		
		s1.addInform("Line");
		s1.addInform("SE");
		s1.addInform("KIT");
		
		Graduate g = new Graduate(s);
		ExpectedGraduate eg = new ExpectedGraduate(s1);
		
		g.display();
		eg.display();
		
		s.removeInform("Naver");
		s.notifyObservers();
		
		eg.setSubject(s);
	}

}
