#include <iostream.h>
#include <fstream.h>
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
#define maxim(a, b) ((a > b) ? a : b)
int m, n, a[100], b[100], d[100][100], sir[100], k;


int main()
{
int i, j;

fin>>m>>n;
for (i=1;i<=m;i++)
fin>>a[i];
for (i=1;i<=n;i++)
fin>>b[i];
 cout<<endl;
for(i=1;i<=n;i++)
for (j=1;j<=n;j++)
  if (a[i] == b[j])
   d[i][j] = 1 + d[i-1][j-1];
   
  else
  d[i][j] = maxim(d[i-1][j], d[i][j-1]);
   
  
i=m; j=n;
while(i)
if (a[i] == b[j])
{sir[++k] = a[i]; --i; --j;}
else if (d[i-1][j] < d[i][j-1])
--j;
else
--i;

fout<<k<<endl;
for (i = k; i; --i)
fout<<sir[i]<<" ";
return 0;
}