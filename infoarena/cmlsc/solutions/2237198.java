import static java.lang.Math.max;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static final String IN_FILE = "cmlsc.in";
  public static final String OUT_FILE = "cmlsc.out";

  public static int[] longestCommonSubsequence(final int[] a, final int[] b) {
    final int m = a.length;
    final int n = b.length;
    final int[][] dp = new int[m + 1][n + 1];
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] =
          a[i - 1] == b[j - 1]
          ? dp[i - 1][j - 1] + 1
          : max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    final List<Integer> sequence = new ArrayList<>();
    for (int i = m, j = n; i > 0 && j > 0; ) {
      if (a[i - 1] == b[j - 1]) {
        sequence.add(a[i - 1]);
        i--;
        j--;
      } else if (dp[i][j] == dp[i - 1][j]) {
        i--;
      } else {
        j--;
      }
    }
    Collections.reverse(sequence);
    return sequence.stream().mapToInt(Integer::intValue).toArray();
  }

  public static int[] readValues(final Scanner scanner, final int n) {
    final int[] values = new int[n];
    for (int i = 0; i < n; i++) {
      values[i] = scanner.nextInt();
    }
    return values;
  }

  public static void writeValues(final PrintWriter writer, final int[] values) {
    for (int i = 0; i < values.length; i++) {
      writer.print(values[i]);
      writer.print(i + 1 < values.length ? ' ' : '\n');
    }
  }

  public static void main(final String[] args) throws IOException {
    try (final Scanner scanner = new Scanner(new FileInputStream(IN_FILE));
        final PrintWriter writer = new PrintWriter(OUT_FILE)) {
      final int m = scanner.nextInt();
      final int n = scanner.nextInt();
      final int[] a = readValues(scanner, m);
      final int[] b = readValues(scanner, n);
      final int[] sequence = longestCommonSubsequence(a, b);
      writer.println(sequence.length);
      writeValues(writer, sequence);
    }
  }
}

