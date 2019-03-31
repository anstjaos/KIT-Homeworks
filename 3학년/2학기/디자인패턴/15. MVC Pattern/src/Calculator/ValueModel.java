package Calculator;

import java.util.ArrayList;

public class ValueModel implements ValueModelInterface {
	private int value;
	public ArrayList<ValueObserver> valueObservers;
	
	public ValueModel() {
		valueObservers = new ArrayList<ValueObserver>();
		value = 0;
	}
	
	public int getValue() {
		return value;
	}
	
	public void setValue(int value) {
		this.value = value;
		notifyObservers();
	}
	
	public void registerObserver(ValueObserver vo) {
		valueObservers.add(vo);
	}
	
	public void removeObserver(ValueObserver vo) {
		valueObservers.remove(vo);
	}
	
	public void notifyObservers() {
		for(ValueObserver vo : valueObservers) {
			vo.updateValue(value);
		}
	}
}
