import java.*;
import java.io.File; 
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Files;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


import java.nio.file.Path;
import java.nio.file.Paths;
public class Main{

    public static final String IN_FILE = "euclid2.in";
	public static final String OUT_FILE = "euclid2.out";
    public static void main(String[] args) throws IOException {
        int n,a,b,r;
         try (
	        final Scanner sc = new Scanner(new FileInputStream(IN_FILE));
                 
	        final PrintStream writer = new PrintStream(OUT_FILE);
	    ) 
         { n=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            a=sc.nextInt();
            b=sc.nextInt();
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            writer.println(String.valueOf(a));
        }
         }
    }

}
