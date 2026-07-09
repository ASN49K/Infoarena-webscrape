import java.io.*;
import java.util.Scanner;

/**
 * Created by Aetheryon on 28.12.2015.
 */

public class Main{
    public static int t,a,b;
    public static final String IN_FILE_NAME = "euclid2.in";
    public static final String OUT_FILE_NAME = "euclid2.out";

    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(new FileInputStream(IN_FILE_NAME));
        PrintStream out = new PrintStream(OUT_FILE_NAME);

        t = in.nextInt();
        for (int i=1;i<=t;++i){
            a = in.nextInt();
            b = in.nextInt();
            out.print(gcd(a,b)+"\n");
        }
    }

    public static int gcd(int a,int b){
        return (a==0) ? b : gcd(b%a,a);
    }
}
