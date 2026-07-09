import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
public class Main {
	public static int gcd(int a, int b) {
		while (a!=b)
		{
			if (a > b) {
				a-=b;
			}
			else {
				b-=a;
			}
		}
		return a;
	}
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("euclid2.in"));
		PrintWriter pw = new PrintWriter("euclid2.out");
		int a, b;
		in.nextInt();
		while(in.hasNextInt()) {
			a = in.nextInt();
			b = in.nextInt();
			pw.println(gcd(a, b));
		}
		pw.close();
		in.close();
	}

}
