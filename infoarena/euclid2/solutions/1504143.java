//package training.one;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Euclid2 {
	private static int TESTS_COUNT;
	private static int[] a;
	private static int[] b;
	
	private static int[] result;
	
	public static void main(String []args) {    
		readInput();
		
		for (int i = 0; i < TESTS_COUNT; i++) {
			result[i] = computeSolution(a[i], b[i]);
		}
		
		writeResults();
	}

	private static void writeResults() {
//		URL url = Euclid2.class.getClassLoader().getResource("euclid2.out");
//		String path = url.getPath();

		String path = "euclid2.out";
		FileWriter fw = null;
		
		try {
			fw = new FileWriter(path);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		for (int i : result) {
			try {
				fw.write(i + "\n");
//				System.out.println("writing " + i);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		try {
			fw.flush();
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
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
//			URL url = Euclid2.class.getClassLoader().getResource("euclid2.in");
//			String path = url.getPath();

			String path = "euclid2.in";
			s = new Scanner(new File(path));
		} catch (FileNotFoundException e) {
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
	}
}
