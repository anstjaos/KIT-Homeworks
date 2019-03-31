package Calculator;

public class CalculatorControl implements ControlInterface {
	private ValueModelInterface valueModel;
	
	public CalculatorControl(ValueModelInterface vmi) {
		valueModel = vmi;
	}
	
	public void plus(int num) {
		int value = valueModel.getValue();
		value = value + num;
		valueModel.setValue(value);
	}
	
	public void minus(int num) {
		int value = valueModel.getValue();
		value = value - num;
		valueModel.setValue(value);
	}
	
	public void multiply(int num) {
		int value = valueModel.getValue();
		value = value * num;
		valueModel.setValue(value);
	}
	
	public void division(int num) {
		if(num == 0) return;
		int value = valueModel.getValue();
		value = value / num;
		valueModel.setValue(value);
	}
}
