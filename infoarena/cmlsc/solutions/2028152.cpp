#include <bits/stdc++.h>
#define nmax 1030
using namespace std;

int n, m;
int a[nmax], b[nmax], c[nmax], subsir[nmax][nmax];

void read()
{
    ifstream f("cmlsc.in");
    f >> n >> m;
    for(int i=1; i<=n; ++i)
        f >> a[i];
    for(int i=1; i<=m; ++i)
        f >> b[i];
    f.close();
}

void solve()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i] == b[j])
                subsir[i][j] = subsir[i-1][j-1] + 1;
            else
                subsir[i][j] = max(subsir[i-1][j], subsir[i][j-1]);
        }
    }

    ofstream g("cmlsc.out");
    int i=n, j=m, nr=subsir[i][j], k=0;
    g << nr << '\n';
    while(i && j)
    {
        if(a[i] == b[j])
        {
            c[++k]=a[i];
            --i;
            --j;
        }
        else
        {
            if(subsir[i-1][j] > subsir[i][j-1])
                --i;
            else
                --j;
        }
    }

    for(int i=k; i; --i)
        g << c[i] << ' ';
    g.close();
}

int main()
{
    read();
    solve();
    return 0;
}
