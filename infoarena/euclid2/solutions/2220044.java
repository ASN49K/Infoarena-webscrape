import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.PrintWriter;

public class EuclidAlgorithm {

	public static void main(String[] args) {
		GCD temp = new GCD();
		temp.solve();
	}
}

class GCD {

		private int[][] array = null;

		public GCD() { readFromFile(); }

		private void readFromFile() {
			try {
				Scanner scanner = new Scanner(new File("euclid2.in"));
				boolean first = true;
				int idx = 0;
				while (scanner.hasNext()) {
					if (first) {
						array = new int[Integer.parseInt(scanner.next())][2];
					} else {
						array[idx][0] = Integer.parseInt(scanner.next());
						array[idx][1] = Integer.parseInt(scanner.next());
						idx++;
					}
					first = false;
				}
				scanner.close();
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		private void writeToFile() {
			try {
				PrintWriter writer = new PrintWriter("euclid2.out");
				for (int[] pair : array) {
					writer.println(getValues(pair[0], pair[1]));
				}
				writer.close();
			} catch (FileNotFoundException e) { e.printStackTrace(); }
		}

		public void solve() {
			if (array == null) { return; }
			writeToFile();
		}

		private int getValues(int left, int right) {
			return left > right ? gcd(left, right) : gcd(right, left);
		}

		private int gcd(int big, int small) {
			int remainder = big % small;	
			while (remainder > 0) {
				big = small;
				small = remainder;
				remainder = big % small;
			}
			return small;
		}
	}
