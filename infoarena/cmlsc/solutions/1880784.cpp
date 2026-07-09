#include<bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in"); ofstream g("cmlsc.out");

const int nmax = 1024 + 5;
const int mmax = 256;
int n, m;
int rez[nmax][nmax];
int a[nmax], b[nmax];
bool vis[nmax];

void read()
{
    f >> n >>m;
    for(int i = 1; i <= n; i++)
    {
        f >> a[i];
        assert(a[i] <= 256);
    }
    for(int i = 1; i <= m; i++)
    {
        f >> b[i];
        assert(b[i] <= 256);
    }
}

int main()
{
    read();

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if( b[i] == a[j] ){
                rez[i][j] = rez[i-1][j-1] + 1;
                vis[b[i]] = true;
            }
            else
                rez[i][j] = max(rez[i][j-1], rez[i-1][j]);
        }
    g<<rez[m][n]<<"\n";

    for(int i = 1; i <= mmax; i++)
        if(vis[i])
            g<<i<<" ";
    return 0;
}
