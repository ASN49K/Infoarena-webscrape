#include<fstream.h>

int main()
{
 long n,m,i,j,k;
 int a[1026],b[1026],sol[1026][1026],d[1026];

 ifstream fin("cmlsc.in");
 fin>>n>>m;

 for (i=1; i<=n; i++)
	{
	 fin>>a[i];
	 sol[0][i]=0;
	}
 for (i=1; i<=m; i++)
	{
	 fin>>b[i];
	 sol[i][0]=0;
	}

 for (i=1; i<=n; i++)
	for (j=1; j<=m; j++)
	 if (a[i]==b[j])
		sol[i][j]=sol[i-1][j-1]+1; else
		if (sol[i-1][j]>sol[i][j-1])
		 sol[i][j]=sol[i-1][j]; else
		 sol[i][j]=sol[i][j-1];

 i=n; j=m;
 k=sol[n][m];

 while (k>0)
	{
	 if (a[i]==b[j])
		{
		 d[k]=a[i];
		 k--;
		 i--;
		 j--;
		} else
		if (sol[i][j]==sol[i-1][j])
		 i--; else
		 j--;
	}

 ofstream fout("cmlsc.out");
 fout<<sol[n][m]<<'\n';
 for (i=1; i<=sol[n][m]; i++)
	fout<<d[i]<<" ";

 fin.close();
 fout.close();

 return 0;
}