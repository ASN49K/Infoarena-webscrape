package euclid;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }
    public static void main(String[] args) {
        File input = new File("euclid2.in");
        Scanner reader = null;
        try {
            reader = new Scanner(input);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        FileWriter output = null;
        try {
            output = new FileWriter("euclid2.out");
        } catch (IOException e) {
            e.printStackTrace();
        }

        int t = reader.nextInt();

        for(int i = 0; i < t; i++) {
            int a = reader.nextInt();
            int b = reader.nextInt();
            try {
                output.write(gcd(a, b) + "\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
