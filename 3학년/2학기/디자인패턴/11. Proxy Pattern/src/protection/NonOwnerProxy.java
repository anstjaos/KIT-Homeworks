package protection;

public class NonOwnerProxy implements PersonBean {
	private PersonBean person = null;
	
	public NonOwnerProxy(PersonBean person) { this.person = person; }
	
	public String getName() {
		return person.getName();
	}
	
	public String getGender() {
		return person.getGender();
	}
	
	public String getInterests() {
		return person.getInterests();
	}
	
	public int getHotOrNotRating() {
		return person.getHotOrNotRating();
	}
	
	public void setName(String name) { System.out.println("Can't set Name from non owner proxy"); }
	
	public void setGender(String gender) { System.out.println("Can't set Gender from non owner proxy"); }
	
	public void setInterests(String interests)  { System.out.println("Can't set Interests from non owner proxy"); }
	
	public void setHotOrNotRating(int rating) { 
		person.setHotOrNotRating(rating);
	}
}
