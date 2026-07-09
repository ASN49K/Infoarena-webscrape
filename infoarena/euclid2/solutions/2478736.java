
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main{

    public static final String IN_FILE = "euclid2.in";
	public static final String OUT_FILE = "euclid2.out";
    public static void main(String[] args) throws IOException {
        int n,a,b,r;
         
	        final Scanner sc = new Scanner(new FileInputStream(IN_FILE));
                 
	        final PrintStream writer = new PrintStream(OUT_FILE);
	  
         n=sc.nextInt();
        while(n>0)
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
            n-=1;
        }
         
    }

}
