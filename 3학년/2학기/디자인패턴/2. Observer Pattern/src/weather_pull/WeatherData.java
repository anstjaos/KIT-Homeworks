package weather_pull;

import java.util.Observable;

public class WeatherData extends Observable{
	private float temperature, humidity, airPressure;
	
	public float getTemperature() { return temperature; }
	public float getHumidity() { return humidity; }
	public float getAirePressure() { return airPressure; }
	
	public void setMeasurements(float t, float h, float p) {
		temperature = t;
		humidity = h;
		airPressure = p;
		measurementsChanged();
	}
	
	public void measurementsChanged() {
		setChanged();
		notifyObservers();
	}
}
