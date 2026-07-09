import java.util.Scanner;
import java.io.*;

public class Main {

    public static int gcd(int a, int b) {
        while (b > 0) {
            int rest = a % b;
            a = b;
            b = rest;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(new FileInputStream("euclid2.in"));


        PrintWriter writer = new PrintWriter(new FileOutputStream("euclid2.out"));


        int tPerechi = scanner.nextInt();


        for (int i = 0; i < tPerechi; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int result = gcd(x, y);


            writer.println(result);
        }


        scanner.close();
        writer.close();
    }
}
