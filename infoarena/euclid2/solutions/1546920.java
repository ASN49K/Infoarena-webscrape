

import java.io.*;
import java.util.*;

public class Main {

   
    public static int cmmdc(int x, int y)
    {
        if (y > 0)
            return cmmdc(y, x%y);
        else
            return x;
    }
    
    public static void main(String[] argv) throws IOException{
        Scanner fin = new Scanner(new FileInputStream("cmmdc.in"));
        PrintStream fout = new PrintStream("cmmdc.out");
        
        
        int x, y, n, i, z;
        n = fin.nextInt();
        for (i = 1; i <= n; i++)
        {
            x = fin.nextInt();
            y = fin.nextInt();
            z = cmmdc(x, y);
            fout.println(z);
        }
    }
    
}
