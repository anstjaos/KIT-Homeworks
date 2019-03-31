package JavaBean;

public class Quiz8_Bean {
	private int value1;
	private int value2;
	
	public Quiz8_Bean() { }
	
	public void setValue(int value1,int value2) {
		this.value1 = value1;
		this.value2 = value2;
	}

	public void setValue1(int value1) {
		this.value1 = value1;
	}

	public int getValue1() {
		return value1;
	}

	public void setValue2(int value2) {
		this.value2 = value2;
	}

	public int getValue2() {
		return value2;
	}

	public int getAdd() { return (value1+ value2);}
	public int getMelt() { return (value1 * value2);}
	public int getMinus() { return (value1 - value2);}
	public int getDiv() { return (value1 / value2);}

}