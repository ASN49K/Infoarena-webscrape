import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static int gcd(int a, int b) {
		int result = 1;
		int max = a;
		if(b < max)
			max = b;
		for(int index = 2; index <= max; index++) {
			if((a % index == 0) && (b % index == 0)) {
				result = index;
			}
		}
		return result;
	}

	public static void main(String[] args) throws IOException {
		Scanner reader = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter writer = new PrintWriter("euclid2.out");
		int T = reader.nextInt();
		int a = 0;
		int b = 0;
		int result = 0;
		while(reader.hasNext()) {
			a = reader.nextInt();
			b = reader.nextInt();			
			writer.write(String.valueOf(gcd(a,b)) + "\n");			
		}
		reader.close();
		writer.close();

	}
}
