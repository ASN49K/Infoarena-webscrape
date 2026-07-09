import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    /*
    3
    12 42
    21 7
    9 10
     */

    public static int euclid(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return euclid(b, a%b);
        }
    }

    public static void main(String[] args) {
        int a, b, n;
        String line;
        StringTokenizer st;

        try {
            BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"));
            PrintWriter writer = new PrintWriter("euclid2.out");
            line = reader.readLine();
            n = Integer.parseInt(line);
            while (n != 0) {
                line = reader.readLine();
                st = new StringTokenizer(line, " ");
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                writer.write(String.valueOf(euclid(a, b)) + ((n != 1) ? "\n" : ""));
                n--;
            }

            reader.close();
            writer.close();
        } catch (Exception e) {

        }
    }
}
