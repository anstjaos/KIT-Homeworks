package weather_pull;

import java.util.Observable;
import java.util.Observer;

public class ForecastDisplay implements Observer, DisplayElement{
	private float temperature, humidity, pressure;
	private Observable observable;
	
	public ForecastDisplay(Observable observable) {
		this.observable = observable;
		observable.addObserver(this);
	}
	
	public void update(Observable o, Object arg) {
		if(o instanceof WeatherData)
		{
			WeatherData weatherData = (WeatherData)o;
			temperature = weatherData.getTemperature();
			humidity = weatherData.getHumidity();
			pressure = weatherData.getAirePressure();
			display();
		}
	}
	
	public void display() {
		System.out.println("Forecast conditions : " + temperature + "F degrees and " + humidity + "% humidity and " +pressure);
	}
}
