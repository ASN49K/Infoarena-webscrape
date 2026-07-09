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
        try {
            BufferedReader scanner = new BufferedReader(new FileReader("euclid2.in"));
            PrintWriter writer = new PrintWriter(new FileWriter("euclid2.out"));

            int T = Integer.parseInt(scanner.readLine());

            for (int i = 0; i < T; i++) {
                String[] parts = scanner.readLine().split(" ");
                int a = Integer.parseInt(parts[0]);
                int b = Integer.parseInt(parts[1]);

                writer.println(cmmdc(a, b));
                writer.flush();
            }

            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
