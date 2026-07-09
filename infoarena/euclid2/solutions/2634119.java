package com.company;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

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
        FileWriter w = new FileWriter(new File("euclid2.out"));
        int t = r.nextInt();

        for (int i = 0; i < t; i++) {
            int a = r.nextInt();
            int b = r.nextInt();
            w.write("" + cmmdc(a, b));
            w.write('\n');
        }
        r.close();
        w.close();

    }
}
