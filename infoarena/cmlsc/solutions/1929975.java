package dynamicProgramming;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;

class LongestCommonSubsequence {
	public char[] x;
	public char[] y;
	int n, m;
	
	public LongestCommonSubsequence() {};
	
	public LongestCommonSubsequence(String a, String b) {
		x = a.toCharArray();
		y = b.toCharArray();
	}
	
	public String solve () {
		return LCS(String.copyValueOf(x), String.copyValueOf(y));
	}
	
	public String LCS (String x, String y) {
		
		if (x.length() == 0 || y.length() == 0) 
			return "";
		if (x.charAt(x.length() - 1) == y.charAt(y.length() - 1)) 
			return LCS(x.substring(0, x.length() - 1), y.substring(0, y.length() - 1)) + x.charAt(x.length() - 1);
		
		String a = LCS(x.substring(0, x.length() - 1), y);
		String b = LCS(x, y.substring(0, y.length() - 1));
		return a.length() > b.length() ? a : b;
	}
	
	public static void main (String[] argv) {
		LongestCommonSubsequence r = new LongestCommonSubsequence();
		r.read("cmlsc.in");
		r.write("cmlsc.out");
	}
	
	public void read (String name) {
		Scanner in;
		
		try {
			in = new Scanner(new FileReader(name));
			n = in.nextInt();
			m = in.nextInt();
			
			x = new char[n];
			y = new char[m];
			
			for (int i = 0; i < n; i++) 
				x[i] = String.valueOf(in.nextInt()).charAt(0);
			
			for (int i = 0; i < m; i++) 
				y[i] = String.valueOf(in.nextInt()).charAt(0);
			
			in.close();
		}
		catch (InputMismatchException e) {
//			System.err.println(e.printStackTrace());
			e.printStackTrace(System.err);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void write (String name) {
        FileWriter out;
		String solution = solve();
		
		try {
			out = new FileWriter("cmlsc.out");

			out.write(String.valueOf(solution.length()));
			out.write('\n');
			out.write(String.valueOf(solution));
			
			out.close();
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
}
