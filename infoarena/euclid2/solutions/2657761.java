import java.io.*;
import java.util.StringTokenizer;

public class Main{
	public static void main(String []args) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("euclid2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("euclid2.out")));
			int test = Integer.parseInt(br.readLine());
			for(int tc=1;tc<=test; tc++)
			{
				StringTokenizer st = new StringTokenizer(br.readLine());
				long a = Long.parseLong(st.nextToken());
				long b = Long.parseLong(st.nextToken());
				long res = gcd(a,b);
				out.println(res);
			}
		out.flush();
	}
	private static long gcd(long a, long b)
	{
		if(b==0)
			return a;
		else
			return gcd(b,a%b);
	}
}