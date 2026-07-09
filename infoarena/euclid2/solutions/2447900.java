/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author dakata
 */
class Main {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("euclid2.in"));
        PrintStream writer = new PrintStream("euclid2.out");
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int res = gcd(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()));
            writer.println(res);

        }
    }

    static int gcd(int a, int b) {
        if (a < 0) {
            a = -a;
        }
        if (b < 0) {
            b = -b;
        }
        while (b != 0) {
            a %= b;
            if (a == 0) {
                return b;
            }
            b %= a;
        }
        return a;
    }
}
