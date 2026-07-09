import java.io.*;
import java.util.*;

/**
 * Created by Aetheryon on 28.12.2015.
 */

public class Main{
    static int a,b,t,r;
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(new FileInputStream("euclid2.in"));
        PrintStream out = new PrintStream("euclid2.out");
        t = in.nextInt();
        for (int i=1;i<=t;++i){
            a = in.nextInt();
            b = in.nextInt();
            while(b>0){
                r = a%b;
                a = b;
                b = r;
            }
            out.println(a);
        }
    }

}
