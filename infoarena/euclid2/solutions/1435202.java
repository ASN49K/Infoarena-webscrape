import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	
	public static int euclid(int a, int b) {
		while(b != 0) {
			int r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter out = new PrintWriter(new FileOutputStream("euclid2.out"));
		int numberOf = in.nextInt();
		for (int i = 0; i < numberOf; i++){
			out.write(String.valueOf(euclid(in.nextInt(), in.nextInt())));
			out.write("\n");
		}
		
		in.close();
		out.close();
	}

}
