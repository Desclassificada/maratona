import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;

public class Main{

    public static void main(String[] args){  
		Scanner sc = new Scanner(System.in) ;    
		String a, b;
		Vector<BigInteger> fib = new Vector<BigInteger>();
		fib.add(BigInteger.ONE);
		fib.add(BigInteger.ONE);
		
		for(int i=2; i<110; i++){
			fib.add((fib.get(i-1)).add(fib.get(i-2)));
		}
		
		while(true){
			a = sc.next();			
			b = sc.next();
			
			BigInteger b1 = BigInteger.ZERO;		
			BigInteger b2 = BigInteger.ZERO;
			
			//Converter de Fib para BigInteger
			for(int i=1; i<=a.length(); i++){
				if(a.charAt(a.length()-i) == '1')
					b1 = b1.add(fib.get(i));
			}
			
			for(int i=1; i<=b.length(); i++){
				if(b.charAt(b.length()-i) == '1')
					b2 = b2.add(fib.get(i));
			}
					
			b1 = b1.add(b2);
			
			//Converter de BigInteger para Fib
			StringBuilder ans = new StringBuilder();
			int i = 101;
			
			while( (b1.compareTo(fib.get(i)) == -1) && i>=1)
				i--;				
			
			for(; i>=1; i--){
				if(b1.compareTo(fib.get(i)) == -1){
					ans.append('0');
				}else{
					ans.append('1');
					b1 = b1.subtract(fib.get(i));
				}
			}
			
			if(ans.length() < 1)
				ans.append('0');
			
			System.out.println(ans.toString());
			
			if(sc.hasNext())
				System.out.println();
			else
				break;
		}
		

    }
}

