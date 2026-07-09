import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static final String INPUT_FILE = "euclid2.in";
	public static final String OUTPUT_FILE = "euclid2.out";
	
	public static Scanner openFileForRead() throws FileNotFoundException {
		return new Scanner(new FileInputStream(INPUT_FILE));
	}
	
	public static PrintWriter openFileForWrite() throws FileNotFoundException {
		return new PrintWriter(new FileOutputStream(OUTPUT_FILE));
	}
	
	public static int euclid(int a, int b) {
		int r = -1;
		while(r != 0) {
			r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = openFileForRead();
		PrintWriter out = openFileForWrite();
		
		int numberOf = in.nextInt();
		for (int i = 0; i < numberOf; i++){
			int result = euclid(in.nextInt(), in.nextInt());
			out.write(String.valueOf(result) + "\n");
		}
		
		in.close();
		out.close();
	}

}
