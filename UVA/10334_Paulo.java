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
		
		for(int i=2; i<1010; i++){
			fib.add((fib.get(i-1)).add(fib.get(i-2)));
		}
		
		while(sc.hasNext()){
			int n = sc.nextInt();
			
			System.out.println(fib.get(n+1));			
		}
		

    }
}

