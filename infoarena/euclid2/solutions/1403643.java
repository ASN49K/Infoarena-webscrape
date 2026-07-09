import java.io.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
	
		Scanner reader = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter writer = new PrintWriter("euclid2.out");
		
		int T = reader.nextInt();
		
		for (int k = 0; k < T; ++k){
			
			int a = reader.nextInt();
			int b = reader.nextInt();
			
			writer.print(gcd(a, b) + "\n");
		}
		
		reader.close();
		writer.close();
	}
	
	public static int gcd(int a, int b){
		
		int r;
		
		while (b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		
		return a;
	}
}
