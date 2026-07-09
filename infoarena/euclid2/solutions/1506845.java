import java.io.*;
import java.util.Scanner;
public class Main {
	public static void main(String []args) throws IOException
	{
		Scanner in = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter out = new PrintWriter("euclid2.out");
		int t = in.nextInt(), r,a, b;
		while(t-- > 0){
			a = in.nextInt();
			b = in.nextInt();
			while(b!=0)
			{
				r = a%b;
				a  = b;
				b = r;
			}
			out.write(String.valueOf(a)+"\n");
		}
		out.close();
		in.close();
	}
}
