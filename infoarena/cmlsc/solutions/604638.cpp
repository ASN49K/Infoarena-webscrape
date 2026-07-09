#include <iostream.h>
#include <fstream.h>

fstream f("cmlsc.in");
ofstream g("cmlsc.out");

int max(short a,short b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int m,n,i,j;
	short **a=0,*x,*y,k=1;
	x=new short [n];
	y=new short [m];
	a=new short *[n];
	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>x[i];
	for(i=1;i<=m;i++)
		f>>y[i];
	
	for(i=0;i<=n;i++)
		a[i]=new short[m];
	
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			a[i][j]=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i][j-1],a[i-1][j]);
		}

	g<<a[n][m]<<"\n";
	
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			if(a[i][j]==k)
			{
				g<<y[j]<<" ";
				k++;
			}
			

	f.close();
	g.close();
	
	return 0;
}