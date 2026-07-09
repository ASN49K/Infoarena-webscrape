import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		int n, m;
		
		Scanner s = new Scanner(new FileInputStream("cmlsc.in"));
		n = s.nextInt();
		m = s.nextInt();
		
		int a[] = new int[n+1];
		int b[] = new int[m+1];
		int d[][] = new int[n+1][m+1];
		int maxim = max(n,m);
		int sir[] = new int[maxim+1];
		int bst = 0;
		
		for (int i = 1; i <= n; i++) {
			a[i] = s.nextInt();
		}
		
		for (int i = 1; i <= m; i++) {
			b[i] = s.nextInt();
		}
		
		s.close();
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i] == b[j]) {
					d[i][j] = 1 + d[i - 1][j - 1];
				} else {
					d[i][j] = max(d[i - 1][j], d[i][j - 1]);
				}
			}
		}
		
		for (int i = n, j = m; i > 0; ) {
			if (j == 0) break;
			if (a[i] == b[j]) {
				sir[++bst] = a[i];
				--i;
				--j;
			} else if (d[i - 1][j] < d[i][j - 1]) {
				--j;
			} else --i;
		}
		
		PrintWriter w = new PrintWriter("cmlsc.out");
		w.write(bst + "\n");
		for (int i = bst; i > 0; --i) {
			w.write(sir[i] + " ");
		}
		
		w.close();

	}
	
	static int max(int a, int b) {
		return (a > b) ? a : b;
	}

}
