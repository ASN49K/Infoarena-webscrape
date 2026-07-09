import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner reader = new Scanner(new FileInputStream("cmlsc.in"));
		int lengthA = reader.nextInt();
		int lengthB = reader.nextInt();
		int[] a = new int[lengthA];
		int[] b = new int[lengthB];

		String line = reader.nextLine();

		line = reader.nextLine();
		String[] words = line.split(" ");
		int index = 0;
		for (String nr : words) {
			a[index] = Integer.parseInt(nr);
			index++;
		}

		index = 0;
		line = reader.nextLine();
		words = line.split(" ");
		for (String nr : words) {
			b[index] = Integer.parseInt(nr);
			index++;
		}
		
		index = 0;
//		int[] result = new int[max(lengthA,lengthB)];
		ArrayList<Integer> res = new ArrayList<Integer>();
		for(int nrA : a) {
			for(int nrB : b) {
				if(nrA == nrB)
					res.add(nrA);
			}
		}
		
		
		
		PrintWriter writer = new PrintWriter("cmlsc.out");
		writer.write(res.size() + "\n");
		for(Integer i : res) {
			writer.write(String.valueOf(i) + " ");
		}
		
		reader.close();
		writer.close();
	}
	
	public static int max(int a, int b) {
		if(a>b) return a;
		return b;
	}

}















