import java.io.FileInputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    private Scanner scanner;
    private PrintWriter writer;

    public static void main(String[] args) throws Exception {
        new Main().exec();
    }

    private void exec() throws Exception {
        scanner = new Scanner(new FileInputStream("euclid2.in"));
        writer = new PrintWriter("euclid2.out");

        int n = Integer.valueOf(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String[] numbers = scanner.nextLine().split(" ");
            writer.print(gcd(Integer.valueOf(numbers[0]), Integer.valueOf(numbers[1])) + "\n");
        }


        scanner.close();
        writer.close();
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }


}
