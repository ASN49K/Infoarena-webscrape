#include <fstream.h>

ifstream fin("date.in");
ofstream fout("date.out");

int c[257][257],i,j,n,m,a[257],b[257];
int main ()
{
 fin>>n>>m;
 for(i=1;i<=n;i++)
   fin>>a[i];
 for(i=1;i<=m;i++)
   fin>>b[i];

 for(i=n;i>=1;i--)
   for(j=m;j>=1;j--)
      {
      if(a[i]==b[j])
	c[i][j]=1+c[i+1][j+1];
	else
	if(c[i][j+1]>c[i+1][j])
	  c[i][j]=c[i][j+1];
	  else
	  c[i][j]=c[i+1][j];
      }

 fout<<c[1][1]<<'\n';
 fin.close ();
 fout.close ();
 return 0;
}