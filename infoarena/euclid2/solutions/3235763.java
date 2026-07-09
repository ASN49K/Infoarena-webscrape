import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Euclid2 {
    private static final Scanner reader;
    private static final BufferedWriter writer;

    static {
        try {
            reader = new Scanner(new FileReader("euclid2.in"));
            writer = new BufferedWriter(new FileWriter("euclid2.out"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        int n = reader.nextInt();
        for (int it = 0; it < n; it++) {
            int gcd = gcd(reader.nextInt(), reader.nextInt());
            writer.write(gcd + "\n");
        }
        writer.flush();
    }
}
