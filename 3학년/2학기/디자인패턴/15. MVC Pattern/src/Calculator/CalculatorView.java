package Calculator;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class CalculatorView extends JFrame implements ValueObserver, ActionListener {
	private static final long serialVersionUID = 1L;
	private JTextField inputText;
	private JButton buttons[] = new JButton[16];
	private String operator;
	private ControlInterface controller;
	private ValueModelInterface valueModel;

	public CalculatorView(ControlInterface ci, ValueModelInterface vmi) {
		super("°è»ê±â");
		super.setResizable(true);
		controller = ci;
		valueModel = vmi;
		vmi.registerObserver(this);
		operator = "";
		createView();
	}
	
	private void createView() {
		setLayout(new BorderLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(300,400);
		
		inputText = new JTextField("",15);
		JPanel inputPanel = new JPanel();
		inputPanel.add(inputText);
		
		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new GridLayout(4,4,10, 10));
		String buttonValue[] = {"1", "2", "3", "X", "4", "5", "6", "/", "7", "8", "9", "+", "C", "0", "=", "-"};
		
		for(int i = 0; i < 16; i++) {
			buttons[i] = new JButton(buttonValue[i]);
			buttonPanel.add(buttons[i]);
			buttons[i].addActionListener(this);
			
			if(i % 4 == 3) {
				buttons[i].setBackground(new Color(150, 0, 255));
				buttons[i].setForeground(Color.WHITE);
			}
			else if(i == 12 || i == 14) {
				buttons[i].setBackground(new Color(255, 166, 0));
				buttons[i].setForeground(Color.DARK_GRAY);
			}
			else {
				buttons[i].setBackground(new Color(175, 175, 175));
				buttons[i].setForeground(Color.WHITE);
			}
		}
		
		add(inputPanel, BorderLayout.NORTH);
		add(buttonPanel, BorderLayout.CENTER);
		//setVisible(true);
	}
	
	public void updateValue(int num) {
		inputText.setText(String.valueOf(num));
	}
	
	public void actionPerformed(ActionEvent e) {
		String input = e.getActionCommand();
		int value = 0;
		if(!inputText.getText().equals("")) value= Integer.parseInt(inputText.getText());
		
		switch(input) {
		case "+":
			valueModel.setValue(value);
			inputText.setText("");
			operator = "+";
			break;
		case "-":
			valueModel.setValue(value);
			inputText.setText("");
			operator = "-";
			break;
		case "/":
			valueModel.setValue(value);
			inputText.setText("");
			operator = "/";
			break;
		case "X":
			valueModel.setValue(value);
			inputText.setText("");
			operator = "X";
			break;
		case "C":
			valueModel.setValue(0);
			inputText.setText("");
			operator = "";
			break;
		case "=":
			switch(operator) {
			case "+":
				controller.plus(value);
				break;
			case "-":
				controller.minus(value);
				break;
			case "/":
				controller.division(value);
				break;
			case "X":
				controller.multiply(value);
				break;
			}
			break;
			default:
				inputText.setText(inputText.getText() + input);
				break;
		}
	}


}
