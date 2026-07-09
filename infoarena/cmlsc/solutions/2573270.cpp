#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m;
int a[1025], b[1025];
int c[1025][1025];

void Read()
{
    f>>n>>m;
    for(int i = 1;i <= n;++i)
        f>>a[i];
    for(int j = 1;j <= m;++j)
        f>>b[j];
}

void recon(int i, int j)
{
    if(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            recon(i - 1,j - 1);
            g<<a[i]<<" ";
        }
        else
            {
                if(c[i - 1][j] > c[i][j - 1])
                    recon(i - 1, j);
                else
                    recon(i, j - 1);
            }

    }
}

void Solve()
{
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            if(a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    g<<c[n][m]<<'\n';
    recon(n, m);
}
int main()
{
    Read();
    Solve();
    return 0;
}
