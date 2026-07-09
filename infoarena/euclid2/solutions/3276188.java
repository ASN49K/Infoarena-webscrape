import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("euclid2.in"));
             BufferedWriter bw = new BufferedWriter(new FileWriter("euclid2.out"))) {

            int T = Integer.parseInt(br.readLine().trim());

            for (int i = 0; i < T; i++) {
                String[] parts = br.readLine().split(" ");
                int a = Integer.parseInt(parts[0]);
                int b = Integer.parseInt(parts[1]);
                int gcd = computeGCD(a, b);
                bw.write(gcd + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}