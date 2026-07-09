/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package euclid;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author dakata
 */
class Main {

    static class FastReader {

        BufferedReader br;
        StringTokenizer st;

        public FastReader(String f) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FastReader  scanner = new FastReader("euclid2.in");
        PrintWriter writer = new PrintWriter("euclid2.out");
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            int res = gcd(scanner.nextInt(), scanner.nextInt());
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
