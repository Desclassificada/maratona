import java.lang.Math;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;

public class Main{

    public static void main(String[] args){  
		Scanner sc = new Scanner(System.in) ;    
		int n = sc.nextInt();
		        
        for(int i=0; i<n; i++){
			int max = 0;
			BigInteger ans = new BigInteger("0");
			
			while(true){
				String current = sc.next();
				
				if(current.equals("0"))
					break;
												
				int index;	
				for(index=0; index < current.length(); index++){
					if(current.charAt(index) == '.')
						break;
				}
				
				int size = current.length() - index-1;
				if(size < 0)
					size = 0;
					
				String num = new String();					
				if(size > 0)
					num = current.substring(0, index) + current.substring(index+1);
				else
					num = current;
				
//				System.out.println(current + " = " + num);					
				
				if(size <= max){
					StringBuilder sb = new StringBuilder(num);
					for(int j=size; j< max; j++)
						sb.append('0');
					
					ans = ans.add(new BigInteger(sb.toString()));					
				}else{
					StringBuilder sb = new StringBuilder();
					for(int j=max; j< size; j++)
						sb.append('0');
						
					ans = new BigInteger(ans.toString() + sb.toString());
					
					ans = ans.add(new BigInteger(num));					
					max = size;
				}
										
			}
			
			StringBuilder sb = new StringBuilder("1");
			for(int j=0; j< max; j++)
				sb.append('0');
				
			int signal = ans.signum();
			ans = ans.abs();

			BigInteger mod = new BigInteger(sb.toString());
			BigInteger a = ans.divide(mod);
			BigInteger b = ans.remainder(mod);
			
			if( signal == 0){
				System.out.println(0);
			}else if( a.equals(BigInteger.ZERO)){
				
				if(signal == -1)
					System.out.print("-");
					
				System.out.print("0.");
				
				String s_ans = b.toString();
				for(int j=s_ans.length(); j < max; j++)
					System.out.print('0');

				System.out.println(s_ans);				
			}else if( b.equals(BigInteger.ZERO)){
				if(signal == -1)
					System.out.print("-");
				System.out.println(a);								
			}else{
				if(signal == -1)
					System.out.print("-");
				System.out.print(a + ".");												
				
				StringBuilder s_ans = new StringBuilder(b.toString());
				for(int j=s_ans.length(); j < max; j++)
					System.out.print('0');
					
				BigInteger aux = new BigInteger(s_ans.reverse().toString());
				s_ans = new StringBuilder(aux.toString());
				
				System.out.println(new BigInteger(s_ans.reverse().toString()));				
			}
		}

    }
}

