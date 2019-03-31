
import java.util.Scanner;

public class Bicycle {	
	// instance variable
	private int speed;			
	// instance methods
	public void accelerate()
	{
		int i_speed = Iohandler.getInteger("������ų �ӵ��� �Է��ϼ���.");
		speed += i_speed;
		Iohandler.putString("���� �ӵ��� " + speed + "km/h�Դϴ�.");
	}

	public void decelerate() 
	{
		int i_speed = Iohandler.getInteger("���ҽ�ų �ӵ��� �Է��ϼ���.");
		speed -= i_speed;
		if (speed <= 0)
		{
			speed = 0;
			System.out.println("�����Ű� �����Ͽ����ϴ�.");
		}
		else System.out.println("���� �ӵ��� " + speed + "km/h�Դϴ�.");
	}

	public void constantSpeed()
	{ 
		if(speed == 0) Iohandler.putString("�����Ű� �����Ͽ����ϴ�. �ӵ��� �÷��ּ���.");
		else Iohandler.putString("��� � �� �Դϴ�. ���� �ӵ��� " + speed + "km/h�Դϴ�.");
	}

	public int getSpeed() {return speed;}
	// ������ - speed�� 0���� �ʱ�ȭ ���ش�.
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
				bi.accelerate();		// �����ϱ�
				break;
			case 2:
				bi.decelerate();		// �����ϱ�
				break;
			case 3:
				bi.constantSpeed();		// ��ӿ���
				break;
			default:
				System.out.println("�߸��� ���� �Է��ϼ̽��ϴ� !");
				break;
			}
		}

	} // End of main
} // End of Bicycle

class Iohandler {		// ������� ����ϴ� Ŭ����
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
		System.out.println("�޴��� �����Ͽ� �ּ���.");
		System.out.println("1.���� �  2.���� �  3.��� �");
		int num = input.nextInt();
		return num;
	}
	// ������
	Iohandler() {}
} // End of Iohandler
