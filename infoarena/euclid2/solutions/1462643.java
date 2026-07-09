import java.io.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		FileReader in = new FileReader("euclid2.in");
		FileWriter out = new FileWriter("euclid2.out");
		Scanner sin = new Scanner(in);
		long T,a,b;
		T = sin.nextInt();
		while(T-- >0)
		{
			a = sin.nextLong();
			b = sin.nextLong();
			out.write(String.valueOf(cmmdc(a,b)));
			out.write("\n");
		}
		sin.close();
		in.close();
		out.close();
	}
	
	private static long cmmdc(long a, long b)
	{
		if(b==0)
			return a;
		return cmmdc(b,a%b);
	}

}
