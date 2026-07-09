import java.io.*;
import java.util.Scanner;

public class Main {
    private static int gcd(int a, int b) {
        int r = a % b;

        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }

        return b;
    }

    public static void main(String[] args) throws IOException {
        String in_file_name = "euclid2.in";
        String out_file_name = "euclid2.out";

        FileReader in_file = new FileReader(in_file_name);
        FileWriter out_file = new FileWriter(out_file_name);

        Scanner in = new Scanner(in_file);
        PrintWriter out = new PrintWriter(out_file);

        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            int a, b;
            a = in.nextInt();
            b = in.nextInt();

            out.write(gcd(a, b) + "\n");
        }

        in.close();
        out.close();
    }
}
