package report1;

import java.util.ArrayList;

public interface Subject {
	public void registerObserver(Observer o);
	public void removeObserver(Observer o);
	public void notifyObservers();
	public ArrayList<String> getInform();
}
