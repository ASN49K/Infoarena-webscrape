package ro.infoarena.arhiva.educationala;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Euclid {

    public static int gcd_rec(final int a, final int b) {
        return (b == 0) ? a : gcd_rec(b, a % b);
    }

    public static void main(final String[] args) throws IOException {

        System.out.println(System.getProperty("user.dir"));
        final Scanner in = new Scanner(new File("euclid2.in"));
        final FileWriter out = new FileWriter(new File("euclid2.out"));

        int t = in.nextInt();
        int a, b;
        while (t-- > 0) {
            a = in.nextInt();
            b = in.nextInt();
            out.write(String.valueOf(gcd_rec(a, b)));
            out.append('\n');

        }
        in.close();
        out.flush();
        out.close();
    }
}
