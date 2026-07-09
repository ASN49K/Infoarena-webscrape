import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static final String INPUT_FILE = "euclid2.in";
	public static final String OUTPUT_FILE = "euclid2.out";
	
	public static int euclid(int a, int b) {
		while(b != 0) {
			int r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileInputStream(INPUT_FILE));
		PrintWriter out = new PrintWriter(new FileOutputStream(OUTPUT_FILE));
		int numberOf;
		numberOf = in.nextInt();
		for (int i = 0; i < numberOf; i++){
			out.write(euclid(in.nextInt(), in.nextInt()) + "" + "\n");
		}
		
		in.close();
		out.close();
	}

}
