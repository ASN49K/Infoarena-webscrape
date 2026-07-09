import java.util.*;
import java.io.*;

public class Main { 

    public static void main (String[] args) {
        try {
            Scanner sc = new Scanner(new File("euclid2.in"));
            PrintWriter pw = new PrintWriter("euclid2.out");

            for (int i = 0; i < sc.nextInt(); i++) {
                pw.write(GCD(sc.nextInt(), sc.nextInt()) + "\n");
            }
            sc.close();
            pw.close();
        }
        catch(Exception e) { }
    }

    private static long GCD(long a, long b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }
}