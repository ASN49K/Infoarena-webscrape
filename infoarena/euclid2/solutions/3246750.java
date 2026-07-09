import java.io.*;
import java.util.Scanner;

public class Main {

    private static final String INPUT_FILE_NAME = "euclid2.in";
    private static final String OUTPUT_FILE_NAME = "euclid2.out";

    private static TestOutput solveTest(TestInput input) {
        int x = input.x;
        int y = input.y;
        int r = x % y;

        while (r > 0) {
            x = y;
            y = r;
            r = x % y;
        }

        return new TestOutput(y);
    }

    public static void main(String[] args) throws Exception {
        try(InputReader inputReader = new InputReader(INPUT_FILE_NAME);
            OutputPrinter outputPrinter = new OutputPrinter(OUTPUT_FILE_NAME)) {
            int cntTests = inputReader.readCntTests();

            for (int testId = 0; testId < cntTests; testId++) {
                TestInput testInput = inputReader.readNextTextInput();
                TestOutput testOutput = solveTest(testInput);
                outputPrinter.writeTestOutput(testOutput);
            }
        }
    }

    private static class InputReader implements AutoCloseable {
        private final Scanner scanner;

        public InputReader(String filename) throws FileNotFoundException {
            scanner = new Scanner(new File(filename));
        }

        public int readCntTests() {
            return scanner.nextInt();
        }

        private TestInput readNextTextInput() {
            return new TestInput(scanner.nextInt(), scanner.nextInt());
        }

        @Override
        public void close() {
            scanner.close();
        }
    }

    private static class OutputPrinter implements AutoCloseable {
        private final BufferedWriter bufferedWriter;

        public OutputPrinter(String fileName) throws IOException {
            bufferedWriter = new BufferedWriter(new FileWriter(fileName));
        }

        public void writeTestOutput(TestOutput testOutput) throws IOException {
            bufferedWriter.write(String.valueOf(testOutput.getGCD()));
            bufferedWriter.newLine();
        }

        @Override
        public void close() throws Exception {
            bufferedWriter.flush();
            bufferedWriter.close();
        }
    }

    private static class TestInput {
        int x;
        int y;

        public TestInput(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private record TestOutput(int gcd) {

        public int getGCD() {
                return gcd;
            }
        }
}