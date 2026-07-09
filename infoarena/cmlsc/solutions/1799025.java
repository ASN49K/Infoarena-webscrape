import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int M = in.nextInt();
        int N = in.nextInt();
        int[] a = new int[M + 1];
        int[] b = new int[N + 1];
        for (int i = 1; i <= M; i++) a[i] = in.nextInt();
        for (int i = 1; i <= N; i++) b[i] = in.nextInt();

        int[][] dp = new int[M + 1][N + 1];

        for (int i = 0; i <= N; i++) dp[0][i] = 0;
        for (int i = 0; i <= M; i++) dp[i][0] = 0;

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int[] fn = new int[dp[M][N]];
        int index = fn.length;
        int k = M, q = N;

        while (k > 0 && q > 0) {
            if (a[k] == b[q]) {
                fn[--index] = a[k];
                k--; q--;
            } else if (dp[k - 1][q] < dp[k][q - 1]) q--;
            else k--;
        }

        for (int i = 0; i < fn.length; i++) out.print(fn[i] + " ");
        out.println();
    }

    void run() {
        try {
            in = new FastScanner(new File("cmlsc.in"));
            out = new PrintWriter(new File("cmlsc.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public FastScanner(File f) {
            try {
                reader = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}
