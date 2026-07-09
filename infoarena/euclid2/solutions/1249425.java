import java.io.*;
import java.util.*;
 
public class Main {
	
	public static int gcd(int a, int b) {
		if(a%b == 0) return b;
		else return gcd(b, a%b);
	}
 
	public static void main(String[] args)throws IOException
	{
	    Scanner reader = new Scanner(new FileInputStream("euclid2.in"));
	    PrintWriter writer = new PrintWriter("euclid2.out");
	    
	    int T = reader.nextInt();
	    while((T--) > 0) {
	    	int a = reader.nextInt();
		    int b = reader.nextInt();
		    int aux = gcd(a, b);
		    writer.write(String.valueOf(aux) + "\n");
	    }
	    
	    writer.close();
	    reader.close();
	}
 
}
