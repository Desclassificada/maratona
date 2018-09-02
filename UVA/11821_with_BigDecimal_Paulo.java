import java.lang.Math;
import java.util.Scanner;
import java.math.BigDecimal;
import java.util.*;

public class Main{

    public static void main(String[] args){  
		Scanner sc = new Scanner(System.in) ;    
		int n = sc.nextInt();
		        
        for(int i=0; i<n; i++){
			int max = 0;
			BigDecimal ans = new BigDecimal("0");
			
			while(true){
				String current = sc.next();
				
				if(current.equals("0"))
					break;
												
				ans = ans.add(new BigDecimal(current));
			}
			String s_ans = ans.toString();
			int size = s_ans.length();
			
			while( (size > 1) &&  (s_ans.charAt(size-1) == '0') )				
				size--;
				
			if((s_ans.charAt(size-1) == '.')){
				size--;
			}
			
			
			System.out.println(s_ans.substring(0, size));				
		}

    }
}

