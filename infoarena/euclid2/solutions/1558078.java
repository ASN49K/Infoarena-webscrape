import java.io.*;
import java.util.*;

/**
 * Created by Aetheryon on 28.12.2015.
 */

public class Main{
    static int a,b,t;
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(new FileInputStream("euclid2.in"));
        PrintStream out = new PrintStream("euclid2.out");
        t = in.nextInt();
        for (int i=1;i<=t;++i){
            a = in.nextInt();
            b = in.nextInt();
            out.println(gcd(a,b));
        }
    }

    public static int gcd(int a,int b){
        return (a==0) ? b : gcd(b%a,a);
    }
}
