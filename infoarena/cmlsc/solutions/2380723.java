import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        File in = new File("cmlsc.in");
        File out = new File("cmlsc.out");

        FileReader fileReader = new FileReader(in);
        BufferedReader bufferedReader = new BufferedReader(fileReader);

        int i, j;
        int m = 0;
        int n = 0;
        String line;


        if ((line = bufferedReader.readLine()) != null) {

            String[] strs = line.trim().split("\\s+");
            m = Integer.parseInt(strs[0]);
            n = Integer.parseInt(strs[1]);
        }


        int[] a = new int[m + 1];
        int[] b = new int[n + 1];
        int[][] dp = new int[m + 1][n + 1];


        if ((line = bufferedReader.readLine()) != null) {

            String[] strs = line.trim().split("\\s+");
            for (i = 1; i <= m; i++) {
                a[i] = Integer.parseInt(strs[i - 1]);
                dp[i - 1][0] = 0;
            }
        }

        if ((line = bufferedReader.readLine()) != null) {

            String[] strs = line.trim().split("\\s+");
            for (i = 1; i <= n; i++) {
                b[i] = Integer.parseInt(strs[i - 1]);
                dp[0][i - 1] = 0;
            }
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
