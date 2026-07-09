
import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.Scanner;

public class One {
	private static int TESTS_COUNT;
	private static int[] a;
	private static int[] b;
	
	public static void main(String []args) {    
		readInput();
		
		for (int i = 0; i < TESTS_COUNT; i++) {
			System.out.println(computeSolution(a[i], b[i]));	
		}
	}

	private static int computeSolution(int one, int two) {
		return cmmdc(one, two);
	}

	private static int cmmdc(int one, int two) {
		if (two == 0) {
			return one;
		}
		
		return cmmdc(two, one % two);
	}

	private static void readInput() {
		Scanner s = null;
		
		try {
			URL url = One.class.getClassLoader().getResource("euclid2");
			s = new Scanner(new File(url.getPath()));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		TESTS_COUNT = s.nextInt();
		a = new int[TESTS_COUNT];
		b = new int[TESTS_COUNT];
		
		for (int i = 0; i < TESTS_COUNT; i++) {
			a[i] = s.nextInt();
			b[i] = s.nextInt();
		}
	}
}
