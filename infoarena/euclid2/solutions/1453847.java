import java.util.Scanner;
import java.io.FileInputStream;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.File;
 class Main {

	static int gcd(int a, int b) {
		int r;
		while (b!=0) {
			r=a%b;
			a=b;
			b=r;
		}
		return a;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		int t,a,b;
		Scanner in = new Scanner(new FileInputStream("euclid2.in"));
		PrintWriter out = new PrintWriter("euclid2.out"); 
	
		t = in.nextInt();
		
		

		for (int i=0; i<t; i++) {
			a=in.nextInt();
			b=in.nextInt();
			out.println(gcd(a,b));
			out.flush();
		}
		
		in.close();
		out.close();
		

	}

}
