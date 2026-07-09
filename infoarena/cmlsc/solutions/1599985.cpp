#include <iostream>
#include <fstream>
#define L 1028
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[L], b[L], d[L][L];
int s[L], nr;
int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        {
            f>>a[i];
        }
    for (int i = 1; i <= m; i++)
        {
            f>>b[i];
        }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
            {
                d[i][j]=max(d[i-1][j] , d[i][j-1]);
            }
        }
    }
    for(int i=n, j=m; i;)
    {
        if(a[i]==b[j])
        {
            s[++nr]=a[i];
            --i;
            --j;
        }
        else if(d[i][j-1]<d[i-1][j])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    g<<d[n][m]<<'\n';
    for(int i=nr;i>=1;--i)
    {
        g<<s[i]<<' ';
    }
    return 0;
}
