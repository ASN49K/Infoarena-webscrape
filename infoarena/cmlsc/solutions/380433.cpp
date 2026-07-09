#include <fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long a[1025],b[1025],m[1026][1026],nr,sir[1025],i,j,n,m;
int main ()
	{
f>>n>>m;
	for(i=0;i<n;i++)
		f>>a[i];
	for(i=0;i<m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				m[i][j]=1+m[i-1][j-1];	
			else
				{
				if(m[i-1][j]>m[i][j-1])
					m[i][j]=m[i-1][j];
					else
					m[i][j]=m[i][j-1];
				}
	for(i=n,j=m;i>0;)
		if(a[i]==b[j])
			{
			nr++;
			sir[nr]=a[i];
			i--,j--;
			}
		else
			{
			if(m[i][j-1]<m[i-1][j])
				i--;
				else
				j--;
			}
g<<nr<<'\n';
for(i=nr;i>0;i--)
	g<<sir[nr]<<' ';
g<<'\n';
f.close();
g.close();
return 0;
}

			