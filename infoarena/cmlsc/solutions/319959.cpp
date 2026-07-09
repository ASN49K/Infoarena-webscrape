#include <fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[10][10],a[250],b[250],sir[250];
int main ()
{
 int n,i,j,m,l;
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

 if(n>m)
   l=n;
   else
   l=m;

 for(i=n,j=m; i;)
    {
    if(a[i]==b[j])
       sir[i]=a[i],i--,j--,l++;
       else
       if(c[i-1][j]<c[i][j-1])
	  j--;
	  else
	  i--;
   }

 fout<<c[1][1]<<'\n';
 for(i=1;i<=l;i++)
    if(sir[i])
       fout<<sir[i]<<" ";
 fout<<'\n';
 fin.close ();
 fout.close ();
 return 0;
}