import java.io.*;
import java.util.Scanner;

public class Main {
    static int a, b, r;

    private static int cmmdc() {
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner cin = null;
        PrintWriter fout = null;
        try {
            File fin = new File("euclid2.in");
            FileInputStream f = new FileInputStream(fin);
            FileOutputStream g = new FileOutputStream(new File("euclid2.out"));
            fout = new PrintWriter(g);
            cin = new Scanner(f);
        } catch (IOException e) {
        }

        int n = cin.nextInt();

        while ((n--) != 0) {
            a = cin.nextInt();
            b = cin.nextInt();
            fout.println(cmmdc());
        }
        fout.close();
    }
}
