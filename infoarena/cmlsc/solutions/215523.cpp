#include<fstream.h>

int d[1024][1024],i,j,m,n,l,a[1024],b[1024];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


void afiseaza(int i,int j)
{

	if(!d[i][j]) return;

	if(a[i]==b[j])
	{
		afiseaza(i-1,j-1);
		g<<a[i]<<" ";
		return;
	}
	if(d[i][j]==d[i-1][j])
	{
		afiseaza(i-1,j);
		return;
	}
	afiseaza(i,j-1);

	return;

}

int main(void)
{
	


	f>>n>>m;
	for(i=1;i<=n;i++)
	{
		f>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		f>>b[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			d[i][j]=(d[i-1][j]>d[i][j-1])?d[i-1][j]:d[i][j-1];

			if(a[i]==b[j] && d[i][j]<d[i-1][j-1]+1)
			{
				d[i][j]=d[i-1][j-1]+1;
			}

		}
	}
	l=d[n][m];
	g<<l<<"\n";
	afiseaza(n,m);
	f.close();
	g.close();
	return 0;

}

