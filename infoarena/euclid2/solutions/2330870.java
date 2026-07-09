/**
 * Created by Alex.Kerezsi on 1/28/2019.
 */

import java.io.*;
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

        while(tempA != tempB && tempA != 0 && tempB != 0) {
            if (tempA > tempB)
            {
                tempA = tempA - tempB;

                continue;
            }

            if(tempA < tempB)
            {
                tempB = tempB - tempA;

                continue;
            }
        }

        return tempA;
    };

    private static long a;
    private static long b;
    private static long result;

    public static void main(String[] args) throws IOException{
        try {
            Scanner bufferR = new Scanner(new FileReader("euclid2.in"));

            BufferedWriter bufferW = new BufferedWriter(new FileWriter("euclid2.out"));

            int n = bufferR.nextInt();
            for(int i=0; i < n; i++) {
                a = bufferR.nextLong();
                b = bufferR.nextLong();

                result = euclid(a,b);

                bufferW.write(result + "\n");
            }

            bufferW.close();
            bufferR.close();
        } catch (IOException e) {
            e.printStackTrace();
        } ;
    }
}
