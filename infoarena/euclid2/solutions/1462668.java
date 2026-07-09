import java.io.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		FileInputStream in = new FileInputStream("euclid2.in");
		Scanner sin = new Scanner(in);
		FileOutputStream out = new FileOutputStream("euclid2.out");
		int T,a,b;
		T = sin.nextInt();
		while(T-- >0)
		{
			a = sin.nextInt();
			b = sin.nextInt();
			out.write(cmmdc(a,b));
			out.write('\n');
		}
		sin.close();
		out.close();
	}
	
	private static int cmmdc(int a, int b)
	{
		if(b==0)
			return a;
		return cmmdc(b,a%b);
	}

}
