import java.io.*;
import java.util.Scanner;

public class Main {

    public static int gcd(int a, int b) {
        int aux;
        while (b != 0) {
            aux = a % b;
            a = b;
            b = aux;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        // File input and output
        Scanner fin = new Scanner(new File("euclid2.in"));
        PrintWriter fout = new PrintWriter(new FileWriter("euclid2.out"));

        int tPerechi = fin.nextInt();
        for (int i = 0; i < tPerechi; i++) {
            int x = fin.nextInt();
            int y = fin.nextInt();
            fout.println(gcd(x, y));
        }

        // Close the file streams
        fin.close();
        fout.close();
    }
}
