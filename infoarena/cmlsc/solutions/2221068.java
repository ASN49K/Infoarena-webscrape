import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
	    short M, N, i, j;
	    short[] a;
	    short[] b;
	    String line;
        StringTokenizer st;

	    try {
            BufferedReader reader = new BufferedReader(new FileReader("cmlsc.in"));
            PrintWriter writer = new PrintWriter("cmlsc.out");
            line = reader.readLine();
            st = new StringTokenizer(line, " ");
            M = Short.parseShort(st.nextToken());
            N = Short.parseShort(st.nextToken());
            a = new short[M + 1];
            b = new short[N + 1];
            line = reader.readLine();
            st = new StringTokenizer(line, " ");
            for (i = 1; i <= M; i++) {
                a[i] = Short.parseShort(st.nextToken());
            }
            line = reader.readLine();
            st = new StringTokenizer(line, " ");
            for (i = 1; i <= N; i++) {
                b[i] = Short.parseShort(st.nextToken());
            }
            short[] common = new short[0];
            short[] cmlsc = new short[0];
            int length = common.length, MAX_LEN = 0;
            short k = 1;
            for (i = 1; i <= M; i++) {
                for (j = k; j <= N; j++) {
                    if (a[i] == b[j]) {
                        common = Arrays.copyOf(common, length + 1);
                        common[length] = a[i];
                        length++;
                        k = j;
                        i++;
                        continue;
                    }
                }
                if (length > MAX_LEN) {
                    cmlsc = Arrays.copyOf(common, length);
                    MAX_LEN = length;
                }
            }
            writer.write(String.valueOf(MAX_LEN));
            writer.write("\n");
            for (i = 0; i < MAX_LEN; i++) {
                writer.write(String.valueOf(cmlsc[i]) + ((i != MAX_LEN - 1) ? " " : ""));
            }
            reader.close();
            writer.close();
        } catch (Exception e) {

        }
    }
}
