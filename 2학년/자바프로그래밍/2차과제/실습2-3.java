
import java.util.Scanner;

public class Car {
	// instance variables
	private int speed;
	private int fuel;
	private String gear;
	private int start;
	// instance methods
	public void startCar() 
	{ 
		if(start == 0)	{ Iohandler.putString("이미 시동이 걸려있습니다!");}
		else
		{
			start = 0;
			Iohandler.putString("시동이 걸렸습니다.");
		}
	}
	
	public void accelerate()
	{
		if(start == -1) Iohandler.putString("시동이 꺼져있습니다. 시동부터 걸어주십시오!");
		else
		{
			if(!gear.equals("D")) Iohandler.putString("기어를 D로 변경해주십시오!");
			else
			{
				int i_speed = Iohandler.getInteger("증가시킬 속도를 입력하세요.");
				if(speed + i_speed > 300) Iohandler.putString("속도는 300을 넘을 수 없습니다."); 
				else{
					if(fuel - (speed /10) <= 0) Iohandler.putString("연료가 부족합니다!");
					else
					{
						speed += i_speed;
						fuel -= speed /10;
						Iohandler.putString("현재 속도는 " + speed + "km/h이고, 기어는 " + gear + "단입니다.");
						showFuel();
					}
				}
			}
		}
	}
	
	public void decelerate()
	{
		if(start == -1) Iohandler.putString("시동이 꺼져있습니다. 시동부터 걸어주십시오!");
		else
		{
			if(!gear.equals("D")) Iohandler.putString("기어를 D로 변경해주십시오!");
			else
			{
				int i_speed = Iohandler.getInteger("감소시킬 속도를 입력하세요.");
				if(fuel - (speed /10) <= 0) Iohandler.putString("연료가 부족합니다!");
				else
				{
					speed -= i_speed;
					fuel -= speed /10;
					if (speed <= 0)
					{
						speed = 0;
						Iohandler.putString("자동차가 정지하였습니다.");
						showFuel();
					}
					else 
					{
						Iohandler.putString("현재 속도는 " + speed + "km/h이고, 기어는 " + gear + "단입니다.");
						showFuel();
					}
				}
			}
		}
	}
	
	public void goBack()
	{
		if(start == -1) Iohandler.putString("시동이 꺼져있습니다. 시동부터 걸어주십시오!");
		else
		{
			if(speed > 0 || !gear.equals("R")) { 
				Iohandler.putString("현재 속도는 "+speed+"입니다. 0으로 낮춰주시고, 기어를 R로 바꿔주십시오.");
			}
			else 
			{
				speed = 10;
				if(fuel - (speed /10) <= 0)
				{
					Iohandler.putString("연료가 부족합니다!");
					speed = 0;
				}
				else
				{
					fuel -= (speed /10);
					Iohandler.putString("자동차가 " + speed + "의 속도로 후진중입니다. 기어는 " + gear +"단입니다.");
				}
			}
		}
	}
	
	public void changeGear()
	{
		if(start == -1) Iohandler.putString("시동이 꺼져있습니다. 시동부터 걸어주십시오!");
		else
		{
			String i_gear = Iohandler.getString("몇 단으로 변속하시겠습니까?(P,R,N,D)");
			
			if(!i_gear.equals("P") && !i_gear.equals("R") && !i_gear.equals("N") &&  !i_gear.equals("D")) 
				Iohandler.putString("잘못된 값을 입력하셨습니다. 기어는 P,R,N,D가 있습니다.");
			else
			{
				if(i_gear.equals("D")) speed = 0;
				gear = i_gear;
				Iohandler.putString("기어가 " + gear +"단으로 변경되었습니다.");
			}
		}
	}
	
	public void refuel()
	{
		if(speed != 0 || !gear.equals("P"))
		{
			Iohandler.putString("현재 속도는 "+speed+"입니다. 0으로 낮춰주시고, 기어를 P로 바꿔주십시오.");
		}
		else if(fuel == 100)	{ Iohandler.putString("이미 연료가 가득차있습니다!"); }
		else
		{
			fuel = 100;
			Iohandler.putString("연료가 가득 충전되었습니다.");
		}
	}
	
	public void turnoff()
	{
		if(start == -1) Iohandler.putString("이미 시동이 꺼져있습니다!");
		else
		{
			if(speed != 0 || !gear.equals("P")) Iohandler.putString("속도를 0으로 낮추고, 기어를 P로 변경해주십시오");
			else
			{
				start = -1;
				Iohandler.putString("시동이 꺼졌습니다.");
			}
		}
	}
	
	public void showFuel()
	{
		if(fuel <= 20)
		{
			Iohandler.putString("현재 기름은 " + fuel + "% 남았습니다.");
			Iohandler.putString("기름을 채워주세요!");
		}
		else Iohandler.putString("현재 기름은 " + fuel + "% 남았습니다.");
	}
	// 생성자
	Car()
	{
		speed = 0;
		gear = "P";
		fuel = 100;
		start = -1;	
	}
	
	public static void main(String[] args) {
		Car c = new Car();
		while(true)
		{
			int menu = Iohandler.getMenu();
			switch (menu)
			{
			case 1:
				c.startCar();			// 시동걸기
				break;
			case 2:
				c.accelerate();			// 가속하기
				break;
			case 3:
				c.decelerate();			// 감속하기
				break;
			case 4:
				c.goBack();				// 후진하기
				break;
			case 5:
				c.changeGear();			// 기어변속
				break;
			case 6:
				c.refuel();				// 연료넣기
				break;
			case 7:
				c.turnoff();			// 시동끄기
				break;
			default:
				System.out.println("잘못된 값을 입력하셨습니다 !");
				break;
			}
		}
	} // End of main
}	// End of Car

class Iohandler {				// 입출력 담당하는 클래스
	// static methods
	public static Scanner input = new Scanner(System.in);
	public static void putString(String msg) { System.out.println(msg); }
	public static int getInteger(String msg)
	{
		System.out.println(msg);
		int num = input.nextInt();
		return num;
	}
	public static String getString(String msg)
	{
		System.out.println(msg);
		String str = input.next();
		return str;
	}
	public static int getMenu() {
		Scanner input = new Scanner(System.in);
		System.out.println("메뉴를 선택하여 주세요.");
		System.out.println("1.시동걸기  2.가속하기  3.감속하기  4.후진하기  5.기어변속  6.연료넣기  7.시동끄기");
		int num = input.nextInt();
		return num;
	}
	// 생성자
	Iohandler() {}
}	// End of Iohandler
