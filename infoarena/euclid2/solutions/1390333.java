/**
 * @(#)Euclid.java
 *
 *
 * @author 
 * @version 1.00 2015/3/16
 */
import java.util.*;
import java.io.*;

class Euclid2 {
        
    /**
     * Creates a new instance of <code>Euclid</code>.
     */
    public Euclid2() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {
     	Scanner scan = new Scanner(new File("euclid2.in"));
     	PrintWriter out = new PrintWriter("euclid2.out");
     	
     	int n = scan.nextInt();
     	for( int i = 0; i < n; i++ )
     	{
     		int a = scan.nextInt();
     		int b = scan.nextInt();
     		out.println(gcd(a, b));
     	}
     	
     	out.close();
    }
    
    public static int gcd(int a , int b)
    {
    	if( b == 0 )
    		return a;
    	
    	return gcd(b, a%b);
    }
}
