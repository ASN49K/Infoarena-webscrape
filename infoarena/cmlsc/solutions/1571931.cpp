#include <fstream>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int n,m,k,i,j,a[1025],b[1025],sir[1025];
int c[1025][1025];
int main()
{fi>>n>>m;
for (i=1;i<=n;i++) fi>>a[i];
for (i=1;i<=m;i++) fi>>b[i];

for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
   if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
              else c[i][j]=max(c[i-1][j],c[i][j-1]);

fo<<c[n][m]<<'\n';

i=n;
j=m;
while (c[i][j])
{ if (a[i] == b[j])  sir[++k] = a[i], --i, --j;
 else
  if (c[i][j] == c[i-1][j]) i--;
   else j--;

}


for(i=k;i>=1;i--) fo<<sir[i]<<" ";
    return 0;
}
