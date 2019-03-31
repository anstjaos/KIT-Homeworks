
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
		if(start == 0)	{ Iohandler.putString("�̹� �õ��� �ɷ��ֽ��ϴ�!");}
		else
		{
			start = 0;
			Iohandler.putString("�õ��� �ɷȽ��ϴ�.");
		}
	}
	
	public void accelerate()
	{
		if(start == -1) Iohandler.putString("�õ��� �����ֽ��ϴ�. �õ����� �ɾ��ֽʽÿ�!");
		else
		{
			if(!gear.equals("D")) Iohandler.putString("�� D�� �������ֽʽÿ�!");
			else
			{
				int i_speed = Iohandler.getInteger("������ų �ӵ��� �Է��ϼ���.");
				if(speed + i_speed > 300) Iohandler.putString("�ӵ��� 300�� ���� �� �����ϴ�."); 
				else{
					if(fuel - (speed /10) <= 0) Iohandler.putString("���ᰡ �����մϴ�!");
					else
					{
						speed += i_speed;
						fuel -= speed /10;
						Iohandler.putString("���� �ӵ��� " + speed + "km/h�̰�, ���� " + gear + "���Դϴ�.");
						showFuel();
					}
				}
			}
		}
	}
	
	public void decelerate()
	{
		if(start == -1) Iohandler.putString("�õ��� �����ֽ��ϴ�. �õ����� �ɾ��ֽʽÿ�!");
		else
		{
			if(!gear.equals("D")) Iohandler.putString("�� D�� �������ֽʽÿ�!");
			else
			{
				int i_speed = Iohandler.getInteger("���ҽ�ų �ӵ��� �Է��ϼ���.");
				if(fuel - (speed /10) <= 0) Iohandler.putString("���ᰡ �����մϴ�!");
				else
				{
					speed -= i_speed;
					fuel -= speed /10;
					if (speed <= 0)
					{
						speed = 0;
						Iohandler.putString("�ڵ����� �����Ͽ����ϴ�.");
						showFuel();
					}
					else 
					{
						Iohandler.putString("���� �ӵ��� " + speed + "km/h�̰�, ���� " + gear + "���Դϴ�.");
						showFuel();
					}
				}
			}
		}
	}
	
	public void goBack()
	{
		if(start == -1) Iohandler.putString("�õ��� �����ֽ��ϴ�. �õ����� �ɾ��ֽʽÿ�!");
		else
		{
			if(speed > 0 || !gear.equals("R")) { 
				Iohandler.putString("���� �ӵ��� "+speed+"�Դϴ�. 0���� �����ֽð�, �� R�� �ٲ��ֽʽÿ�.");
			}
			else 
			{
				speed = 10;
				if(fuel - (speed /10) <= 0)
				{
					Iohandler.putString("���ᰡ �����մϴ�!");
					speed = 0;
				}
				else
				{
					fuel -= (speed /10);
					Iohandler.putString("�ڵ����� " + speed + "�� �ӵ��� �������Դϴ�. ���� " + gear +"���Դϴ�.");
				}
			}
		}
	}
	
	public void changeGear()
	{
		if(start == -1) Iohandler.putString("�õ��� �����ֽ��ϴ�. �õ����� �ɾ��ֽʽÿ�!");
		else
		{
			String i_gear = Iohandler.getString("�� ������ �����Ͻðڽ��ϱ�?(P,R,N,D)");
			
			if(!i_gear.equals("P") && !i_gear.equals("R") && !i_gear.equals("N") &&  !i_gear.equals("D")) 
				Iohandler.putString("�߸��� ���� �Է��ϼ̽��ϴ�. ���� P,R,N,D�� �ֽ��ϴ�.");
			else
			{
				if(i_gear.equals("D")) speed = 0;
				gear = i_gear;
				Iohandler.putString("�� " + gear +"������ ����Ǿ����ϴ�.");
			}
		}
	}
	
	public void refuel()
	{
		if(speed != 0 || !gear.equals("P"))
		{
			Iohandler.putString("���� �ӵ��� "+speed+"�Դϴ�. 0���� �����ֽð�, �� P�� �ٲ��ֽʽÿ�.");
		}
		else if(fuel == 100)	{ Iohandler.putString("�̹� ���ᰡ �������ֽ��ϴ�!"); }
		else
		{
			fuel = 100;
			Iohandler.putString("���ᰡ ���� �����Ǿ����ϴ�.");
		}
	}
	
	public void turnoff()
	{
		if(start == -1) Iohandler.putString("�̹� �õ��� �����ֽ��ϴ�!");
		else
		{
			if(speed != 0 || !gear.equals("P")) Iohandler.putString("�ӵ��� 0���� ���߰�, �� P�� �������ֽʽÿ�");
			else
			{
				start = -1;
				Iohandler.putString("�õ��� �������ϴ�.");
			}
		}
	}
	
	public void showFuel()
	{
		if(fuel <= 20)
		{
			Iohandler.putString("���� �⸧�� " + fuel + "% ���ҽ��ϴ�.");
			Iohandler.putString("�⸧�� ä���ּ���!");
		}
		else Iohandler.putString("���� �⸧�� " + fuel + "% ���ҽ��ϴ�.");
	}
	// ������
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
				c.startCar();			// �õ��ɱ�
				break;
			case 2:
				c.accelerate();			// �����ϱ�
				break;
			case 3:
				c.decelerate();			// �����ϱ�
				break;
			case 4:
				c.goBack();				// �����ϱ�
				break;
			case 5:
				c.changeGear();			// ����
				break;
			case 6:
				c.refuel();				// ����ֱ�
				break;
			case 7:
				c.turnoff();			// �õ�����
				break;
			default:
				System.out.println("�߸��� ���� �Է��ϼ̽��ϴ� !");
				break;
			}
		}
	} // End of main
}	// End of Car

class Iohandler {				// ����� ����ϴ� Ŭ����
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
		System.out.println("�޴��� �����Ͽ� �ּ���.");
		System.out.println("1.�õ��ɱ�  2.�����ϱ�  3.�����ϱ�  4.�����ϱ�  5.����  6.����ֱ�  7.�õ�����");
		int num = input.nextInt();
		return num;
	}
	// ������
	Iohandler() {}
}	// End of Iohandler
