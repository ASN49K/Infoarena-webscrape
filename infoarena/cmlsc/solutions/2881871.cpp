#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long long t[20001],a[20001],b[10001];
int n,m,i,p,q,k,j;

int v[1025][1025];

int main()
{f>>n>>m;
for(i=1;i<=n;i++)
    f>>a[i];
for(j=1;j<=m;j++)
    f>>b[j];

 for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
{if (a[i] == b[j])
        v[i][j] = 1 + v[i-1][j-1];
        else
        v[i][j] = max(v[i-1][j], v[i][j-1]);}


    for (i = n, j = m; i;)
        {if (a[i] == b[j])
            t[++k] = a[i], --i, --j;
        else if (v[i-1][j] < v[i][j-1])
            --j;
        else
            --i;}
                g<<k<<'\n';

    for(i=k;i>=1;i--)
        g<<t[i]<<" ";

}
