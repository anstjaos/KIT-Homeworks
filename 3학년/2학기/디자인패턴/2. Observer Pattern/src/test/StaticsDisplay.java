
public class StaticsDisplay implements Observer, DisplayElement{
	private float temperature, humidity, pressure;
	private Subject weatherData;
	
	public StaticsDisplay(Subject weatherData) {
		this.weatherData = weatherData;
		this.weatherData.registerObserver(this);
	}
	
	public void update(float t, float h, float p) {
		temperature = t;
		humidity = h;
		pressure = p;
		display();
	}
	
	public void display() {
		System.out.println("Statics conditions : " + temperature + "F degrees and " + humidity + "% humidity and " + pressure);
	}
}
