
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner cin  = new Scanner(System.in);
                      
            BigInteger mod = new BigInteger("2");
            mod = mod.pow(31).subtract(BigInteger.ONE);

            BigInteger b = new BigInteger("3");
            BigInteger a = cin.nextBigInteger();
            
            b = b.modPow(a, mod);
            System.out.println( b );
           
    }
    
}
