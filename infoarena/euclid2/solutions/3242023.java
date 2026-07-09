import java.io.*;

public class Main {


    public static long gcd(long a, long b) {
        while (b > 0) {
            long rest = a % b;
            a = b;
            b = rest;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {

        try (BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"));
             PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("euclid2.out")))) {


            int tPerechi = Integer.parseInt(reader.readLine().trim());


            for (int i = 0; i < tPerechi; i++) {
                String[] tokens = reader.readLine().trim().split("\\s+");
                long x = Long.parseLong(tokens[0]);
                long y = Long.parseLong(tokens[1]);
                long result = gcd(x, y);


                writer.println(result);
            }
        }
    }
}
