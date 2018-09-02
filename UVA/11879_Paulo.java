import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;

public class Main{

    public static void main(String[] args){  

		Scanner sc = new Scanner(System.in) ;    
		
		BigInteger mod = new BigInteger("17");
		BigInteger a;
		
		a = sc.nextBigInteger();
        
        while(!a.equals(BigInteger.ZERO)){
			
			a = a.remainder(mod);
			if(a.equals(BigInteger.ZERO))
				System.out.println(1);
			else
				System.out.println(0);
				
			a = sc.nextBigInteger();
		}
        
    }
}
