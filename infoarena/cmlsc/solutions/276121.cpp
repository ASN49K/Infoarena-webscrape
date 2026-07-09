#include<fstream.h>
#define max 1024

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int a[max],b[max],c[max][max],d[max];
int n,m,k;

void citire()
{int i;
 fin>>n>>m;
 for(i=1;i<=n;i++) fin>>a[i];
 for(i=1;i<=m;i++) fin>>b[i];
 }


int main()
{int i,j;
 citire();

 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 if(a[i]==b[j])
 c[i][j]=1+c[i-1][j-1];
 else
 {if(c[i-1][j]>c[i][j-1])
  c[i][j]=c[i-1][j];
  else c[i][j]=c[i][j-1];
  }
 fout<<c[n][m];
 fout<<"\n";

 /*for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 if(a[i]==b[j]) d[++k]=a[i];*/


 i=n;j=m;
 while(i || j)
 if(a[i]==b[j])
 {d[++k]=a[i];
  i--;j--;
  }
  else
  if(c[i-1][j]<c[i][j-1]) j--;
  else i--;

 for(i=k;i>=1;i--) fout<<d[i]<<" ";

 fin.close();
 fout.close();
 return 0;
 }

