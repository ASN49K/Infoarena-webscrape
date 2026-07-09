//package InfoArena;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class AlgEuclid {

    public static int cmmdc(int a, int b)
    {
        while(a != b)
        {
            if(a > b)
                a -= b;
            else
                b -= a;
        }

        return a;
    }

    public static void main(String[] args) throws IOException
    {

        File file = new File("euclid2.in");
        FileOutputStream file_output = new FileOutputStream("euclid2.out");
        PrintWriter pw = new PrintWriter(file_output);
        Scanner sc = new Scanner(file);
        int n = sc.nextInt(); int a, b, result;

        System.out.println();

        while(n-- > 0)
        {
            a = sc.nextInt(); b = sc.nextInt();
            result = cmmdc(a, b);
            String str = new String();

            pw.println(result);
        }

        pw.close();
    }
}
