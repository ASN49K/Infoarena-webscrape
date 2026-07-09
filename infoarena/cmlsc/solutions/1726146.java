import java.io.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("cmlsc.in")));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("cmlsc.out")));
		String[] nm = reader.readLine().split(" ");
		int m = Integer.parseInt(nm[0]);
		int n = Integer.parseInt(nm[1]);
		
		String s1 = "* " + reader.readLine();
		String s2 = "* " + reader.readLine();
		
		String[] X = s1.split(" ");
		String[] Y = s2.split(" ");
		
		int[][] c = new int[m+1][n+1];
		int[][] b = new int[m+1][n+1];
		
		
		for (int i = 1; i <= m; i++) {
			c[i][0] = 0;
		}
		for (int j = 0; j <= n; j++) {
			c[0][j] = 0;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (X[i].equals(Y[j])) {
					c[i][j] = c[i-1][j-1] + 1;
					b[i][j] = 2;
				} else {
					if (c[i-1][j] >= c[i][j-1]) {
						c[i][j] = c[i-1][j];
						b[i][j] = 1;
					} else {
						c[i][j] = c[i][j-1];
						b[i][j] = 3;
					}
				}
			}
		}
		
		writer.write(String.valueOf(c[m][n]) + "\n");
		
		int i = m;
		int j = n;
		String[] r = new String[c[m][n]];
		int cont = c[m][n];
		
		while (i > 0 && j > 0) {
			if (b[i][j] == 2) {
				r[cont-1] = X[i];
				i--;
				j--;
				cont--;
			} else if (b[i][j] == 1) {
				i--;
			} else {
				j--;
			}	
		}
		for (int k = 0; k < c[m][n]; k++) {
			writer.write(r[k] + " ");
		}
		
		reader.close();
		writer.close();		
	}
}
