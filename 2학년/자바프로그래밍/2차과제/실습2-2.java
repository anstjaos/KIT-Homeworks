
import java.util.Scanner;

public class Bicycle {	
	// instance variable
	private int speed;			
	// instance methods
	public void accelerate()
	{
		int i_speed = Iohandler.getInteger("증가시킬 속도를 입력하세요.");
		speed += i_speed;
		Iohandler.putString("현재 속도는 " + speed + "km/h입니다.");
	}

	public void decelerate() 
	{
		int i_speed = Iohandler.getInteger("감소시킬 속도를 입력하세요.");
		speed -= i_speed;
		if (speed <= 0)
		{
			speed = 0;
			System.out.println("자전거가 정지하였습니다.");
		}
		else System.out.println("현재 속도는 " + speed + "km/h입니다.");
	}

	public void constantSpeed()
	{ 
		if(speed == 0) Iohandler.putString("자전거가 정지하였습니다. 속도를 올려주세요.");
		else Iohandler.putString("등속 운동 중 입니다. 현재 속도는 " + speed + "km/h입니다.");
	}

	public int getSpeed() {return speed;}
	// 생성자 - speed를 0으로 초기화 해준다.
	Bicycle() { speed = 0;}

	public static void main(String[] args)
	{
		Bicycle bi = new Bicycle();
		
		while (true) 
		{
			int menu = Iohandler.getMenu();
			switch (menu)
			{
			case 1:
				bi.accelerate();		// 가속하기
				break;
			case 2:
				bi.decelerate();		// 감속하기
				break;
			case 3:
				bi.constantSpeed();		// 등속운행
				break;
			default:
				System.out.println("잘못된 값을 입력하셨습니다 !");
				break;
			}
		}

	} // End of main
} // End of Bicycle

class Iohandler {		// 입출력을 담당하는 클래스
	// static variable
	public static Scanner input = new Scanner(System.in);
	// static methods
	public static void putString(String msg) { System.out.println(msg); }
	public static int getInteger(String msg)
	{
		System.out.println(msg);
		int num = input.nextInt();
		return num;
	}
	
	public static int getMenu() {
		System.out.println("메뉴를 선택하여 주세요.");
		System.out.println("1.가속 운동  2.감속 운동  3.등속 운동");
		int num = input.nextInt();
		return num;
	}
	// 생성자
	Iohandler() {}
} // End of Iohandler
