import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

class Main {
	public static void handleError(Exception e) {
		System.out.println("OSHIT!");
		e.printStackTrace();
	}

	static long euclidRec(long a, long b) {
		if (a == b) {
			return a;
		} else {
			long small = Math.min(a, b);
			long big = Math.max(a, b);

			return euclidRec(big - small, small);
		}
	}

	public static void main(String[] args)
	{
		try {
			Scanner scanner = new Scanner(new File("euclid2.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter("euclid2.out"));

			//---

			int T;
			long a, b;

			T = scanner.nextInt();

			for (int i = 0; i < T; ++i) {
				a = scanner.nextInt();
				b = scanner.nextInt();

				writer.write(String.valueOf(euclidRec(a, b)));
				writer.newLine();
			}

			//---

			scanner.close();
			writer.close();
		} catch (FileNotFoundException e) {
			Main.handleError(e);
		} catch (IOException e) {
			Main.handleError(e);
		}
	}
}