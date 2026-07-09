package ro.infoarena.arhiva.educationala.euclid;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static int gcd_rec(final int a, final int b) {
        return (b == 0) ? a : gcd_rec(b, a % b);
    }

    public static void main(final String[] args) throws IOException {

        System.out.println(System.getProperty("user.dir"));
        final Scanner in = new Scanner(new FileInputStream("euclid2.in"));
        final PrintWriter out = new PrintWriter("euclid2.out");

        int t = in.nextInt();
        int a, b;
        while (t-- > 0) {
            a = in.nextInt();
            b = in.nextInt();
            out.println(gcd_rec(a, b));

        }
        in.close();
        out.close();
    }
}
