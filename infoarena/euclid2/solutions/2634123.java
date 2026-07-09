//package com.company;

import java.io.*;
import java.util.*;

public class Main {

    public static int cmmdc(int a, int b) {
        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        Scanner r = new Scanner(new File("euclid2.in"));
        PrintStream w = new PrintStream("euclid2.out");
        int t = r.nextInt();

        for (int i = 0; i < t; i++) {
            int a = r.nextInt();
            int b = r.nextInt();
            w.println(cmmdc(a, b));
        }
        r.close();
        w.close();

    }
}
