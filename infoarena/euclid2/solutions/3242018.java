import java.io.*;
import java.util.StringTokenizer;

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

        try (BufferedReader fin = new BufferedReader(new FileReader("euclid2.in"));
             BufferedWriter fout = new BufferedWriter(new FileWriter("euclid2.out"))) {


            int tPerechi = Integer.parseInt(fin.readLine());


            for (int i = 0; i < tPerechi; i++) {
                StringTokenizer st = new StringTokenizer(fin.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                // Compute GCD and write the result
                fout.write(gcd(x, y) + "\n");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
