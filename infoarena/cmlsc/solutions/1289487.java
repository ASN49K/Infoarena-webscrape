import java.util.*;
import java.io.*;

public class Main {
	
	static int n,m;
	static int a[] = new int[1026];
	static int b[] = new int[1026];
	static int l[][] = new int[1026][];
	
	static void  rezolva()
	{
	    int i,j;
	    for(i=1;i<=n;i++)
	        for(j=1;j<=m;j++)
	        if(a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
	    else if(l[i-1][j]>l[i][j-1]) l[i][j]=l[i-1][j];
	    else l[i][j]=l[i][j-1];
	}
	
	static void afiseaza(int i,int j,PrintWriter g) throws Exception
	{
		if(l[i][j]!=0)
	    if(a[i]==b[j]) {afiseaza(i-1,j-1,g); g.write(a[i]+" ");}
	    else if(l[i-1][j]==l[i][j]) afiseaza(i-1,j,g);
	    else if(l[i][j]==l[i][j-1]) afiseaza(i,j-1,g);
	 
	}
	
	public static void main(String z[]) throws Exception
	{
		int i=0;
		Scanner sc = new Scanner(new FileInputStream("cmlsc.in"));
		PrintWriter g = new PrintWriter("clmcs.out");
		n=sc.nextInt(); m=sc.nextInt();
		for(i=1;i<=n;i++)
			a[i]=sc.nextInt();
		for(i=1;i<=m;i++)
			b[i]=sc.nextInt();
		for(i=0; i<1026; i++)
			l[i] = new int[1025];
		rezolva();
		g.write(l[n][m] + "\n");
		afiseaza(n,m,g);
		sc.close();
		g.close();
	}
	
}
