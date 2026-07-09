package main;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class Euclid2 {

    private static int CMMDC(int a, int b) {
        return (b == 0) ? a : CMMDC(b, a % b);
    }

    public static void main(String[] args) throws Exception {
        String InPut = "src/euclid2.in";
        String OutPut = "src/euclid2.out";
        Scanner fin = new Scanner(new File(InPut));
        BufferedWriter fout = new BufferedWriter(new FileWriter(OutPut));
        int T = fin.nextInt();
        while (T-- > 0) {
            int a = fin.nextInt();
            int b = fin.nextInt();
            fout.write(Integer.toString(CMMDC(a, b)));
            fout.write("\n");
        }
        fin.close();
        fout.close();
    }
}
