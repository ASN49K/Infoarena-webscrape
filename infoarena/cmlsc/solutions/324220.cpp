#include <fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[100][100],a[1024],b[1024],sir[1024];
int main ()
{
 int n,i,j,m,l;
 fin>>n>>m;
 for(i=1;i<=n;i++)
   fin>>a[i];
 for(i=1;i<=m;i++)
   fin>>b[i];

 for(i=n,l=0;i>=1;i--)
   for(j=m;j>=1;j--)
      {
      if(a[i]==b[j])
	c[i][j]=1+c[i+1][j+1],sir[l]=a[i],l++;
	else
	if(c[i][j+1]>c[i+1][j])
	  c[i][j]=c[i][j+1];
	  else
	  c[i][j]=c[i+1][j];
      }
 fout<<c[1][1]<<'\n';
 fout<<'\n';
 for(l-=1;l>=0;l--)
     fout<<sir[l]<<" ";
 fout<<'\n';
 fin.close ();
 fout.close ();
 return 0;
}