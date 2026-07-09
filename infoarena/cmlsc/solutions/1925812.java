import java.io.*;

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

        StringBuilder response = new StringBuilder(matrix[firstArray.length][secondArray.length] + "\n");
        addRoute(matrix, firstArray.length, secondArray.length, response);
        response.delete(response.length() - 1, response.length());
        return response.toString();
    }

    private static void addRoute(int[][] matrix, int i, int j, StringBuilder response) {
        if (i <= 0 || j <= 0)
            return;
        if (firstArray[i - 1].equals(secondArray[j - 1])) {
            response.append(firstArray[i - 1] + " ");
            addRoute(matrix, i - 1, j - 1, response);
        } else if (matrix[i - 1][j] < matrix[i][j - 1])
            addRoute(matrix, i, j - 1, response);
        else
            addRoute(matrix, i - 1, j, response);
    }

}
