import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        FileReader in = new FileReader("euclid2.in");
        FileWriter out = new FileWriter("euclid2.out");
        Scanner sin = new Scanner(in);
        Integer T=0,a,b;
        T = sin.nextInt();
        while(T > 0)
        {
            a = sin.nextInt();
            b = sin.nextInt();
            out.write(String.valueOf(cmmdc(a,b)));
            out.write("\n");
            T--;
        }
        sin.close();
        in.close();
        out.close();
    }

    private static int cmmdc(int a, int b)
    {
        if(b==0)
            return a;
        return cmmdc(b,a%b);
    }

}