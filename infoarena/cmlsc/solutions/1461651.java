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
		int aux = 0;
		ArrayList<Integer> res = new ArrayList<Integer>();
		for(int i = 0; i < lengthA; i++) {
			for(int j = aux; j < lengthB; j++) {
				if(a[i] == b[j]) {
					res.add(a[i]);
					aux = j;
					System.out.println(aux);
				}
					
			}
		}
		
		
		
		PrintWriter writer = new PrintWriter("cmlsc.out");
		writer.write(res.size() + "\n");
		for(int i=0; i<res.size();i++) {
			if(i == res.size() - 1) 
				writer.write(String.valueOf(res.get(i)));
			else 
				writer.write(String.valueOf(res.get(i)) + " ");
		}
		
		reader.close();
		writer.close();
	}
	
	public static int max(int a, int b) {
		if(a>b) return a;
		return b;
	}

}















