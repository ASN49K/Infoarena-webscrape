package com.alexpana.infoarena;

import java.io.*;
import java.util.Scanner;

public class Cmlsc {

    static class Input {
        final int[] first;
        final int[] second;

        Input(int[] first, int[] second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Output {
        final int[] output;

        private Output(int[] output) {
            this.output = output;
        }
    }

    private static Input read() throws FileNotFoundException {
        Scanner sc = new Scanner(new BufferedReader(new FileReader("cmlsc.in")));

        int lengthA = sc.nextInt();
        int lengthB = sc.nextInt();

        int[] arrayA = new int[lengthA];
        int[] arrayB = new int[lengthB];

        for (int i = 0; i < lengthA; ++i) {
            arrayA[i] = sc.nextInt();
        }

        for (int i = 0; i < lengthB; ++i) {
            arrayB[i] = sc.nextInt();
        }
        return new Input(arrayA, arrayB);
    }

    private static void write(Output output) throws IOException {
        FileWriter fileWriter = new FileWriter("cmlsc.out");
        Writer writer = new BufferedWriter(fileWriter);
        writer.write("" + output.output.length);
        writer.write("\n");
        for (int value : output.output) {
            writer.write("" + value);
            writer.write(" " );
        }
        writer.flush();
        writer.close();
    }

    public static Output solve(Input input) {
        int[][] sub = new int[input.first.length+1][input.second.length+1];

        for (int i = 1; i < input.first.length + 1; ++i) {
            for (int j = 1; j < input.second.length + 1; ++j) {
                if (input.first[i-1] == input.second[j-1]) {
                    sub[i][j] = sub[i-1][j-1] + 1;
                } else {
                    sub[i][j] = Math.max(sub[i-1][j], sub[i][j-1]);
                }
            }
        }

        int[] result = new int[sub[input.first.length][input.second.length]];
        int i = input.first.length;
        int j = input.second.length;
        int n = sub[input.first.length][input.second.length] - 1;
        while (j > 0 && i > 0) {
            if (input.first[i-1] == input.second[j-1]) {
                result[n--] = input.first[i-1];
                i -= 1;
                j -= 1;
            } else if (sub[i-1][j] < sub[i][j-1]) {
                j -= 1;
            } else {
                i -= 1;
            }
        }

        return new Output(result);
    }

    public static void main(String[] args) throws IOException {
        write(solve(read()));
    }
}
