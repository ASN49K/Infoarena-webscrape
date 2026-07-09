import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    private static final String INPUT_FILE_PATH = "euclid2.in";
    private static final String OUTPUT_FILE_PATH = "euclid2.out";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new FileReader(INPUT_FILE_PATH));
        PrintWriter pw = new PrintWriter(OUTPUT_FILE_PATH);

        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
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
