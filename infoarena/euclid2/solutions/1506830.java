import java.io.*;
import java.util.Scanner;
public class Main {
	public static void main(String []args) throws IOException
	{
		Scanner in = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter out = new PrintWriter("euclid2.out");
		int t = in.nextInt();
		while(t-- > 0){
			out.write(String.valueOf(gcd(in.nextInt(),in.nextInt())));
			out.write("\n");
		}
		out.close();
		in.close();
	}
	public static int gcd(int a,int b)
	{
		if(b==0)
			return a;
		return gcd(b,a%b);
	}
}
