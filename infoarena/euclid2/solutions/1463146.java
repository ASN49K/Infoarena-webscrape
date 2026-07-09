
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
 
	public static void main(String[] args) throws IOException {
		Scanner reader = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter writer = new PrintWriter("euclid2.out");
		reader.nextInt();
		int a = 0;
		int b = 0;
		while (reader.hasNext()) {
			a = reader.nextInt();
			b = reader.nextInt();
			writer.write(String.valueOf(gcd(a, b)) + "\n");
		}
		reader.close();
		writer.close();

	}
}
