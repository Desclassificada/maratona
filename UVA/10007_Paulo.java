import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

public class Main {

    static BigInteger memo[] = new BigInteger[310];

    public static BigInteger DP(int n){
        if(n == 0)
            return BigInteger.ONE;

        if(memo[n] != null)
            return memo[n];

        return memo[n] = (DP(n-1).multiply(BigInteger.valueOf(2*(2*n-1)))).divide(BigInteger.valueOf(n+1));
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n;
        n = sc.nextInt();

        while(n > 0){

            BigInteger ans = DP(n);

            for(int i=n; i>1; i--){
                ans = ans.multiply(BigInteger.valueOf(i));
            }

            System.out.println(ans);
            n = sc.nextInt();
        }
    }
}
