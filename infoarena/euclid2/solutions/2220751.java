import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        int a, b, n, r;
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
                while (b != 0) {
                    r = a%b;
                    a = b;
                    b = r;
                }
                writer.write(String.valueOf(a) + ((n != 1) ? "\n" : ""));
                n--;
            }

            reader.close();
            writer.close();
        } catch (Exception e) {

        }
    }
}
