package Calculator;

public class Calculator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ValueModelInterface valueModel = new ValueModel();
		ControlInterface ci = new CalculatorControl(valueModel);
		CalculatorView cv = new CalculatorView(ci, valueModel);

	}
}
