import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class cmmdc {

    public static int cmmdc(int a, int b, int d) {
        if (0 == a % 2 && 0 == b % 2) {
            return cmmdc(a / 2, b / 2, d * 2);
        } else if (0 == a % 2 && 0 != b % 2) {
            return cmmdc(a / 2, b, d);
        } else if (0 == b % 2 && 0 != a % 2) {
            return cmmdc(a, b / 2, d);
        } else if (a > b) {
            return cmmdc(a - b, b, d);
        } else if (b > a) {
            return cmmdc(a, b - a, d);
        }
        return a * d;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        String fin = "euclid2.in";
        FileInputStream fis = new FileInputStream(fin);
        BufferedReader br = new BufferedReader(new InputStreamReader(fis));

        String line = null;
        if ((line = br.readLine()) != null) {
            PrintWriter pw = new PrintWriter("euclid2.out", "UTF-8");
            int lineCount = Integer.parseInt(line);
            for (; lineCount != 0 && line != null; lineCount--) {
                line = br.readLine();
                String[] parts = line.split(" ");
                if (parts.length == 2) {
                    pw.println(cmmdc(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]), 1));
                }
            }
            pw.close();
        }
        br.close();
    }

}
