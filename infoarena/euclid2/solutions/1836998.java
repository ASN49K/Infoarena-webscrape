package testpackage;

import java.util.Scanner;
import java.io.*;

public class Da {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new BufferedReader(new FileReader("euclid2.in")));
		PrintWriter out = new PrintWriter(new FileWriter("euclid2.out"));
		
		int T = in.nextInt();
		while (T-- != 0) {
			int a = in.nextInt();
			int b = in.nextInt();
			if (a<b) {
				int temp = b;
				b = a;
				a = temp;
			}
			while (a!=0 && b!=0) {
				int temp = b;
				b = a%b;
				a = temp;
			}
			out.println(a);
		}
		in.close(); out.close();
	}
}

