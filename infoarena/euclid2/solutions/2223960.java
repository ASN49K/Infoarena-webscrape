import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStream inputStream = new FileInputStream("euclid2.in");
        OutputStream outputStream = new FileOutputStream("euclid2.out");

        try (InputReader inputReader = new InputReader(inputStream);
             PrintWriter printWriter = new PrintWriter(outputStream)) {
            new Solver(inputReader, printWriter).solve();
        }
    }

    static class Solver {

        private InputReader inputReader;
        private PrintWriter printWriter;

        public Solver(InputReader inputReader, PrintWriter printWriter) {
            this.inputReader = inputReader;
            this.printWriter = printWriter;
        }

        public void solve() {
            int N = inputReader.nextInt();
            for (int test = 0; test < N; test++) {
                int firstNo = inputReader.nextInt();
                int secondNo = inputReader.nextInt();

                printWriter.println(gcd(firstNo, secondNo));
            }
        }

        private static int gcd(int a, int b) {
            if (b == 0) {
                return a;
            }

            return gcd(b, a % b);
        }
    }

    static class InputReader implements AutoCloseable {

        private BufferedReader bufferedReader;

        private StringTokenizer stringTokenizer;

        public InputReader(InputStream inputStream) {
            this.bufferedReader = new BufferedReader(new InputStreamReader(inputStream), 1 << 16);
            this.stringTokenizer = null;
        }

        private String next() {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                try {
                    stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return stringTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public void close() throws IOException {
            bufferedReader.close();
        }
    }
}