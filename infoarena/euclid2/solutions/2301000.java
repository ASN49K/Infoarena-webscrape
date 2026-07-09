import java.io.*;
import java.util.*;

public class Main {
    private static final String INPUT_FILE_PATH = "euclid2.in";
    private static final String OUTPUT_FILE_PATH = "euclid2.out";

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(INPUT_FILE_PATH));
        int n = sc.nextInt();
        PrintWriter pw = new PrintWriter(OUTPUT_FILE_PATH);
        while (n-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            pw.println(MathUtils.gcd(a, b));
        }
        pw.flush();
    }

    private static class MathUtils {
        static int gcd(int a, int b) {
            return (a == 0) ? b : gcd(b % a, a);
        }
    }
}
