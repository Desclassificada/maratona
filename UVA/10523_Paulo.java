import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;

public class Main{

    public static void main(String[] args){  

		int n;
		Scanner sc = new Scanner(System.in) ;    
		
        
        while(sc.hasNext()){
			BigInteger a;
			BigInteger ans = BigInteger.ZERO;
			n = sc.nextInt();
			a = sc.nextBigInteger();
			
			BigInteger aux1 = new BigInteger("0");
			BigInteger aux2 = new BigInteger("1");
			
			for(int i=1; i<=n; i++){
				aux1 = aux1.add(BigInteger.ONE);
				aux2 = aux2.multiply(a);
				
				ans = ans.add( aux1.multiply(aux2) );
			}
			
			System.out.println(ans);
		}
        
    }
}
