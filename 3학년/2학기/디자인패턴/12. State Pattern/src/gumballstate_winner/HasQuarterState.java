package gumballstate_winner;

import java.util.Random;

public class HasQuarterState implements State {
	private Random randomWinner = new Random(System.currentTimeMillis());	// 새로 추가된 Random 객체
	private GumballMachine gumballMachine;
 
	public HasQuarterState(GumballMachine gumballMachine) {
		this.gumballMachine = gumballMachine;
	}
  
	public void insertQuarter() {
		System.out.println("You can't insert another quarter");
	}
 
	public void ejectQuarter() {
		System.out.println("Quarter returned");
		gumballMachine.setState(gumballMachine.getNoQuarterState());
	}
 
	public void turnCrank() {
		System.out.println("You turned...");
		int winner = randomWinner.nextInt(10);
		if ((winner == 0) && (gumballMachine.getCount() > 1)) {		// 조건을 만족할 경우 State를 WinnerState로 전환
			gumballMachine.setState(gumballMachine.getWinnerState());
		} else {													// 조건에 만족하지 못할 경우 SoldState로 전환
			gumballMachine.setState(gumballMachine.getSoldState());
		}
	}

    public void dispense() {
        System.out.println("No gumball dispensed");
    }
    
    public void refill() { }
 
	public String toString() {
		return "waiting for turn of crank";
	}
}
