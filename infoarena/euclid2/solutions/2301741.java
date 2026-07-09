import java.io.*;

public class Main {
    private static final String INPUT_FILE_PATH = "euclid2.in";
    private static final String OUTPUT_FILE_PATH = "euclid2.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE_PATH));
        PrintWriter pw = new PrintWriter(OUTPUT_FILE_PATH);

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] tokens = br.readLine().split("\\s");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            pw.println(a);
        }
        pw.flush();
    }
}
