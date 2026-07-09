import java.io.*;

/**
 * Created by daniel1.macovei on 3/13/2017.
 */
public class Main {
    public static void main(String[] args) throws IOException {

        try (BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"))) {
            try (PrintWriter writer = new PrintWriter(new FileWriter("euclid2.out"))) {
                Integer n = Integer.valueOf(reader.readLine());
                for (int index = 0; index < n; index++) {
                    String[] numbers = reader.readLine().split(" ");
                    writer.println(cmmdc(Integer.valueOf(numbers[0]), Integer.valueOf(numbers[1])));
                }
            }
        }
    }

    private static int cmmdc(int a, int b) {

        int z;
        while (b != 0) {
            z = a;
            a = b;
            b = z % b;
        }
        return a;
    }
}
