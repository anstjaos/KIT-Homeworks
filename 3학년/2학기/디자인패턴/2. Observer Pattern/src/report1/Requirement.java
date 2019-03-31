package report1;

import java.util.ArrayList;

public class Requirement implements Subject{
	private ArrayList<String> inform;
	private ArrayList<Observer> observers;
	
	Requirement()
	{
		inform = new ArrayList<String>();
		observers = new ArrayList<Observer>();
	}
	
	public void registerObserver(Observer o)
	{
		observers.add(o);
	}
	
	public void removeObserver(Observer o)
	{
		observers.remove(o);
	}
	
	public void notifyObservers()
	{
		for(Observer o : observers)
		{
			o.update();
		}
	}
	
	public ArrayList<String> getInform()
	{
		return inform;
	}
	
	public void addInform(String inform)
	{
		this.inform.add(inform);
	}
	
	public void removeInform(String inform)
	{
		this.inform.remove(inform);
	}
}
