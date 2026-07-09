#include <fstream>
#define maxn 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,a[maxn],b[maxn],d[maxn][maxn],s[maxn];
int main()
{
int i=0, j=0, k=0;
fin>>m>>n;
for (i=1;i<=m;i++)
fin>>a[i];
for (i=1;i<=n;i++)
fin>>b[i];
for (i=1; i <= m; i++)
for (j=1; j <= n; j++)
if (a[i] == b[j])
d[i][j] = d[i-1][j-1] + 1;
else
if (d[i-1][j] > d[i][j-1])
d[i][j] = d[i-1][j];
else
d[i][j] = d[i][j-1];
fout<<d[m][n]<<endl;
i=m;
j=n;
while (d[i][j]!=0)
{
if (a[i]==b[j])
{
s[++k]=b[j];
i--;
j--;
}
else
if (d[i][j-1] == d[i][j])
j--;
else
i--;
}
for (i=k; i > 0; --i)
fout<<s[i]<<" ";
return 0;
}
