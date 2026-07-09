#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],c[1025][1025],d[1025][1025],i,j,n,m;
void cmlsc(int i, int j)
{    if (i==0||j==0) return;
     if (!d[i][j])
	{cmlsc(i-1,j-1);
	 fout<<a[i]<<' ';}
     else if (d[i][j]==1)
	cmlsc(i-1,j);
     else cmlsc(i,j-1);}

int main()
	{fin>>n>>m;
	for (i=1;i<=n;i++)          // 0- sus+stanga; 1- sus; 2- stanga
		fin>>a[i];
	for (i=1;i<=m;i++)
		fin>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		  if (a[i]==b[j])
			{c[i][j]=c[i-1][j-1]+1;
			 d[i][j]=0;}
		   else if (c[i-1][j]>=c[i][j-1])
			{ c[i][j]=c[i-1][j];
			  d[i][j]=1;}
			else
			 {c[i][j]=c[i][j-1];
			  d[i][j]=2;}
	fout<<c[n][m]<<'\n';
	cmlsc(n,m);
	/*for (i=0;i<=n;i++)
	{
	for (j=0;j<=m;j++)
		fout<<c[i][j]<<' ';
		fout<<'\n';} */
fout.close();
return 0;}