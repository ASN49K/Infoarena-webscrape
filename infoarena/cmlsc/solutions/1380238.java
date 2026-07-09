import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Determines the longest common subsequence of two sequences.
 *
 * @author Andrei Muntean
 */
public class LongestCommonSubsequence
{
    private static int[] firstSequence;
    private static int[] secondSequence;

    // dp[i][j] = the size of the longest common subsequence up to the i-th element of
    // firstSequence and the j-th element of secondSequence.
    // The name "dp" derives from the concept used to calculate it: dynamic programming.
    private static int[][] dp;

    private static void read(String path) throws IOException
    {
        try (Scanner scanner = new Scanner(new File(path)))
        {
            // One-based indexing.
            firstSequence = new int[scanner.nextInt() + 1];
            secondSequence = new int[scanner.nextInt() + 1];

            for (int index = 1; index < firstSequence.length; ++index)
            {
                firstSequence[index] = scanner.nextInt();
            }

            for (int index = 1; index < secondSequence.length; ++index)
            {
                secondSequence[index] = scanner.nextInt();
            }

            // The first sequence must never be smaller than the second one.
            if (firstSequence.length < secondSequence.length)
            {
                int[] temp = firstSequence;

                firstSequence = secondSequence;
                secondSequence = temp;
            }
        }
    }

    private static void computeCommonSubsequenceLengths()
    {
        dp = new int[firstSequence.length][secondSequence.length];

        // i = the current index of the first sequence.
        for (int i = 1; i < firstSequence.length; ++i)
        {
            // j = the current index of the second sequence.
            for (int j = 1; j < secondSequence.length; ++j)
            {
                if (firstSequence[i] == secondSequence[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    private static void write(String path) throws IOException
    {
        try (PrintWriter printWriter = new PrintWriter(new FileWriter(path)))
        {
            // Outputs the length of the longest common subsequence.
            printWriter.println(dp[dp.length - 1][dp[0].length - 1]);

            // Outputs the longest common subsequence.
            for (int requiredMax = 1, j = 1; j < dp[0].length; ++j)
            {
                for (int i = dp.length - 1; i > 0; --i)
                {
                    // Determines whether this is the last occurence of the maximum
                    // value on this column.
                    if (dp[i - 1][j] < dp[i][j])
                    {
                        if (dp[i][j] == requiredMax)
                        {
                            printWriter.printf("%d ", firstSequence[i]);
                            ++requiredMax;
                        }

                        break;
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException
    {
        // Opens the file "cmlsc.in" by default.
        read(args != null && args.length > 0 ? args[0] : "cmlsc.in");
        computeCommonSubsequenceLengths();
        write(args != null && args.length > 1 ? args[1] : "cmlsc.out");
    }
}