import java.io.*;
import java.util.StringTokenizer;

public class Main {

    // Optimized GCD function
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        // Buffered input and output for large data handling
        BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter fout = new BufferedWriter(new OutputStreamWriter(System.out));


        int tPerechi = Integer.parseInt(fin.readLine());


        for (int i = 0; i < tPerechi; i++) {
            // Read the pair of integers using StringTokenizer for fast tokenization
            StringTokenizer st = new StringTokenizer(fin.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            // Compute GCD and write the result
            fout.write(gcd(x, y) + "\n");
        }

        // Close streams
        fin.close();
        fout.close();
    }
}
