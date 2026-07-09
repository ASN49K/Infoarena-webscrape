import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {
	private static final String IN = "euclid2.in";
	private static final String OUT = "euclid2.out";
	
	private static int TESTS_COUNT;
	private static int[] a;
	private static int[] b;
	private static int[] result;
	
	public static void main(String[] args) {
		readInput();
		
		computeSolution();
		
		displaySolution();
	}
	
	private static void computeSolution() {
		for (int i = 0; i < TESTS_COUNT; i++) {
			result[i] = gcd(a[i], b[i]);
		}
	}
	
	private static int gcd(int one, int two) {
		if (two == 0) {
			return one;
		}
		
		return gcd(two, one % two);
	}
	
	private static void displaySolution() {
		FileWriter out = null;
		
		try {
			out = new FileWriter(OUT);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		for (int i = 0; i < TESTS_COUNT; i++) {
			try {
				out.write(result[i] + "\n");
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		try {
			out.close();			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static void readInput() {
		Scanner s = null;
		
		try {
			s = new Scanner(new File(IN));			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		TESTS_COUNT = s.nextInt();
		a = new int[TESTS_COUNT];
		b = new int[TESTS_COUNT];
		result = new int[TESTS_COUNT];
		
		for (int i = 0; i < TESTS_COUNT; i++) {
			a[i] = s.nextInt();
			b[i] = s.nextInt();
		}
		
		s.close();
	}
}