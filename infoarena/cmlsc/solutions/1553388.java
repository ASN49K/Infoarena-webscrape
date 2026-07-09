import java.io.*;
import java.util.*;
public class Main {

	public static void refac(int mat[][],int a[],int b[], int p, int q,PrintWriter out){
		
		if(p == -1 || q == -1)
			return;
		if(a[p] == b[q])
		{
			refac(mat,a,b,p-1,q-1,out);
			out.print(a[p]+ " ");
			return;
			
		}
		if(mat[p-1][q] > mat[p][q-1])
			refac(mat,a,b,p-1,q,out);
		else
			refac(mat,a,b,p,q-1,out);
		
	}
	
	public static void main(String[] args) {
	try{
		Scanner in = new Scanner(new File("cmlsc.in"));
		int m = in.nextInt();
		int n = in.nextInt();
		int[] a = new int[m];
		int[] b = new int[n];
		for(int i = 0; i < m; i++)
			a[i]= in.nextInt();
		for(int i = 0; i < n ;i++)
			b[i]= in.nextInt();
		int[][] mat = new int[m][n];
		for(int i = 0; i < m ; i++)
			for(int j = 0; j < n; j++)
			{
				if(i == 0 || j == 0)
				{
					if(a[i] == b[j])
						mat[i][j] =1;
					
				}
				else
				{
					if(a[i] == b[j])
						mat[i][j] = 1 + mat[i-1][j-1];
					else
						mat[i][j] = (mat[i-1][j] > mat[i][j-1])?mat[i-1][j]:mat[i][j-1];
						
				}
			}
			int p= 0,q = 0;
			for(int i = 0; i < m; i++)
			{
				
				for(int j = 0; j < n; j++)
				{
				//	System.out.print(mat[i][j] + " ");
					if(mat[i][j]>mat[p][q])
					{
						p = i;
						q = j;
					}
				}
			//	System.out.println();
			}
			PrintWriter out = new PrintWriter("cmlsc.out");
			out.println(mat[p][q]);
			refac(mat,a,b,p,q,out);
			in.close();
			out.close();
			
		
		}
		catch(FileNotFoundException e){

		}

	}
}
