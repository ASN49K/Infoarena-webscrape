package com.infoarena.example;

import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        FileInputStream instream = null;
        PrintStream outstream;

        try {
            instream = new FileInputStream("euclid2.in");
            outstream = new PrintStream(new FileOutputStream("euclid2.out"));
            System.setIn(instream);
            System.setOut(outstream);
        } catch (Exception e) {
            System.err.println("Error Occurred.");
        }

        Scanner scanner = new Scanner(instream);
        long n = scanner.nextLong();
        for (int i = 1; i <= n; i++) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
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
            System.out.println(a);
        }
    }
}
