package euclid;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }
    public static void main(String[] args) throws IOException {
        File input = new File("euclid2.in");
        Scanner reader = new Scanner(input);

        Main gcd = new Main();

        FileWriter output = new FileWriter("euclid2.out");

        int t = reader.nextInt();

        for(int i = 0; i < t; i++) {
            int a = reader.nextInt();
            int b = reader.nextInt();
            output.write(gcd.gcd(a, b) + "\n");
        }
        reader.close();
        output.close();
    }
}
