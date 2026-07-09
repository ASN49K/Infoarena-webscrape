#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1025], b[1025], c[1025][1025], d[1024], i, j, k, m, n;

int main()
{
    cin>>n>>m;
    for (i=1; i<=n; ++i) cin>>a[i];
    for (i=1; i<=m; ++i) cin>>b[i];

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
                else c[i][j]=max(c[i-1][j], c[i][j-1]);


    i=n;
    j=m;
    while (c[i][j])
    {
        while (c[i-1][j]==c[i][j]) --i;
        while (c[i][j-1]==c[i][j]) --j;
        ++k;
        d[k]=a[i];
        --i;
        --j;
    }
    cout<<k<<'\n';
    for (i=k; i>0; --i) cout<<d[i]<<' ';


    return 0;
}
