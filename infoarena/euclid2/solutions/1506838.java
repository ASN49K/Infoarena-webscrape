import java.io.*;
import java.util.Scanner;
public class Main {
	public static void main(String []args) throws IOException
	{
		Scanner in = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter out = new PrintWriter("euclid2.out");
		int t = in.nextInt();
		while(t-- > 0)
			out.write(String.valueOf(gcd(in.nextInt(),in.nextInt()))+"\n");
		out.close();
		in.close();
	}
	public static int gcd(int a,int b)
	{
		int r;
		while(b!=0)
		{
			r = a%b;
			a  = b;
			b = r;
		}
		return a;
	}
}
