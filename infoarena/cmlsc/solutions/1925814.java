import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Created by daniel1.macovei on 3/13/2017.
 */
public class Main {
    private static int n, m;
    private static String[] firstArray, secondArray;

    public static void main(String[] args) throws IOException {

        try (BufferedReader reader = new BufferedReader(new FileReader("cmlsc.in"))) {
            reader.readLine();
            firstArray = reader.readLine().split(" ");
            secondArray = reader.readLine().split(" ");
        }
        try (PrintWriter writer = new PrintWriter(new FileWriter("cmlsc.out"))) {
            writer.println(buildSolution(firstArray, secondArray));
        }
    }

    private static String buildSolution(String[] firstArray, String[] secondArray) {

        int[][] matrix = new int[firstArray.length + 1][secondArray.length + 1];

        for (int indexFirst = 1; indexFirst <= firstArray.length; indexFirst++)
            for (int indexSecond = 1; indexSecond <= secondArray.length; indexSecond++)
                matrix[indexFirst][indexSecond] = firstArray[indexFirst - 1].equals(secondArray[indexSecond - 1]) ?
                        matrix[indexFirst - 1][indexSecond - 1] + 1 :
                        Math.max(matrix[indexFirst - 1][indexSecond], matrix[indexFirst][indexSecond - 1]);

        Deque<String> result = new ArrayDeque<>();
        int indexFirst = firstArray.length, indexSecond = secondArray.length;
        while (indexFirst > 0 && indexSecond > 0) {
            if (firstArray[indexFirst - 1].equals(secondArray[indexSecond - 1])) {
                result.addFirst(firstArray[indexFirst - 1]);
                indexFirst--;
                indexSecond--;
            } else if (matrix[indexFirst][indexSecond] == matrix[indexFirst - 1][indexSecond]) indexFirst--;
            else indexSecond--;
        }

        StringBuilder response = new StringBuilder(matrix[firstArray.length][secondArray.length] + "\n");
        for (String value : result)
            response.append(value + " ");
        response = response.delete(response.length() - 1,response.length());
        return response.toString();
    }


}
