package weather_push;

import java.util.Observable;
import java.util.Observer;

public class StaticsDisplay implements Observer, DisplayElement{
	private float temperature, humidity, pressure;
	private Observable observable;
	
	public StaticsDisplay(Observable observable) {
		this.observable = observable;
		observable.addObserver(this);
	}
	
	public void update(Observable o, Object args) {
		if(o instanceof WeatherCenter)
		{
			WeatherData weatherData = (WeatherData) args;
			temperature = weatherData.getTemperature();
			humidity = weatherData.getHumidity();
			pressure = weatherData.getAirePressure();
			display();
		}
		
	}
	
	public void display() {
		System.out.println("Statics conditions : " + temperature + "F degrees and " + humidity + "% humidity and " + pressure);
	}
}
