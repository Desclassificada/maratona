import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;

public class Main{

    public static void main(String[] args){  
		Scanner sc = new Scanner(System.in) ;    
		        
        while(sc.hasNext()){			
			String sx = sc.next();
			int b1 = sc.nextInt();
			int b2 = sc.nextInt();
							
			String aux = (new BigInteger(sx, b1)).toString(b2);		
				
			if(aux.length() > 7){
				System.out.println("  ERROR");											
			}else{
				System.out.format("%7s\n", aux.toUpperCase());							
			}
		}
        
    }
}
