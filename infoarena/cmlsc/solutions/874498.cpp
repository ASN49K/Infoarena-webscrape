#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int a[100][100],v1[100],v2[100],i,j,n,m,sir[100],k;
int main()
{f>>n>>m;
for(i=1;i<=n;i++)f>>v1[i];
for(j=1;j<=m;j++)f>>v2[j];

for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
 if(v1[i]==v2[j]) a[i][j]=1+a[i-1][j-1];
 else
 if (a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
 else
 a[i][j]=a[i][j-1];
 g<<a[n][m]<<' '<<'\n';
k=0;
i=n;j=m;
while (a[i][j]>0)
if(v1[i]==v2[j]) sir[++k]=v1[i],i--,j--;
else
if(a[i-1][j]>a[i][j-1])i--;
else
j--;
while(k)g<<sir[k--]<<' ';
g<<'\n';
f.close();
g.close();
    return 0;
}
