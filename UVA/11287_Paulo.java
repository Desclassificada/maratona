import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;

public class Main{

    public static void main(String[] args){  
		Scanner sc = new Scanner(System.in) ;    
		BigInteger b1 = new BigInteger(sc.next());
		BigInteger b2 = new BigInteger(sc.next());
        
        while(!b1.equals(BigInteger.ZERO) && !b1.equals(BigInteger.ZERO) ){
			if(b1.isProbablePrime(10)){
				System.out.println("no");
			}else{
				BigInteger c = b2.modPow(b1, b1);
				if(c.equals(b2.remainder(b1))){
					System.out.println("yes");					
				}else{
					System.out.println("no");					
				}
			}
			
			b1 = new BigInteger(sc.next());
			b2 = new BigInteger(sc.next());
		}
        
    }
}
