import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;

public class Base{

    public static void main(String[] args){  

        Scanner sc = new Scanner(System.in) ;    
        int t;
        
        t = sc.nextInt();
        
        for(int k=0; k<t; k++){
			StringBuilder a = new StringBuilder(sc.next()), b = new StringBuilder(sc.next()), c;

			a = a.reverse();
			b = b.reverse();
			
            BigInteger ba = new BigInteger(a.toString()), bb = new BigInteger(b.toString());
			ba = ba.add(bb);
			c = new StringBuilder(ba.toString());
			c.reverse();
			ba = new BigInteger(c.toString());
			
            System.out.println(ba);
        }
    }
}
