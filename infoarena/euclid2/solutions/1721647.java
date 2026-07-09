import java.io.*;

public class Main {

    public static int euclid(int a, int b) {
        while (b > 0) {
            int m = a % b;
            a = b;
            b = m;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("euclid2.in"));
        BufferedWriter bw  = new BufferedWriter(new FileWriter("euclid2.out"));

        int N = Integer.parseInt(br.readLine());
        for (int t = 0; t < N; t++) {
            String[] line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);

            bw.write(euclid(a, b) + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}
