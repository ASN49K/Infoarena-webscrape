import java.io.*;
import java.util.Scanner;

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
            Scanner scanner = new Scanner(new FileInputStream(new File("euclid2.in")));
            PrintWriter writer = new PrintWriter(new FileOutputStream(new File("euclid2.out")));

            int n = Integer.parseInt(scanner.nextLine());

            for (int i = 0; i < n; i++) {
                String[] parts = scanner.nextLine().split(" ");
                int a = Integer.parseInt(parts[0]);
                int b = Integer.parseInt(parts[1]);

                writer.println(cmmdc(a, b));
            }

            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}