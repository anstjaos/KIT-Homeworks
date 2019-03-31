package weather_push;

public class WeatherData{
	private float temperature, humidity, airPressure;
	
	public WeatherData(float t, float h, float p)
	{
		temperature = t;
		humidity = h;
		airPressure = p;
	}
	
	public float getTemperature() { return temperature; }
	public float getHumidity() { return humidity; }
	public float getAirePressure() { return airPressure; }
}
