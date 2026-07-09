import java.io.*;
import java.util.*;

public class Main {
	private static final String INPUT_FILE_PATH = "euclid2.in";
	private static final String OUTPUT_FILE_PATH = "euclid2.out";

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader(INPUT_FILE_PATH));
		PrintWriter out = new PrintWriter(OUTPUT_FILE_PATH);
		int t = in.nextInt();
		while (t-- > 0) {
			int a = in.nextInt();
			int b = in.nextInt();
			out.println(gcd(a, b));
		}
		in.close();
		out.close();
	}

	private static int gcd(int a, int b) {
		return (a == 0) ? b : gcd(b % a, a);
	}

}
