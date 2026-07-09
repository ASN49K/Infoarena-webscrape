import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;
import java.io.File;

public class Cmlsc {

    public static void main(final String[] args) throws IOException {
        final File in = new File("cmlsc.in");
        final Scanner reader = new Scanner(in);
        
        final int n = reader.nextInt();
        final int[] N = new int[n];
        final int m = reader.nextInt();
        final int[] M = new int[m];

        for (int it = 0; it < n; ++it) N[it] = reader.nextInt();
        for (int it = 0; it < m; ++it) M[it] = reader.nextInt();

        reader.close();
        
        final int[][] dp = new int[1 + n][1 + m];
        for (int it = n - 1; 0 <= it; --it) {
            for (int jt = m - 1; 0 <= jt; --jt) {
                if (N[it] == M[jt]) dp[it][jt] = 1 + dp[1 + it][1 + jt];
                else dp[it][jt] = Math.max(dp[1 + it][jt], dp[it][1 + jt]);
            }
        }

        final File out = new File("cmlsc.out");
        final Writer writer = new FileWriter(out);
        writer.write(dp[0][0] + "\n");
        int it = 0;
        int jt = 0;
        while (it < n && jt < m) {
            if (N[it] == M[jt]) {
                writer.write(N[it] + " ");
                ++it;
                ++jt;
            } else if (1 + it < n && dp[1 + it][jt] == dp[it][jt]) {
                ++it;
            } else {
                ++jt;
            }
        }
        writer.write("\n");
        writer.flush();
        writer.close();
    }

}