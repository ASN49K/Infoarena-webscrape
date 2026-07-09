/**
 * Created by Alex.Kerezsi on 1/28/2019.
 */

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    private static final String IN_FILE = "euclid2.in";
    private static final String OUT_FILE = "euclid2.out";

    private static long euclid(int a, int b) {
        int temp;

        while (b != 0) {
            temp = a;
            a = b;
            b = temp % b;
        }

        return a;
    }

    public static void main(String[] args) {
        /*try (
                final Scanner bufferR = new Scanner(new FileInputStream(IN_FILE));
                final PrintStream bufferW = new PrintStream(OUT_FILE);
        ) {
            final int n = bufferR.nextInt();

            int a;
            int b;
            for (int i = 0; i < n; i++) {
                a = bufferR.nextInt();
                b = bufferR.nextInt();

                bufferW.println(euclid(a, b));
            }
        } catch (Exception e) {
        }*/
    }
}
