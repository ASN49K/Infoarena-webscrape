import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStream inputStream = new FileInputStream("cmslc.in");
        OutputStream outputStream = new FileOutputStream("cmlsc.out");

        try (InputReader inputReader = new InputReader(inputStream);
            PrintWriter printWriter = new PrintWriter(outputStream)) {
            new Solver(inputReader, printWriter).solve();
        }
    }

    static class Solver {

        private InputReader inputReader;

        private PrintWriter printWriter;

        private int N, M;

        private int[] firstSeq;

        private int[] secondSeq;

        private int[][] bestMatch;

        public Solver(InputReader inputReader, PrintWriter printWriter) {
            this.inputReader = inputReader;
            this.printWriter = printWriter;
        }

        private void read() {
            N = inputReader.nextInt();
            M = inputReader.nextInt();
            firstSeq = new int[N + 1];
            secondSeq = new int[M + 1];

            for (int i = 1; i <= N; i++) {
                firstSeq[i] = inputReader.nextInt();
            }

            for (int i = 1; i <= M; i++) {
                secondSeq[i] = inputReader.nextInt();
            }
        }

        private void recons(int N, int M, int rem) {
            if (rem == 0) {
                return;
            }

            if (firstSeq[N] == secondSeq[M]) {
                recons(N - 1, M - 1, rem - 1);

                printWriter.print(firstSeq[N]);
                if (rem > 0) {
                    printWriter.print(" ");
                }

                return ;
            }

            if (bestMatch[N - 1][M] > bestMatch[N][M - 1]) {
                recons(N - 1, M, rem);
            } else {
                recons(N, M - 1, rem);
            }
        }

        public void solve() {
            read();

            bestMatch = new int[N + 1][M + 1];
            for (int i = 0; i <= N; i++) {
                Arrays.fill(bestMatch[i], 0);
            }

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (firstSeq[i] == secondSeq[j]) {
                        bestMatch[i][j] = bestMatch[i - 1][j - 1] + 1;
                    } else {
                        bestMatch[i][j] = Math.max(bestMatch[i - 1][j], bestMatch[i][j - 1]);
                    }
                }
            }

            printWriter.println(bestMatch[N][M]);

            recons(N, M, bestMatch[N][M]);
            printWriter.println();
        }
    }

    static class InputReader implements AutoCloseable {

        private BufferedReader bufferedReader;

        private StringTokenizer stringTokenizer;

        public InputReader(InputStream inputStream) {
            bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            stringTokenizer = null;
        }

        private String nextToken() {
            if (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                try {
                    stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return stringTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        @Override
        public void close() throws IOException {
            bufferedReader.close();
        }
    }
}
