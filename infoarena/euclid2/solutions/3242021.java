import java.io.*;

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


            int tPerechi = Integer.parseInt(fin.readLine().trim());


            for (int i = 0; i < tPerechi; i++) {
                String line = fin.readLine().trim();
                String[] tokens = line.split("\\s+");
                int x = Integer.parseInt(tokens[0]);
                int y = Integer.parseInt(tokens[1]);


                fout.write(gcd(x, y) + "\n");
            }


            fout.flush();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
