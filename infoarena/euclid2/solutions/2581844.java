package ro.infoarena.arhiva.educationala.euclid;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static int gcd_rec(int a, int b) {

        while (b > 0) {
            final int r = a % b;
            b = a;
            a = r;
        }
        return a;

    }

    public static void main(final String[] args) throws IOException {


        final Scanner in = new Scanner(new File("euclid2.in"));
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
