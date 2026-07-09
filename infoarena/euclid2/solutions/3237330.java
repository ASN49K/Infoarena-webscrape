import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
    private static final BufferedReader reader;
    private static final PrintWriter writer;

    static {
        try {
            reader = new BufferedReader(new FileReader("euclid2.in"));
            writer = new PrintWriter("euclid2.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(reader.readLine());
        for (int it = 0; it < n; it++) {
            String[] tokens = reader.readLine().split(" ");
            int gcd = gcd(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[0]));
            writer.write(gcd + "\n");
        }
        writer.flush();
    }
}
