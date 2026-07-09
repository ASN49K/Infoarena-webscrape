package edu.infoarena;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream("euclid2.in")));
        String firstLine = bufferedReader.readLine();

        int numberOfPairs = Integer.parseInt(firstLine.trim());

        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("euclid2.out")), numberOfPairs * 4);

        String line;

        while ((line = bufferedReader.readLine()) != null) {
            Pair pair = new Pair(line);
            bufferedWriter.write(String.valueOf(getGreatestCommonDivisor(pair.getFirstNumber(), pair.getSecondNumber())));
            bufferedWriter.newLine();
        }

        bufferedWriter.flush();
    }

    static class Pair {
        private final int firstNumber;
        private final int secondNumber;

        Pair(String lineContainingTwoNumbers) {
            String[] inputNumbers = lineContainingTwoNumbers.split("[^0-9]");
            if (inputNumbers.length < 2 ) {
                throw new RuntimeException("input line should contain two numbers, the actual input : " + lineContainingTwoNumbers);
            }
            this.firstNumber = Integer.parseInt(inputNumbers[0]);
            this.secondNumber = Integer.parseInt(inputNumbers[1]);
        }

        public int getFirstNumber() {
            return firstNumber;
        }

        public int getSecondNumber() {
            return secondNumber;
        }
    }

    static int getGreatestCommonDivisor(int firstNumber, int secondNumber) {
        if (secondNumber == 0) {
            return firstNumber;
        }
        return getGreatestCommonDivisor(secondNumber, firstNumber % secondNumber);
    }

}
