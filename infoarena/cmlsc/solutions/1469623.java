import java.io.*;
import java.util.*;

class Main{
	public static void write(int a) {
		String fileName2 = "cmlsc.out";

		try {
			FileWriter w = new FileWriter(fileName2);
			//Writer buffw = new BufferedWriter(w);
			//int  = v[a][b];
			w.write (String.valueOf(a));
			//w.newLine ();
			w.write ("1 1 1 1 1");

			w.close();
		}

		catch (IOException ex) {
			System.out.println ("Error writing file");
		} 
	}
	public static void main(String[] args){
		String fileName = "cmlsc.in";
		//String fileName2 = "cmlsc.out";
		int a,b;

		try {
			FileReader f = new FileReader(fileName);
			Scanner buff = new Scanner(f);
			//FileWriter w = new FileWriter(fileName2);

			a = buff.nextInt();
			b = buff.nextInt();

			int[] x = new int[a];
			int[] y = new int[b];

			for (int i=0; i < a;i++) x[i] = buff.nextInt();
			for (int i=0; i < b;i++) y[i] = buff.nextInt();
			int p = a+1, q=b+1;
			int[][] v =new int[p][q];

			for (int i=0;i<=a;i++) v[i][0] = 0;
			for (int j=0;j<=b;j++) v[0][j] = 0;
			for (int i=1;i<=a;i++)
				for (int j=1;j<=b;j++)
					if (x[i-1] == y[j-1]) {
						v[i][j] = v[i-1][j-1] + 1;
					}
					else
					{
						if (v[i-1][j]>v[i][j-1]) v[i][j] = v[i-1][j];
						else v[i][j] = v[i][j-1];
					}
			//System.out.println (v[a][b]);
			//System.out.println ("1 1 1 1 1");
		//	w.write (String.valueOf(p));
		//	w.write ("1 1 1 1 1");
			write(v[a-1][b-1]);
			buff.close();
		//	w.close();
		}

		catch (FileNotFoundException ex) {
			System.out.println ("Unable to open file");
		}

		//catch (IOException ex) {
		//	System.out.println ("Error reading file");
		//}
	}
}