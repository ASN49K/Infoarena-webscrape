import java.io.*;
import java.util.Scanner;

public class Main {
    private static int cmmdc(int a, int b) {
        int r;
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

        int x, y;
        while ((n--) != 0) {
            x = cin.nextInt();
            y = cin.nextInt();
            fout.println(cmmdc(x, y));
        }
        fout.close();
    }
}
