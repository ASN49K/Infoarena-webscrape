import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        File inputFile = new File("euclid2.in");
        Scanner fileScanner = new Scanner(inputFile);
        FileWriter fileWriter = new FileWriter("euclid2.out");
        int numberOfTests = Integer.parseInt(fileScanner.nextLine());
        for (int i = 0; i < numberOfTests; i++) {
            String[] lineInput = fileScanner.nextLine().split(" ");
            int firstNumber = Integer.parseInt(lineInput[0]);
            int secondNumber = Integer.parseInt(lineInput[1]);
            if (firstNumber < secondNumber) {
                int aux = firstNumber;
                firstNumber = secondNumber;
                secondNumber = aux;
            }

            fileWriter.write(gcd(firstNumber, secondNumber)+ "\n");
        }

        fileScanner.close();
        fileWriter.close();
    }

    private static int gcd(int firstNumber, int secondNumber) {
        return secondNumber == 0 ? firstNumber : gcd(secondNumber, firstNumber % secondNumber);
    }
}