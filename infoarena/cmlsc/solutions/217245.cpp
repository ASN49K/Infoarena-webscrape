#include <fstream.h>
short int a[1024],b[1024],x[1024],l[1024][1024],i,j,n,m,k;


int main()
{
 ifstream fin("cmlsc.in");
 fin>>n>>m;
 for(i=1;i<=n;i++)
  fin>>a[i];
 for(i=1;i<=m;i++)
  fin>>b[i];
 fin.close();

 for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
   if(a[i]==b[j])
    l[i][j]=l[i-1][j-1]+1;
   else
    if(l[i-1][j]>l[i][j-1])
     l[i][j]=l[i-1][j];
    else
     l[i][j]=l[i][j-1];

 k=l[n][m];
 i=n; j=m;
 while(k!=0)
  if(a[i]==b[j])
  {
   x[k]=a[i];
   k--; i--; j--;
  }
  else
   if(l[i][j]==l[i][j-1])
    j--;
   else
    i--;

 ofstream fout("cmlsc.out");
 fout<<l[n][m]<<'\n';
 for(i=1;i<=l[n][m];i++)
  fout<<x[i]<<" ";

 return 0;
}



