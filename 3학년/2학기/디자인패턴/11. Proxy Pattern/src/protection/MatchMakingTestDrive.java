package protection;

import java.util.Hashtable;

public class MatchMakingTestDrive {
	public Hashtable<String, PersonBean> datingDB = new Hashtable<String, PersonBean>();
	public static void main(String[] args) {
		MatchMakingTestDrive test = new MatchMakingTestDrive();
		test.drive();
	}
	
	public MatchMakingTestDrive() {
		initializeDatabase();
	}
	
	public void initializeDatabase() {
		PersonBean joe = new PersonBeanImpl();
		joe.setName("Joe Javabean");
		joe.setInterests("cars, computers, music");
		joe.setHotOrNotRating(7);
		datingDB.put(joe.getName(), joe);
		
		PersonBean kelly = new PersonBeanImpl();
		kelly.setName("Kelly Klosure");
		kelly.setInterests("ebay, movies, music");
		kelly.setHotOrNotRating(6);
		datingDB.put(kelly.getName(), kelly);
	}
	
	public PersonBean getOwnerProxy(PersonBean person) {
		return new OwnerProxy(person);
	}
	
	public PersonBean getNonOwnerProxy(PersonBean person) {
		return new NonOwnerProxy(person);
	}
	
	public PersonBean getPersonFromDatabase(String name) {
		return (PersonBean)datingDB.get(name);
	}
	
	public void drive() {
		PersonBean joe = getPersonFromDatabase("Joe Javabean");
		PersonBean ownerProxy = getOwnerProxy(joe);
		System.out.println("Name: " + ownerProxy.getName());
		
		ownerProxy.setInterests("bowling, Go");
		System.out.println("Interests set from owner proxy");
		ownerProxy.setHotOrNotRating(10);
		System.out.println("Rating is " + ownerProxy.getHotOrNotRating());
		
		PersonBean nonOwnerProxy = getNonOwnerProxy(joe);
		System.out.println("Name is " + nonOwnerProxy.getName());
		nonOwnerProxy.setName("MoonSeo");
		nonOwnerProxy.setHotOrNotRating(3);
		System.out.println("Rating set from non owner proxy");
		System.out.println("Rating is " + nonOwnerProxy.getHotOrNotRating());
	}
}
