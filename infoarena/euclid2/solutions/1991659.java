import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by vvats on 05/06/17.
 */
public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader in = new InputStreamReader(new FileInputStream("euclid2.in"));
        PrintWriter writer = new PrintWriter("euclid2.out", "UTF-8");
        Scanner scanner = new Scanner(in);

        int t = scanner.nextInt();
        while (t-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a > b) {
                writer.println(gcd(a, b));
            } else {
                writer.println(gcd(b, a));
            }
        }
        writer.close();
        in.close();
    }

    private static int gcd(int a, int b) {
        while (b != 0) {
            int c = b;
            b = a % b;
            a = c;
        }
        return a;
    }
}
