import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;

public class Main { 

    public static void main (String[] args) {
        try {
            Scanner sc = new Scanner(new File("euclid2.in"));
            int t = sc.nextInt();
            
            PrintWriter pw = new PrintWriter("euclid2.out");

            for (int i = 0; i < t; i++) {
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