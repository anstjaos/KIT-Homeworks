package Calculator;

public interface ValueModelInterface {
	public int getValue();
	public void setValue(int num);
	public void registerObserver(ValueObserver vo);
	public void removeObserver(ValueObserver vo);
	public void notifyObservers();
}
