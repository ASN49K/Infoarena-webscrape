/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.Character.isDigit;

/**
 *
 * @author dakata
 */
class Main {

    public static final String IN_FILE = "euclid2.in";
    public static final String OUT_FILE = "euclid2.out";

    public static final class FastScanner implements AutoCloseable {

        private static final int BUFFER_SIZE = 1 << 16;

        private final DataInputStream stream;
        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int bufferPointer = 0;
        private int bytesRead = 0;

        public FastScanner(final String fileName) throws IOException {
            stream = new DataInputStream(new FileInputStream(fileName));
        }

        public int nextInt() throws IOException {
            byte c;
            do {
                c = read();
            } while (c != '-' && !isDigit(c));
            final boolean isNegative = c == '-';
            if (isNegative) {
                c = read();
            }
            int value = 0;
            do {
                value = value * 10 + (c - '0');
                c = read();
            } while (isDigit(c));
            return isNegative ? -value : value;
        }

        private byte read() throws IOException {
            final byte c = tryRead();
            if (c == -1) {
                throw new IOException("Reached end of stream!");
            }
            return c;
        }

        private byte tryRead() throws IOException {
            if (bufferPointer == bytesRead) {
                bufferPointer = 0;
                bytesRead = stream.read(buffer, 0, BUFFER_SIZE);
                if (bytesRead == -1) {
                    bytesRead = 0;
                    return -1;
                }
            }
            return buffer[bufferPointer++];
        }

        @Override
        public void close() throws IOException {
            stream.close();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FastScanner  scanner = new FastScanner(IN_FILE);
        PrintWriter writer = new PrintWriter(OUT_FILE);
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
