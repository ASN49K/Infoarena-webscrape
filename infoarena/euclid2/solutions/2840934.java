import java.io.*;
import java.util.Scanner;

public class Main {
    private static class Pair {
        int a;
        int b;
    }

    private static void swapCompare(Pair p) {
        if (p.a > p.b) {
            p.a = p.a ^ p.b;
            p.b = p.a ^ p.b;
            p.a = p.a ^ p.b;
        }
    }

    private static int euclid(Pair p) {
        while (p.a != 0) {
            p.b = p.b % p.a;
            swapCompare(p);
        }
        return p.b;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("euclid2.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("euclid2.out"));

        int number = in.nextInt();
        Pair p = new Pair();

        while (number != 0) {
            p.a = in.nextInt();
            p.b = in.nextInt();
            swapCompare(p);
            out.write(String.format("%d\n", euclid(p)));
            number--;
        }

        in.close();
        out.close();
    }
}
