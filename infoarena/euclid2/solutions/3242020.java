import java.io.*;
import java.util.Scanner;

public class Main {

   
    public static int gcd(int a, int b) {
        int aux;
        while (b != 0) {
            aux = a % b;
            a = b;
            b = aux;
        }
        return a;
    }

    public static void main(String[] args) {
        try {

            Scanner fin = new Scanner(new File("euclid2.in"));
            PrintWriter fout = new PrintWriter(new FileOutputStream("euclid2.out"));


            int tPerechi = fin.nextInt();


            for (int i = 0; i < tPerechi; i++) {
                int x = fin.nextInt();
                int y = fin.nextInt();


                fout.println(gcd(x, y));
            }


            fin.close();
            fout.close();

        } catch (FileNotFoundException e) {
            System.err.println("File not found: " + e.getMessage());
        }
    }
}
