
import java.util.ArrayList;

public class WeatherData implements Subject{
	private float temperature, humidity, airPressure;
	private ArrayList<Observer> observers;
	
	public WeatherData() { observers = new ArrayList<Observer>(); }
	
	public void registerObserver(Observer o) { observers.add(o); }
	public void removeObserver(Observer o) { observers.remove(o); }
	public void notifyObservers() {
		for(Observer o : observers) o.update(temperature, humidity, airPressure);
	}
	
	public void setMeasurements(float t, float h, float p) {
		temperature = t;
		humidity = h;
		airPressure = p;
		measurementsChanged();
	}
	
	public void measurementsChanged() {
		notifyObservers();
	}
}
