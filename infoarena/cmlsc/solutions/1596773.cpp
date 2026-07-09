#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],m,n,i,j,l,cmlsc[1025],ab[1025][1025];
int main()
{fin>>m>>n;
for (i=1;i<=m;i++) fin>>a[i];
for (i=1;i<=n;i++) fin>>b[i];
for (i=1;i<=m;i++)
for (j=1;j<=n;j++)
{if (a[i]==b[j])
ab[i][j]=1+ab[i-1][j-1];
else
    if (ab[i-1][j]>ab[i][j-1])
    ab[i][j]=ab[i-1][j];
else
    ab[i][j]=ab[i][j-1];
}
int lgab=0;
for (i=m,j=n;i&&j;)
{if (a[i]==b[j])
cmlsc[++lgab]=a[i],i--,j--;
else
if (ab[i-1][j]>ab[i][j-1])
    i--;
else
    j--;
}
fout<<lgab<<'\n';
for (i=lgab;i;i--)
    fout<<cmlsc[i]<<' ';
fout<<'\n';
}
