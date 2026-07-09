/**
 * Created by Alex.Kerezsi on 1/28/2019.
 */

import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    private static long tempA;
    private static long tempB;

    private static long euclid(long a, long b){
        tempA = a;
        tempB = b;

        if(a == 0)
            return a;

        if(b == 0)
            return b;

        while(tempA != tempB) {
            if (tempA > tempB)
            {
                tempA = tempA - tempB;
            } else if(tempA < tempB)
            {
                tempB = tempB - tempA;
            }
        }

        return tempA;
    };

    private static long a;
    private static long b;
    private static long result;

    public static void main(String[] args){
        try {
            final Scanner bufferR = new Scanner(new FileInputStream("euclid2.in"));

            final PrintStream bufferW = new PrintStream("euclid2.out");

            int n = bufferR.nextInt();
            for(int i=0; i < n; i++) {
                a = bufferR.nextLong();
                b = bufferR.nextLong();

                result = euclid(a,b);

                bufferW.println(result);
            }

            bufferW.close();
            bufferR.close();
        } catch (Exception e) {
        }
    }
}
