package maxtrix

public class Matrix_for_foreach{
	public static void main(String[] args){
		Action1 a = new Action1();
		System.out.println("for�� ����� �迭");
		a.action1();
		System.out.println("foreach�� ����� �迭");
		a.action2();
	}
}
class Action1 {
	public int arr[][];
	public Action1() {
		arr = new int[3][4];
		int input=1;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<4; j++) {
				arr[i][j] = input++;
			}
		}
	}
	public void action1() {
		for(int i=0; i<3; i++) {
			int sum=0;
			for(int j=0; j<4; j++) {
				sum=sum+arr[i][j];
			}
			System.out.println(i+"��° ���� �� : " + sum);
		}
		
		int sum=0;
		for(int i=0; i<3; i++) {			
			for(int j=0; j<4; j++) {
				sum=sum+arr[i][j];
			}
		}
		System.out.println("��ü ��" + sum);
	}
	public void action2() {		
		int i=1;
		for(int[] x : arr) {
			int sum=0;
			
			for(int y : x) {
				sum = sum+y;				
			}
			System.out.println((i++)+"��° ���� �� : " + sum);			
		}		
		
		int sum=0;
		for(int[] x : arr) {
	
			for(int y : x) {
				sum = sum+y;				
			}
		}		
		System.out.println("��ü ��" + sum);
	}
}


