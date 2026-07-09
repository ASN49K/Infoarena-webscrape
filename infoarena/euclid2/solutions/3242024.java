import java.io.*;

public class Main {


    private static long gcd(long a, long b) {
        while (b != 0) {
            long rest = a % b;
            a = b;
            b = rest;
        }
        return a;
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("euclid2.in"));
             BufferedWriter writer = new BufferedWriter(new FileWriter("euclid2.out"))) {


            int tPerechi = Integer.parseInt(reader.readLine().trim());

            String line;
            while ((line = reader.readLine()) != null) {
                String[] tokens = line.trim().split("\\s+");
                long x = Long.parseLong(tokens[0]);
                long y = Long.parseLong(tokens[1]);
                long result = gcd(x, y);

                writer.write(result + "\n");
            }

     
            writer.flush();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
