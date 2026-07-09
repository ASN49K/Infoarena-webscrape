//package random;

import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        File file = new File("euclid2.in");
        Scanner scanner = new Scanner(file);
        FileWriter fileWriter = new FileWriter("euclid2.out");
        PrintWriter printWriter = new PrintWriter(fileWriter);

        int n = scanner.nextInt();
        int x, y;
        for (int i = 1; i <= n; i++) {
            x = scanner.nextInt();
            y = scanner.nextInt();
            printWriter.print(gcd(x, y));
            printWriter.print("\n");
        }


        scanner.close();
        printWriter.close();
        fileWriter.close();
    }

    private static int gcd(int a, int b) {
        int m;
        while (b != 0) {
            m = b;
            b = a % b;
            a = m;
        }
        return a;
    }
}
