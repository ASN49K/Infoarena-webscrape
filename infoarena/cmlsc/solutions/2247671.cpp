#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 1025;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j;
int a[maxn], b[maxn];
int d[maxn][maxn];
int rez[maxn], rezk;

int main()
{
    f >> n >> m;
    for(i = 1; i <= n; i ++)
    {
        f >> a[i];
    }
    for(i = 1; i <= m; i ++)
    {
        f >> b[i];
    }

    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
        {
            if(a[i] == b[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = max(d[i][j-1], d[i-1][j]);
            }
        }
    }
    for(i = n, j = m; i != 0; )
    {
        if(a[i] == b[j])
        {
            rez[++rezk] = a[i];
            --i; --j;
        }
        else if(d[i-1][j] < d[i][j-1]) {
            --j;
        } else {
            --i;
        }
    }

    g << rezk << '\n';
    for(i = rezk; i >= 1; i --)
        g << rez[i] << ' ';

    f.close();
    g.close();
    return 0;
}
