#include<fstream.h>
#define max(a,b) ((a > b) ? (a) : (b))
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1000],b[1000],d[1000][1000],n,m,sir[1000],k=0;
int main()
{
	int i,j;
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>a[i];
	for(i=1;i<=n;i++)
		f>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[i])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
	for(i=m,j=n;i;)
		if(a[i]==b[j])
		{
			k++;
			sir[k]=a[i];
			i--;
			j--;
		}
		else
			if(d[i-1][j]<d[i][j-1])
				j--;
			else
				i--;
	g<<k<<"\n";
	for(i=k;i>=1;i--)
		g<<sir[i]<<" ";
	return 0;
}
	