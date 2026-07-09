import java.io.*;

public class Main {

    public static int cmmdc(int a, int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        try (BufferedReader scanner = new BufferedReader(new FileReader("euclid2.in"));
             BufferedWriter writer = new BufferedWriter(new FileWriter("euclid2.out"))) {

            int n = Integer.parseInt(scanner.readLine());

            for (int i = 0; i < n; i++) {
                String line = scanner.readLine();
                String[] parts = line.split(" ");
                int a = Integer.parseInt(parts[0]);
                int b = Integer.parseInt(parts[1]);

                writer.write(Integer.toString(cmmdc(a, b)));
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}