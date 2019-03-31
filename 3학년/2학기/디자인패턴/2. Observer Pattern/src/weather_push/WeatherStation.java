package weather_push;

public class WeatherStation {
	public static void main(String[] args) {
		WeatherCenter weatherCenter = new WeatherCenter(30,40, 20.4f);
		
		CurrentConditionsDisplay currentDisplay = new CurrentConditionsDisplay(weatherCenter);
		StaticsDisplay staticsDisplay = new StaticsDisplay(weatherCenter);
		ForecastDisplay forecastDisplay = new ForecastDisplay(weatherCenter);
		
		weatherCenter.setMeasurements(80, 65, 30.4f);
		weatherCenter.setMeasurements(82, 70, 29.2f);
		weatherCenter.setMeasurements(78, 90, 29.2f);
	}
}
