import java.util.Scanner;

public class Pi{

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      int i= input.nextInt();
      double temp = 0;
      double value ;
      if(i % 2 == 0){
         while(i != 0){
            temp += formalPi(i);
            i -= 2;
         }
         value = 4 * (1 + temp );
      }
      else{
         while(i != 1){
            temp += formalPi(i);
            i -= 2;
         }
         value = 4 * (1 - temp );
      }
      
      System.out.println(value);
      
      
      
   }
   
   public static double formalPi(int i){
      
      
      return ((double)-(1/((2.0*i)-1))+(double)(1/((2.0*i)+1)));
   }

}