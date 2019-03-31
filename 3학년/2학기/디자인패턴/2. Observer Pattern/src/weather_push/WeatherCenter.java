package weather_push;

import java.util.Observable;

public class WeatherCenter extends Observable{
	private WeatherData wd;
	
	public WeatherCenter(float t, float h, float p) {
		wd = new WeatherData(t,h,p);
	}
	
	public void setMeasurements(float t, float h, float p) {
		wd = new WeatherData(t,h,p);
		measurementsChanged();
	}
	
	public void measurementsChanged() {
		setChanged();
		notifyObservers(this.wd);
	}
}
