#include <fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long a[1025],b[1025],d[1026][1026],nr,sir[1025],i,j,n,m;
int main ()
	{
f>>m>>n;


	for(i=0;i<n;i++)
		f>>a[i];
	for(i=0;i<m;i++)
		f>>b[i];


	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	      if(a[i]==b[j])
		d[i][j]=1+d[i-1][j-1];	
		else
		{
		if(d[i-1][j]>d[i][j-1])
		   d[i][j]=d[i-1][j];
		   else
		   d[i][j]=d[i][j-1];
		}

	for(i=m,j=n;i>0;)
	   if(a[i]==b[j])
	      {
		nr++;
		sir[nr]=a[i];
		i--,j--;
	      }
	      else
	      {
	      if(d[i-1][j]<d[i][j-1])
		  j--;
   		  else
		  i--;
	      }
g<<nr<<'\n';
for(i=nr;i>0;i--)
	g<<sir[i]<<' ';
g<<'\n';
f.close();
g.close();
return 0;
}

			

