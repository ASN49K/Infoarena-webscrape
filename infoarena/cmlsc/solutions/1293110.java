//package pd;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	    static void afisareRaspuns() throws FileNotFoundException
	    {   
	        for(int i=1;i<=n;i++)
	            for(int j=1;j<=m;j++)
	                if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
	                else D[i][j]=( D[i-1][j]>D[i][j-1] ) ? D[i-1][j] : D[i][j-1];
	         
	        int r=D[n][m];
	        for(int i=n,j=m;r != 0 ;)
	            if( A[i] == B[j] )
	                { R[r--]=A[i]; i--; j--; }
	                else
	                {   
	                    if( D[i-1][j] > D[i][j-1] ) i--;
	                    else j--;
	                }
	        PrintWriter g = new PrintWriter("cmlsc.out");
	        g.printf("%d\n",D[n][m]);
	        for(int i=1;i<=D[n][m];i++)
	            g.printf("%d ",R[i]);
	        g.printf("\n");
	        g.close();
	    }
	
	static int n,m;
	static int[] A,B,R;
	static int[][] D;
	public static void main(String args[]) throws FileNotFoundException{
	    Scanner scanner = new Scanner(new FileReader("cmlsc.in"));
	    n = scanner.nextInt();
	    m = scanner.nextInt();
	    A = new int[n+1];
	    B = new int[m+1];
	    D = new int[n+1][m+1];
	    R = new int[n+m+1];
	    for(int index = 1; index <= n; index++){
	    	A[index] = scanner.nextInt();
	    }
	    for(int index = 1; index <= m; index++){
	    	B[index] = scanner.nextInt();
	    }
	    afisareRaspuns();
	    scanner.close();
	}
}
