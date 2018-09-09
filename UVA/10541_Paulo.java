import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

public class Main {

    static BigInteger memo[][] = new BigInteger[250][250];

    static Vector<Integer> v = new Vector<>();
    static int n, k;

    public static BigInteger DP(int i, int j){
        if(j == k)
            return BigInteger.ONE;
        if(i >= n)
            return BigInteger.ZERO;
        if( (n-i) < v.get(j) )
            return BigInteger.ZERO;

        if(memo[i][j] != null)
            return memo[i][j];

        return memo[i][j] = DP(i+1, j).add(DP(i+v.get(j)+1, j+1));
    }

    public static void main(String[] args) {

        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();

        while(t-- > 0){
            v.clear();

            for(int i=0; i<250; i++)
                for(int j=0; j<250; j++)
                    memo[i][j] = null;

            n = sc.nextInt();
            k = sc.nextInt();

            for(int i=0; i<k; i++)
                v.add(sc.nextInt());

            System.out.println(DP(0,0));
        }
    }
}
