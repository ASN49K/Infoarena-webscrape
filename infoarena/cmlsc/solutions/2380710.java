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
        }

        for (i = 1; i <= n; i++) {
            b[i] = scanner.nextInt();
        }

        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }

                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        Stack<Integer> stack = new Stack<>();

        i = m;
        j = n;

        while (i > 0 && j > 0) {

            if (dp[i - 1][j] < dp[i][j] && dp[i][j - 1] < dp[i][j]) {
                stack.push(a[i]);
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j]) {
                j--;
            } else if (dp[i][j - 1] < dp[i][j]) {
                i--;
            } else if (dp[i][j - 1] == 0) {
                i--;
            } else {
                j--;
            }

        }

        PrintWriter writer = new PrintWriter(out);


        writer.println(dp[m][n]);

        while (!stack.isEmpty()) {
            writer.printf("%d ", stack.pop());
        }

        writer.close();
    }
}
