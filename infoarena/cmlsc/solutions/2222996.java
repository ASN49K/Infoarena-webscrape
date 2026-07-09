import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
	    int M;
        int N;
        int i;
        int j;
        int[] a;
	    int[] b;
	    int[][] c;
	    String line;
        StringTokenizer st;

	    try {
            BufferedReader reader = new BufferedReader(new FileReader("cmlsc.in"));
            PrintWriter writer = new PrintWriter("cmlsc.out");
            line = reader.readLine();
            st = new StringTokenizer(line, " ");
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            a = new int[M + 1];
            b = new int[N + 1];
            c = new int[M + 1][N + 1];
            line = reader.readLine();
            st = new StringTokenizer(line, " ");
            for (i = 1; i <= M; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            line = reader.readLine();
            st = new StringTokenizer(line, " ");
            for (i = 1; i <= N; i++) {
                b[i] = Integer.parseInt(st.nextToken());
            }
            for (i = 1; i <= M; i++) {
                for (j = 1; j <= N; j++) {
                    if (a[i] == b[j]) {
                        c[i][j] = 1 + c[i-1][j-1];
                    }
                    if (c[i-1][j] > c[i][j]) {
                        c[i][j] = c[i-1][j];
                    }
                    if (c[i][j-1] > c[i][j]) {
                        c[i][j] = c[i][j-1];
                    }
                }
            }

            int[] common;

            writer.write(String.valueOf(c[M][N]));
            writer.write("\n");
            common = new int[c[M][N] + 1];
            i = M;
            j = N;
            int k = 0;
            while (i != 0) {
                if (a[i] == b[j]) {
                    common[++k] = a[i];
                    --i;
                    --j;
                } else if (c[i-1][j]<c[i][j-1]) {
                    --j;
                } else {
                    --i;
                }
            }
            for (i = k; i > 0; i--) {
                writer.write(common[i] + ((i == 1) ? "" : " "));
            }
            reader.close();
            writer.close();
        } catch (Exception e) {

        }
    }
}
