package com.infoarena.example;

import java.io.*;
import java.util.Scanner;

import static java.lang.System.in;
import static java.lang.System.out;

public class Main {

    public static void main(String[] args) throws IOException {
        FileInputStream instream = null;
        PrintStream outstream;
        long n, a, b;

        try {
            instream = new FileInputStream("euclid2.in");
            outstream = new PrintStream(new FileOutputStream("euclid2.out"));
            System.setIn(instream);
            System.setOut(outstream);
        } catch (Exception e) {
            System.err.println("Error Occurred.");
        }

        Scanner scanner = new Scanner(instream);
        n = scanner.nextLong();
        for (int i = 1; i <= n; i++) {
            a = scanner.nextLong();
            b = scanner.nextLong();
            if (b > a) {
                long c = a;
                a = b;
                b = c;
            }
            while (b != 0L) {
                long c = b;
                b = a % b;
                a = c;
            }
            out.println(a);
        }
        in.close();
        out.close();
    }
}
