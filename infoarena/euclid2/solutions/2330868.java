/**
 * Created by Alex.Kerezsi on 1/28/2019.
 */

import java.io.*;
import java.util.Scanner;

public class Main {
    private static long euclid(long a, long b){
        long tempA = a;
        long tempB = b;

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

    public static void main(String[] args) throws IOException{
        try {
            Scanner bufferR = new Scanner(new FileReader("euclid2.in"));

            BufferedWriter bufferW = new BufferedWriter(new FileWriter("euclid2.out"));

            int n = bufferR.nextInt();
            for(int i=0; i < n; i++) {
                long a = bufferR.nextLong();
                long b = bufferR.nextLong();

                long result = euclid(a,b);

                bufferW.write(result + "\n");
            }

            bufferW.close();
            bufferR.close();
        } catch (IOException e) {
            e.printStackTrace();
        } ;
    }
}
