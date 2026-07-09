import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * Created by Ada on 7/24/2016.
 */
public class Cmlsc {

    public static void main(String[] argv) {
        Integer n, m;
        Integer[] a, b;
        Integer i, j;

        //read file
        try {
            File file = new File("cmlsc.in");
            Scanner scanner = new Scanner(file);
            n = scanner.nextInt();
            m = scanner.nextInt();
            a = new Integer[n + 1];
            b = new Integer[m + 1];
            for (i = 1; i <= n; i++) {
                a[i] = scanner.nextInt();
            }
            for (j = 1; j <= m; j++) {
                b[j] = scanner.nextInt();
            }
            scanner.close();
        } catch (Exception exception) {
            System.out.println("Exception reading file: " + exception.getMessage());
            return;
        }

        //build matrix
        Integer[][] s = new Integer[n + 1][m + 1];
        for (i = 0; i <= n; i++) {
            s[i][0] = 0;
        }
        for (j = 0; j <= m; j++) {
            s[0][j] = 0;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (a[i].equals(b[j])) {
                    s[i][j] = s[i - 1][j - 1] + 1;
                } else {
                    s[i][j] = (s[i - 1][j] > s[i][j - 1]) ? s[i - 1][j] : s[i][j - 1];
                }
            }
        }
        i = n;
        j = m;
        Integer[] solution = new Integer[s[n][m] + 1];
        Integer k = s[n][m];
        while ((i > 0) && (j > 0)) {
            if (a[i].equals(b[j])) {
                solution[k--] = a[i];
                i--;
                j--;
            } else {
                if (s[i - 1][j] > s[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        //write output file
        try {
            FileWriter fileWriter = new FileWriter("cmlsc.out");
            fileWriter.write(s[n][m] + "\n");
            for (k = 1; k <= s[n][m]; k++) {
                fileWriter.write(solution[k] + " ");
            }
            fileWriter.write("\n");
            fileWriter.close();
        } catch (Exception exception) {
            System.out.println("Exception writing file: " + exception.getMessage());
        }
    }
}
