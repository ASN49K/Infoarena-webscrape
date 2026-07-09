package ia;
import java.lang.*;
import java.io.FileWriter;
import java.io.File;
import java.util.Scanner;
import java.io.IOException;

public class Main {
	public static int solveTest(int a, int b) {
		while(b > 0) {
			int r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	public static void main(String[] args) {
		try{
			FileWriter fo = new FileWriter("a.out");
			File f = new File("a.in");
			Scanner fi = new Scanner(f);
			
			int t = fi.nextInt();
			while(t-- > 0) {
				int a = fi.nextInt();
				int b = fi.nextInt();
				fo.write(solveTest(a, b) + "\n");
			}
			fo.close();
		}
		catch(IOException e) {}
	}
}
