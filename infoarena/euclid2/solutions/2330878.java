/**
 * Created by Alex.Kerezsi on 1/28/2019.
 */

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    private static final String IN_FILE = "euclid2.in";
    private static final String OUT_FILE = "euclid2.out";

    private static long euclid(final long a, final long b) {
        if (a == 0)
            return a;
        if (b == 0)
            return b;

        long tempA = a;
        long tempB = b;

        while (tempA != tempB) {
            if (tempA > tempB) {
                tempA = tempA - tempB;
            } else if (tempA < tempB) {
                tempB = tempB - tempA;
            }
        }

        return tempA;
    }

    public static void main(String[] args) {
        try (
                final Scanner bufferR = new Scanner(new FileInputStream(IN_FILE));
                final PrintStream bufferW = new PrintStream(OUT_FILE);
        ) {
            final int n = bufferR.nextInt();

            long a;
            long b;
            for (int i = 0; i < n; i++) {
                a = bufferR.nextLong();
                b = bufferR.nextLong();

                bufferW.println(euclid(a, b));
            }
        } catch (Exception e) {
        }
    }
}
