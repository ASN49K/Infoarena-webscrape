package com.company;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    private static int gcd(int a, int b) {
        int r = a % b;

        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }

        return b;
    }

    public static void main(String[] args) {
	    String in_file_name = "euclid2.in";
        String out_file_name = "euclid2.out";

        File in_file = new File(in_file_name);
        File out_file = new File(out_file_name);

        try {
            Scanner in = new Scanner(in_file);
            PrintWriter out = new PrintWriter(out_file);

            int T = in.nextInt();
            for (int i = 1; i <= T; i ++) {
                int a, b;
                a = in.nextInt();
                b = in.nextInt();

                out.println(gcd(a, b));
            }

            in.close();
            out.close();
        } catch (java.io.FileNotFoundException e) {
            System.err.println(e.getMessage());
        }
    }
}
