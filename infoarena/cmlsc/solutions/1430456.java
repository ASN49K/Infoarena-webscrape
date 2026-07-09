import java.io.*;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws IOException {
		int m, n;
		int[][] M;
		int[] a, b;
		int[] sol;
		
		Scanner reader = new Scanner(new FileInputStream("cmlcs.in"));
		m = reader.nextInt();
		n = reader.nextInt();
		M = new int[m+1][n+1];
		a = new int[m];
		b = new int[n];
		sol = new int[Math.min(m, n)];
		for (int i = 0; i < m; ++i)
			a[i] = reader.nextInt();
		for (int i = 0; i < n; ++i)
			b[i] = reader.nextInt();
		
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i-1] == b[j-1])
					M[i][j] = M[i-1][j-1]+1;
				else
					M[i][j] = Math.max(M[i-1][j], M[i][j-1]);
			}
		}
		
		int i = m, j = n , k = 0;
		for (; ;) {
			if (a[i-1] == b[j-1]) {
				sol[k++] = a[i-1];
				--i; --j;
			} else if (M[i-1][j] < M[i][j-1])
				--j;
			else --i;
			if (i == 0 || j == 0) break;
		}
		
		PrintWriter writer = new PrintWriter("cmlcs.out");
		writer.write(String.valueOf(M[m][n]) + "\n");
		for (i = k-1; i >= 0; --i)
			writer.write(String.valueOf(sol[i]) + " ");
		
		reader.close();
		writer.close();
		
	}
}
