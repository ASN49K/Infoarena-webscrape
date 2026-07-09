import java.util.Scanner;

/**
 * Created by vvats on 05/06/17.
 */
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a > b) {
                System.out.println(gcd(a, b));
            } else {
                System.out.println(gcd(b, a));
            }
        }
    }

    private static int gcd(final int a, final int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
}
