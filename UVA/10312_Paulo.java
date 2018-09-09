import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

public class Main {

    static BigInteger memoC[] = new BigInteger[30];
    static BigInteger memoS[] = new BigInteger[30];

    public static BigInteger catalan(int n){
        if(n == 0)
            return BigInteger.ONE;

        if(memoC[n] != null)
            return memoC[n];

        return memoC[n] = (catalan(n-1).multiply(BigInteger.valueOf(2*(2*n-1)))).divide(BigInteger.valueOf(n+1));
    }

    public static BigInteger superCatalan(int n){
        if(n == 0)
            return BigInteger.ONE;
        if(n == 1)
            return BigInteger.ONE;

        if(memoS[n] != null)
            return memoS[n];

        BigInteger a = superCatalan(n-1).multiply(BigInteger.valueOf(3*(2*n-3)));
        BigInteger b = superCatalan(n-2).multiply(BigInteger.valueOf(n-3));

        return memoS[n] = (a.subtract(b)).divide(BigInteger.valueOf(n));
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n;

        while(sc.hasNext()){
            n = sc.nextInt();

            BigInteger ans = (superCatalan(n).divide(BigInteger.valueOf(2))).subtract(catalan(n-1));
            if(n > 2)
                System.out.println(ans);
            else
                System.out.println(0);
        }
    }
}
