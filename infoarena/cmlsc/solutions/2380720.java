import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        File in = new File("cmlsc.in");
        File out = new File("cmlsc.out");
        Scanner scanner = new Scanner(in);

        int i, j;
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[] a = new int[m + 1];
        int[] b = new int[n + 1];
        int[][] dp = new int[m + 1][n + 1];

        for (i = 1; i <= m; i++) {
            a[i] = scanner.nextInt();
            dp[i - 1][0] = 0;
        }

        for (i = 1; i <= n; i++) {
            b[i] = scanner.nextInt();
            dp[0][i - 1] = 0;
        }

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {

                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int[] result = new int[dp[m][n]];
        int idx = 0;

        i = m;
        j = n;

        while (i > 0 && j > 0) {

            if (dp[i - 1][j] == dp[i][j]) {
                i--;
            } else if (dp[i][j - 1] == dp[i][j]) {
                j--;
            } else {
                result[idx++] = a[i];
                i--;
                j--;
            }
        }

        PrintWriter writer = new PrintWriter(out);

        writer.println(dp[m][n]);

        for (i = idx - 1; i >= 0; i--) {
            writer.printf("%d ", result[i]);
        }

        writer.close();
    }
}
