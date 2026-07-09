#include<fstream.h>
int a[100],i,n,j,l[100][100],b[100],d[100],m,k;
int main()
{
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>m>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(j=1;j<=n;j++)
f>>b[j];
for(i=1;i<=m;i++)
l[0][i]=0;
for(j=1;j<=n;j++)
l[j][0]=0;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
l[i][j]=1+l[i-1][j-1];
else
if(l[i-1][j]>l[i][j-1])
l[i][j]=l[i-1][j];
else
l[i][j]=l[i][j-1];
g<<l[m][n];
g<<"\n";
i=m;
j=n;
while(l[i][j])
{
 if(a[i]==b[j])
 {
  d[k]=a[i];
  k++;
  i--;
  j--;
 }
 else
 if(l[i][j]==l[i-1][j])
 i--;
 else
 if(l[i][j]==l[i][j-1])
 j--;
}
 for(i=k-1;i>=0;i--)
 g<<d[i]<<" ";
return 0;
}