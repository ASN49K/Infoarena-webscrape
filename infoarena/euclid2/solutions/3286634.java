
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static final String inFile = "euclid2.in";
    public static final String outFile = "euclid2.out";

    public static void main(String[] args) throws IOException {

        try (final Scanner readFile = new Scanner(new FileInputStream(inFile));
             final PrintStream writeFile = new PrintStream(outFile)) {
            int firstNum, secondNum, rem = 0;

            int n = readFile.nextInt();
            for(int i=0; i<n; i++){
                firstNum = readFile.nextInt();
                secondNum = readFile.nextInt();
                while(secondNum != 0){
                    rem = firstNum % secondNum;
                    firstNum = secondNum;
                    secondNum = rem;
                }
                writeFile.println(firstNum);
            }
            readFile.close();
            writeFile.close();
        }
    }
}